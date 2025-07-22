
#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

//class representing the data for a customer arriving into a queue
class Data
{
public: // Member functions
	//constructor, if no arguments are given all fields instantiated to 0
	Data(int customerNumber = 0, int serviceTime = 0, int totalTime = 0);

	//destructor
	~Data();

	//overloaded << operator allows the fields in a data object to be easily printed
	//takes the left hand side (output) and assigns it a format to print in
	friend ostream& operator<<(ostream& outputS, Data data); //using 'friend' to not have to use setters/getters

	//setters for customer number, service time, and total time
	void setCustomerNumber(int custNum);
	void setServiceTime(int servTime);
	void setTotalTime(int totTime);

	//getters to retrieve customer number, service time, and total time
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in minutes
												
	int totalTime;	 // totalTime = serviceTime + sum of serviceTimes of customers in line
					// before this customer; units in minutes
}; // This memory needs to be allocated on the heap! (use malloc)