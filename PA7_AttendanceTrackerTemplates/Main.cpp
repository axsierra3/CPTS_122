//PA 7
//Name: Ara Sierra
//Description: Main is used to call the function to run the application, contained in the 
// attedance tracker class.
//This program can read a file of students registered for a course, and store their information
// the program can then have the user mark if each individual student in the list is absent
// or present that day.
// The data can be used in a variety of ways, including writing two different types of
// attendance reports, and writing or reading from a master file.

#include "AttendanceTracker.hpp"


int main() {
	AttendanceTracker a;
	a.runProgram();

	return 0;
}