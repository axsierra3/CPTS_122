#pragma once

#include <iostream>
#include <string>
#include "QueueNode.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//class representing a line of customers
class Queue
{
public:
	//constructor sets head and tail pointers to null
	Queue() { mpHead = mpTail = nullptr; }

	//destructor empties the queue and deallocates the memory used for the line
	~Queue();

	//takes data, and inserts it at the end/tail of the line, sets next pointers
	//accordingly and returns a boolean value for success
	bool enqueue(const Data& newData); 

	//removes the data at the start/head of the line,
	// adjusts pointers accordingly
	//precond: q must not be empty
	Data dequeue(); 

	//checks if rhe list is empty by determining if the head and tail pointers are the same,
	//and point to null, returns a bollean value
	bool isEmpty() const;

	//called in other files, this function calls the other private overloaded print function
	//and passes in the head of the list
	void printQueueRecursively(); 

	//returns the data contained in the head node
	Data getHeadData() const;

	//returns the data contained in the tail node
	Data getTailData() const;

	//interface of the application
	//creates two queues and utilizes the other functions in the queue class (enqueue dequeue) to simulate
	//how grocery store lines work in regard to time
	//uses random number generation to generate service and arrival times and presents dynamically changing 
	// queues simultaneously
	static void runApp(int n);

private: 
	//traverses the linked list starting at the head, using next pointers and the overloaded <<
	//operator to print the information stored in each node in the queue to the screen
	void printQueueRecursively(QueueNode* pHead); 

	//two pointers to keep track of front and back of line
	QueueNode* mpHead,
		* mpTail;

};

