#pragma once
#include<vector>
#include<algorithm>
#include<iostream>


#define _SAMPLE_RESERVE_ 20
#define __DECREASE_SIZE_WARNING__


class Stat_Interface
{
protected:
	double stack_sum; //-> Manually updated everytime
	int stack_size; //-> Manually updated everytime
	
	double fmean; //-> returns the last calculated mean
	double variance; //-> does not check for update
	double pop_variance;
	double std_dev;
	double pop_std_dev;
	double median;

	bool updated;
	
	std::string name;

public:

	inline virtual void Update() = 0;

	inline virtual double Median() = 0;

	//New - Old
	inline virtual double change() = 0;
	

	//In relation to the mean
	inline double rel_change()
	{
		return (change()/mean());
	}

	//In relation to the mean
	inline double per_change()
	{
		return (change()/mean()*100);
	}


//Trivial Accessors

	inline double Mean()
	{
		this->fmean = stack_sum/stack_size;
		return fmean;
	}

	inline double fmean() const
	{
		return fmean;
	}


	inline double Variance();
	{
		
		if(!updated)
		{
			Update();
		}

		return variance;
	}


	inline double PopVariance()
	{
		
		if(!updated)
		{
			Update();
		}
		
		return pop_variance;
	}

	inline double Std_dev()
	{
		
		if(!updated)
		{
			Update();
		}

		return std_dev;
	}

	inline double Pop_std_dev()
	{
		
		if(!updated)
		{
			Update();
		}
		
		return pop_std_dev;
	}

}; //End of class Stat_Interface
//--------------------------------------------------------------------------


template<class T> class Sample : Stat_Interface
{
	
protected:

	//first ==> Sweep //second ==> Quantity
	std::vector<T> list;

public:
	
	Sample(std::string name=""): name(name), stack_sum(0.0), stack_size(0), fmean(0.0), variance(0.0) ,pop_variance(0.0) ,std_dev(0.0) ,pop_std_dev(0.0) ,median(0.0), updated(false)
		{
			list.reserve(_SAMPLE_RESERVE_);
		}

	Sample(const T arr[], int size, std::string name=""): name(name), stack_sum(0.0), stack_size(0), fmean(0.0), variance(0.0) ,pop_variance(0.0) ,std_dev(0.0) ,pop_std_dev(0.0) ,median(0.0), updated(false)
		{
			list.reserve(size);
			list.insert(list.begin(), arr, myarray+size);
			stack_size+= size;
		}


	Sample(const std::vector<T> &source, std::string name=""): name(name), stack_sum(0.0), stack_size(0), fmean(0.0), variance(0.0) ,pop_variance(0.0) ,std_dev(0.0) ,pop_std_dev(0.0) ,median(0.0), updated(false)
		{
			list.reserve(source.size());
			list.insert(list.begin(), source.begin(), source.end());
			stack_size+= size;
		}




	inline void Push(T quant)
	{
		this->list.emplace_back(quant);
		this->stack_sum += quant;
		this->stack_size++;
		this->last_update = stack_size;
		this->updated = false;
		//variance and std_dev not updated 
	}


	//The op is performed in type of init which can induce unwanted cast of the elements, e.g. std::accumulate(v.begin(), v.end(), 0) gives wrong result when v is std::vector<double>. (cppreference)

	inline void Push(const T arr[], int size)
	{
		this->list.reserve(list.size()+size);
		this->list.insert(list.end(), arr, arr+size);
		T zero = 0.0;
		T temp = std::accumulate(arr, arr+size, zero);
		this->stack_sum += temp;
		this->stack_size+= size;
		this->last_update = stack_size;
		this->updated = false;
		//variance and std_dev not updated 
	}


	inline void Push(const std::vector<T> &source)
	{
		this->list.reserve((list.size()+source.size()));
		this->list.insert(list.end(), source.begin(), source.end());
		T zero = 0.0;
		T temp = std::accumulate(arr, arr+size, zero);
		this->stack_sum += temp;
		this->stack_size+= source.size();
		this->last_update = stack_size;
		this->updated = false;
		//variance and std_dev not updated 
	}	




	inline void Update() override
	{
		double m = Mean();
		this->mean = m;
		double tmp_stack = 0;

		for(unsigned int i = 0; i < stack_size; i++)
		{
			double term = list.at(i) - m;
			tmp_stack += term * term;
		}

		this->variance = tmp_stack/(stack_size-1);
		this->pop_variance = tmp_stack/stack_size;

		this->std_dev = sqrt(variance);
		this->updated = true;
	}


	inline double Median() override //Very Heavy
	{
  		std::vector <T> v;
  		v = list; //Copy	

  		if(v.empty()) 
  		{
   			return 0.0;
  		}
	  	auto n = v.size() / 2;
	  	std::nth_element(v.begin(), v.begin()+n, v.end());
	  	auto med = v[n];
	  	if(!(v.size() & 1)) 
	  	{ //If the set size is even
		    auto max_it = max_element(v.begin(), v.begin()+n);
		    med = (*max_it + med) / 2.0;
		    this->median = med;
		}
  		return med;    
	}

}; //End of class Sample
//--------------------------------------------------------------------------


//For Array -> <datatype, datatype>
//For Vector -><datatype, std::vector<datatype>>
//template <class type> class class-name
template<class T> class Sample_NC : Stat_Interface
{
	
protected:

	//first ==> Sweep //second ==> Quantity
	T *arrptr[];
	std::vector<T> &list;
	bool is_array;

public:

	//Constructor -> Binds the ptr to the array or the vector -> defines is_array
	//size
	Sample_NC (const T arr[], int size, std::string name=""): name(name), stack_sum(0.0), stack_size(0), fmean(0.0), variance(0.0) ,pop_variance(0.0) ,std_dev(0.0) ,pop_std_dev(0.0) ,median(0.0), updated(false), is_array(true), stack_size(size)
		{
			arrptr = arr;
			list = void;
			T zero = 0.0;
			stack_sum += std::accumulate(ptr, ptr+stack_size, zero);
		}


		Sample_NC (const std::vector<T> &source, std::string name=""): name(name), stack_sum(0.0), stack_size(0), fmean(0.0), variance(0.0) ,pop_variance(0.0) ,std_dev(0.0) ,pop_std_dev(0.0) ,median(0.0), updated(false), is_array(false)
		{
			list = &source;
			arrptr = void;
			stack_size = list.size();
			T zero = 0.0;
			stack_sum += std::accumulate(list.begin(), list.end(), zero);
		}

		~Sample_NC()
		{
			delete arrptr[];
			delete &list;
		}

		inline void Update() override
		{
			double m = Mean();
			this->mean = m;
			double tmp_stack = 0;

			if(!is_array)
			{
				for(unsigned int i = 0; i < stack_size; i++)
				{
					double term = list.at(i) - m;
					tmp_stack += term * term;
				}
			}

			else
			{
				for(unsigned int i = 0; i < stack_size; i++)
				{
					double term = arrptr[i] - m;
					tmp_stack += term * term;
				}
			}

			this->variance = tmp_stack/(stack_size-1);
			this->pop_variance = tmp_stack/stack_size;

			this->std_dev = sqrt(variance);
			this->updated = true;
		}


		inline void Newsize(int size)
		{
			int temp = stack_size;
			if(size>temp)
			{
				if(is_array)
				{
					stack_size = size;
					T zero = 0.0;
					stack_sum += std::accumulate(arr[temp], arr[stack_size], zero);
				}

				else
				{
					stack_size = list.size();
					stack_sum += std::accumulate(list.at(temp), list.end(), zero);
				}
			}

			#ifdef __DECREASE_SIZE_WARNING__
			if(size < temp)
			{
				std::cerr << "Sample_NC: " << name << " New Size passed is less than current size. Deletion not allowed." << std::endl;
			}
			#endif
		}

		inline double Median() override //Very Heavy
		{
	  		std::vector <T> v;
	  		if(!is_array)
	  			v = list; //Copy	
	  		else
	  			v.insert(v.begin(), arrptr, arrptr+stack_size);
	  		
	  		if(v.empty()) 
	  		{
	   			return 0.0;
	  		}

		  	auto n = v.size() / 2;
		  	std::nth_element(v.begin(), v.begin()+n, v.end());
		  	auto med = v[n];
		  	if(!(v.size() & 1))
		  	{ //If the set size is even
			    auto max_it = max_element(v.begin(), v.begin()+n);
			    med = (*max_it + med) / 2.0;
			    this->median = med;
			}
	  		return med;  
		}


		//New - Old
		inline double change() override
		{ 
			if(!is_array)
				return (list.at(stack_size-1) - list.at(stack_size-2));
			else
				return (arrptr[stack_size-1] - arrptr[stack_size-2]);
		}

}; //End of class Sample_NC

typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_hr ;
template<class T, class S> class Sample_Stamped : Sample
//--------------------------------------------------------------------------


//-----------------------END OF TRANSLATION UNIT---------------------

#ifdef __DECREASE_SIZE_WARNING__
	#undef __DECREASE_SIZE_WARNING__
#endif
