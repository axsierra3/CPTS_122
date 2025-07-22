
#pragma once

#include <iostream> // input output operations; cout cin
#include <fstream>
#include <string>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;

//class to wrap the fitness application and work with the diet plan class and exercise plan class
class FitnessAppWrapper
{
public:
	//function is called in main and acts as the interface for the rest of the program
	//user interacts with menu through this function and it calls the other functions in the class and uses a switch statement to do so
	void runApp(void); 

	//prints the 9 menu options on the screen
	void displayMenu(); 

private:
	//functions to read in one single plan from file to a plan object, uses overloaded >>
	void loadDailyPlan(ifstream& fileStream, DietPlan& plan); 
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);

	//uses the loadDailyPlan functions and a loop to read in all of the plans for the entire week from the files
	void loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[6]); 
	void loadWeeklyPlan(ifstream& fileStream, ExercisePlan weeklyPlan[6]);

	//prints a single plan to the screen using the overloaded <<
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	//uses the displayDailyPlan functions and a loop to print all of the plans for the week from the array onto the screen
	void displayWeeklyPlan(DietPlan weeklyPlan[]); 
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	//takes a output file stream and a single plan to store a single plan into the file using the overloaded <<
	void storeDailyPlan(std::ofstream& fileStream, DietPlan& plan);
	void storeDailyPlan(std::ofstream& fileStream, ExercisePlan& plan);

	//takes a output file stream and an array of the plans for a week to store them into a file using a loop and the overloaded <<
	void storeWeeklyPlan(std::ofstream& fileStream, DietPlan weeklyPlan[]); 
	void storeWeeklyPlan(std::ofstream& fileStream, ExercisePlan weeklyPlan[]);


};