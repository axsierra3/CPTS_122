//List: dynamic singly linked list of generic nodes (used to store a list of students in this program)

#include "Node.hpp"

#pragma once

template <class T>
class List
{
public:
	//constructor
	List() : mpHead(nullptr) {};

	//takes a generic data type, creates a new node, and inserts it 
	//to the front of the list by adjusting the head pointer and the next 
	//pointer accordingly
	void insertAtFront(T& newDataEntry);

	//getter
	Node<T>* getHeadPtr();

	//destructor that calls deleteList to free the space taken up by the list
	~List();

	//traverses the list recursively by taking the head pointer, and 
	//deletes nodes until the list is empty
	void deleteList(Node<T>* pList);

private:
	//fields
	Node<T>* mpHead;
};

template<class T>
void List<T>::insertAtFront(T& newDataEntry)
{
	Node<Data>* newNode = new Node<Data>(newDataEntry);

	if (mpHead == nullptr)
	{
		mpHead = newNode;
	}

	else
	{
		newNode->setNextPtr(mpHead);
		mpHead = newNode;
	}

}

template<class T>
void List<T>::deleteList(Node<T>* pList)
{
	if (pList != nullptr)
	{
		deleteList(pList->getNextPtr()); //call recursively until a call for each node in list made

		delete pList; //curr node
	}

}

template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return mpHead;
}

template<class T>
List<T>::~List()
{
	deleteList(this->mpHead);
}
