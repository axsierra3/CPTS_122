#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

//template class representing a node for a BST with two types of data
template <class T, class U>
class BSTNode
{
public:
	//constructor (used with char and string in program)
	BSTNode(const T& newData1, const U& newData2) : data1(newData1), data2(newData2), mpLeft(nullptr), mpRight(nullptr) {};

	//getter that returns first data member
	T getData() const;

	//getter that returns second data member
	U getMorse() const;

	//returns pointer to the node to the left in the tree
	BSTNode<T, U>* getLeftPtr() const;
	//returns pointer to the node to the right in the tree
	BSTNode<T, U>* getRightPtr() const;

	//setter that accepts another BST node, and sets it as the left pointer
	void setLeftPtr(BSTNode<T, U>* newLeftPtr);
	//setter that accepts another BST node, and sets it as the right pointer
	void setRightPtr(BSTNode<T, U>* newRightPtr);

private:
	T data1; //data value 1
	U data2; //data value 2
	BSTNode<T, U>* mpLeft,   //pointers for left and right nodes on tree
		* mpRight;
};

template<class T, class U>
inline T BSTNode<T, U>::getData() const
{
	return this->data1;   //for returtning the char
}

template<class T, class U>
inline U BSTNode<T, U>::getMorse() const
{
	return this->data2;
}

template<class T, class U>
inline BSTNode<T, U>* BSTNode<T, U>::getLeftPtr() const
{
	return this->mpLeft;
}

template<class T, class U>
inline BSTNode<T, U>* BSTNode<T, U>::getRightPtr() const
{
	return this->mpRight;
}

template<class T, class U>
inline void BSTNode<T, U>::setLeftPtr(BSTNode<T, U>* newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

template<class T, class U>
inline void BSTNode<T, U>::setRightPtr(BSTNode<T, U>* newRightPtr)
{
	this->mpRight = newRightPtr;
}
