//Under Construction...

WriteState()
{
	//int iterations = 1;
	state["iterations"] = iterations;

	//int total_measurements = 10000;
	state["total_measurements"] = total_measurements;
	
	//float frac_minority = 0.5;
	state["frac_minority"] = frac_minority;

	//int total_pop = 1000;
	state["total_pop"] = total_pop;

	//bool ShuffleConMatrix = false;
	state["ShuffleConMatrix"] = ShuffleConMatrix;

	//---> Sampling Mode
	//bool twice_swap = false;
	state["twice_swap"] = twice_swap;
	
	//double swap_param_l = 0.5; //0.0-0.5
	state["swap_param_l"] = swap_param_l;
	
	//double swap_param_u = 1.0; //0.0-0.5
	state["swap_param_u"] = swap_param_u;
	//---> Sampling Mode

	//---> Con_Matrix Declarations
	//int con_matrix_size = 25;
	state["con_matrix_size"] = con_matrix_size;
	
	//Declare the type of Distribution

	

	//bool printinfo = false;
	state["printinfo"] = printinfo;



	//Declaration of Macro States - Exit on Mismatch
	#ifdef __VARVFRACVAR__
		state["macro_VARVFRACVAR"] = __VARVFRACVAR__ ;
	#endif

	#ifdef __L_F_IT__
		state["macro_L_F_IT"] = __L_F_IT__;
	#endif

	#ifdef __M_EPSILON__
		state["macro_M_EPSILON"] = __M_EPSILON__ ;
	#endif

	#ifdef __MIN_CON_FILL__
		state["macro_MIN_CON_FILL"] = __MIN_CON_FILL__ ;
	#endif
	//Declaration of Macro States - Exit on Mismatch


	//Declaration of Macro States - Generate Warning on Mismatch
	#ifdef __DSep__
		state["macro_DSep"] = __DSep__ ;
	#endif

	//Data Precision on output Streams
	#ifdef __Out_Prec__
		state["macro_Out_Prec"] = __Out_Prec__ ;
	#endif

	//Data Fill for Column Formatting
	#ifdef __DFill__
		state["macro_DFill"] = __DFill__ ;
	#endif
	//Declaration of Macro States - Generate Warning on Mismatch


	//Generate Config File
}



ReadState()
{
	//int iterations = 1;
	if(state["iterations"])
		iterations = state["iterations"].as<int>();

	if(state["total_measurements"])
		total_measurements = state["total_measurements"].as<int>();
	
	if(state["frac_minority"])
		frac_minority = state["frac_minority"].as<float>();

	if(state["total_pop"])
	 	total_pop = state["total_pop"].as<int>();

	if(state["ShuffleConMatrix"])
		ShuffleConMatrix = state["ShuffleConMatrix"].as<bool>();

	//---> Sampling Mode
	//bool twice_swap = false;
	if(state["twice_swap"])
		twice_swap = state["twice_swap"].as<bool>();
	
	//double swap_param_l = 0.5; //0.0-0.5
	if(state["swap_param_l"])
		 swap_param_l = state["swap_param_l"].as<double>();
	
	//double swap_param_u = 1.0; //0.0-0.5
	if(state["swap_param_u"])
		swap_param_u = state["swap_param_u"].as<double>();
	//---> Sampling Mode

	//---> Con_Matrix Declarations
	//int con_matrix_size = 25;
	if(state["con_matrix_size"])
		con_matrix_size = state["con_matrix_size"].as<int>();
	
	//Declare the type of Distribution

	

	//bool printinfo = false;
	if(state["printinfo"])
		printinfo = state["printinfo"].as<bool>();



	//Declaration of Macro States - Exit on Mismatch
	#ifdef __VARVFRACVAR__
		if(["macro_VARVFRACVAR"])
			if(state["macro_VARVFRACVAR"] != __VARVFRACVAR__)
				WarningE(state["macro_VARVFRACVAR"].as<int>(), __VARVFRACVAR__);
	#endif

	#ifdef __L_F_IT__
		if(state["macro_L_F_IT"])
			if(state["macro_L_F_IT"] != __L_F_IT__)
				WarningE(state["macro_L_F_IT"].as<int>(), __L_F_IT__);
	#endif

	#ifdef __M_EPSILON__
		if(state["macro_M_EPSILON"])
			if(state["macro_M_EPSILON"] != __M_EPSILON__)
				WarningE(state["macro_M_EPSILON"].as<int>(), __M_EPSILON__);
	#endif

	#ifdef __MIN_CON_FILL__
		if(state["macro_MIN_CON_FILL"])
			if(state["macro_MIN_CON_FILL"] != __MIN_CON_FILL__)
				WarningE(state["macro_MIN_CON_FILL"].as<int>(), __MIN_CON_FILL__);
	#endif
	//Declaration of Macro States - Exit on Mismatch


	//Declaration of Macro States - Generate Warning on Mismatch
	#ifdef __DSep__
		if(state["macro_DSep"])
			if(state["macro_DSep"] != __DSep__)
				WarningL(state["macro_DSep"].as<char>(), char(__MIN_CON_FILL__) );
	#endif

	//Data Precision on output Streams
	#ifdef __Out_Prec__
		if(state["macro_Out_Prec"])
			if(state["macro_Out_Prec"] != __Out_Prec__)
				WarningL(state["macro_Out_Prec"].as<int>(), __Out_Prec__);
	#endif

	//Data Fill for Column Formatting
	#ifdef __DFill__
		if(state["macro_DFill"])
			if(state["macro_DFill"] != __DFill__)
				WarningL(state["macro_DFill"].as<int>(), __DFill__);
	#endif
	//Declaration of Macro States - Generate Warning on Mismatch


	//Generate Config File
}

<typename A>
void WarningE(A state, A this_state)
{
	std::cerr << FORERED << "Read State: Incompatible Macro - Read: " << state << " & Compiled: " << this_state << RESETTEXT << std::endl;
	exit(EXIT_FAILURE);
}

<typename A>
void WarningL(A state, A this_state)
{
	std::cerr << FORECYN << "Read State: Incompatible Macro - Read: " << state << " & Compiled: " << this_state << RESETTEXT << std::endl;

}