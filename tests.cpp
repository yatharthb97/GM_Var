/*Effciency gap. In the last decade, law professor Nicholas Stephanopou-
los and political scientist Eric McGhee introduced and popularized a new
metric for unfairness, called the effciency gap.


Suppose the candidates in a two-party election receive A and B votes, respectively, with A >= B. 

Then the number of wasted votes for the losing candidate is B, and the number of wasted votes for the winning candidate is A - (1/2)(A + B).

This captures the notion that a vote is wasted just insofar as it fails to
contribute to a candidate's victory. A districting drawn to favor one party
does so by causing the other party to waste votes. That motivates the
definition of effciency gap.

Definition 2.4. Suppose the total number of wasted votes for the two
parties in an election is w1 and w2 respectively, and the total number of
votes cast in the election is N. Then the efficiency gap is (1/N)(w1 - w2).



N -> total_population


*/

if(minority_lost)
{
	wasted_min += m_pop;
}

else
{
	wasted_min += majority;
}


Efficiency_Gap = (wasted_majority-wasted_min)/total_population ;

