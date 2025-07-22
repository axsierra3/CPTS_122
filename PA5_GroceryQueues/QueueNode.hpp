#pragma once

#include <iostream>
#include <string>
#include "data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//class representing an individual node in a line
class QueueNode
{
public: // Member functions
	//constructor takes an object of type data and dynamically allocates 
	//it on the heap using malloc() 
	QueueNode(Data newData);

	//frees the memory allocated for the data in the node
	~QueueNode();

	//returns the data object, const because it is not modifed
	Data getData() const; 
	
	//returns the pointer to the next node in sequence
	QueueNode* getNextPtr() const;

	//modfies the next pointer for this node, other classes can use this function to access the private member
	void setNextPtr(QueueNode* newNextPtr); 


private:
	//pointer to the node's data
	Data* pData; // The memory for Data will need to be allocated on the heap as well!
	QueueNode* pNext; //next ptr
};