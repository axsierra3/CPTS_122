#pragma once

#include <iostream> // input output operations; cout cin
#include <fstream>
#include <string>

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;

//class representing a daily diet plan
class DietPlan
{
public:
	//public member functions

	//constructor w/ default arguments to instantiate a diet plan
	DietPlan(int goalCalories = 0, string planName = "default", string intendedDate = "00/00/0000"); 

	//copy constructor, called when passed by value or when making a new object from existing one
	DietPlan(DietPlan& d);

	//overloading the equals operator to use the copy constructor
	DietPlan& operator=(DietPlan& rhs);

	//destructor, called implicitly when when obj out of scope or when on heap and explicitly deleted
	~DietPlan(); 

	//getters to retrieve class values
	int getGoalCalories();
	string getPlanName();
	string getIntendedDate();

	//setters to update/set class values
	void setGoalCalories(int newGoalCal);
	void setPlanName(string newPlanName);
	void setIntendedDate(string newDate);

	//function prompts user for a new goal, then updates the plan accordingly through setters and prints to the screen
	void editGoal();

private: 
	//private member data for goal calories, plan name and date
	int mGoalCalories;
	string mPlanName;
	string mIntendedDate;
};

//overleaded non-member operators 
//stream insertion operator for printing: ostream refers to an output file stream
//inserts the printing data into the stream
std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs);  

//stream insertion for writing to file, same logic as above
std::ostream& operator<< (std::ofstream& lhs, DietPlan& rhs); 

//to read in a plan from a file and store the values into the correct member fields
ifstream& operator>> (ifstream& lhs, DietPlan& rhs);   



