#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include "Queue.hpp"
#include "QueueNode.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class testQueue
{
public:
	//tests queue's enqueue function on an empty queue
	void testEmptyEnqueue(void); 

	//tests queue's enqueue function on a queue with one node
	void testOneEnqueue(void); 

	//tests queue's dequeue function on a queue with one node
	void testOneDequeue(void); 

	//tests queue's dequeue function on a queue with two nodes
	void testTwoDequeue(void); 

	//inputs the minute number to be 24 hours and tests the application
	void run24HrSim(void);
};

