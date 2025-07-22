//PA 4
//Name: Arantxa Sierra
//Description: Main creates a FitnessAppWrapper and calls the function to run the application. 
// The application runs by presenting a menu to the user with 9 options. It creates 2 arrays of
// daily diet plans and daily exercise plans for an entire week. It does so by giving the user the option
// to read both lists in from a file. The user can then chose to edit the plans, or print the plans,
// or update the plans as many times as they want to until they chose to exit. When exiting, by default,
// the most recent version of the files are uploaded.

#include "FitnessAppWrapper.hpp"
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

int main(void)
{
	FitnessAppWrapper app;
	app.runApp();

	return 0;
}


