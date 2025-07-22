//Attendance Tracker: Wrapper class containing the functions nessecary to run the program
// using the list class

#include "List.hpp"
#include <fstream>
#include <iostream>
#include <string>

#pragma once

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

class AttendanceTracker
{
public:
	//displays a menu interface to the console containing the options a user can 
	//select to interact with the program, including importing the course list
	// loading the master list, storing the master list, marking absences,
	//and generating reports
	//loops until a user selects exit, opens and closes the files for the program
	void runProgram(); 

private: 
	//list representing all the students
	List<Data> masterList;

	//function takes in a file containing student information
	// and parses it line by line to extract the data and store 
	// it in the list
	void importCourseList(ifstream& inputFile); 

	//traverses the list of students recursively and asks the 
	// user if the student was absent or not that day,
	//stores choice in the stack for that student, and determines
	//the current date
	void markAbsences(Node<Data>* headPtr);

	//writes absence report containing all of the students and their 
	//number of absences
	void generateReport1(ofstream& reportv1);
	//writes absence report containing only the students above a certain 
	//amount of absences (passed as num)
	void generateReport2(ofstream& reportv2, int num);

	//takes in a master file (including absences and dates) and stores
	//it into the master file
	void loadMasterList(fstream& masterFile);

	//writes the contents of the master list (including absences and dates)
	// into the master file
	void storeMasterList(fstream& masterFile);
};