//Node: template class to create a dynamic singly linked list (used for data in this program)
#include "Data.hpp"

#pragma once

template <class T>
class Node
{
public:
	//constructor
	Node(const T& newData) : mData(newData), mpNext(nullptr) {};

	//getters
	T& getData();
	Node<T>* getNextPtr() const;

	//setters
	void setNextPtr(Node<T>* newNextPtr);

private:
	//fields
	T mData;
	Node<T>* mpNext;
};

template<class T>
inline T& Node<T>::getData() 
{
	return this->mData;
}

template<class T>
Node<T>* Node<T>::getNextPtr() const
{
	return this->mpNext;
}

template<class T>
inline void Node<T>::setNextPtr(Node<T>* newNextPtr)
{
	this->mpNext = newNextPtr;
}
