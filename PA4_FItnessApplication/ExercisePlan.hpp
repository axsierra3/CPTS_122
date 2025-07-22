#pragma once

#include <iostream> // input output operations; cout cin
#include <fstream>
#include <string>

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;

class ExercisePlan
{
public:
	//public member functions

	//constructor w/ default arguments to instantiate a exercise plan
	ExercisePlan(int goalSteps = 0, string planName = "default", string intendedDate = "00/00/0000"); 

	//copy constructor, called when passed by value or when making a new object from existing one
	ExercisePlan(ExercisePlan& d); 

	//overloading the equals operator to use the copy constructor
	ExercisePlan& operator=(ExercisePlan& rhs);

	//destructor, called implicitly when when obj out of scope or when on heap and explicitly deleted
	~ExercisePlan();

	//getters to retrieve values
	int getGoalSteps();
	string getPlanName();
	string getIntendedDate();

	//setters to set values
	void setGoalSteps(int newGoalSteps);
	void setPlanName(string newPlanName);
	void setIntendedDate(string newDate);

	//function prompts user for a new goal, then updates the plan accordingly through setters and prints to the screen
	void editGoal();

private:
	//private member data for goal steps, plan name and date
	int mGoalSteps;
	string mPlanName;
	string mIntendedDate;
};

//overleaded non-member operators 
//stream insertion operator for printing: ostream refers to an output file stream
//inserts the printing data into the stream
std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs);  

//stream insertion for writing to file, same logic as above
std::ostream& operator<< (std::ofstream& lhs, ExercisePlan& rhs); 

//to read in a plan from a file and store the values into the correct member fields
ifstream& operator>> (ifstream& lhs, ExercisePlan& rhs);    //to read in a plan from a file