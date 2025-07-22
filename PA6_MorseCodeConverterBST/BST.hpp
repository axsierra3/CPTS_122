#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

//template class representing a binary search tree containing two data types in its nodes
template <class T, class U>
class BST
{
public:
	//constructor for tree that reads in values from a text file
	//to build a morse code tree using its own insert function to
	//insert nodes
	BST(); 

	//calls overloaded private insert function and passes in the new data 
	//and the root of the tree
	void insert(const T& newData, const U& newData2);

	//calls overloaded private search function and passes in the item to
	//be found and the root of the tree
	U search(const T itemLookedFor) const;

	//calls overloaded private print function and passes in the 
	//root of the tree
	void print() const;

	//destructor deallocates memory by calling destroyTree() function
	~BST();

private:
	//uses new data to create a new BSTNode and traverses the tree to figure
	//out the appropriate place to insert (based on U value)
	// and adjusts the pointers accordingly
	void insert(const T& newData, const U& newData2, BSTNode<T, U>* pTree);

	//accepts an object of the first class used and traverses the tree
	//recursively until the object is found, and the other data (morse code)
	//is returned
	U search(const T itemLookedFor, BSTNode<T, U>* pTree) const;

	//traverses the list from leftmost node to right to print 
	//the values of the tree in logical order
	void print(BSTNode<T, U>* pTree) const;

	//continues to delete nodes while there are still left or right subtrees
	void destroyTree(BSTNode<T, U>* pTree);

	//node represeting the first/top node in the tree
	BSTNode<T, U>* mpRoot;
};

template<class T, class U>
inline BST<T, U>::BST()
{
	this->mpRoot = nullptr;

	ifstream inputFile("MorseTable.txt");

	string buff;
	char c;
	string morse;


	if (inputFile)
	{
		while (inputFile >> c >> morse)
		{
			this->insert(c, morse);
		}
	}

	inputFile.close();
}

template<class T, class U>
inline void BST<T, U>::insert(const T& newData, const U& newData2)
{
	insert(newData, newData2, this->mpRoot);
}

template<class T, class U>
inline U BST<T, U>::search(const T itemLookedFor) const
{
	return search(itemLookedFor, this->mpRoot);
}

template<class T, class U>
inline void BST<T, U>::print() const
{
	print(this->mpRoot);
}

template<class T, class U>
inline BST<T, U>::~BST()
{
	destroyTree(this->mpRoot);
}

template<class T, class U>
inline void BST<T, U>::insert(const T& newData, const U& newData2, BSTNode<T, U>* pTree)
{
	if (pTree == nullptr) //tree is empty (ptr points at null)
	{
		this->mpRoot = new BSTNode<T, U>(newData, newData2);
	}
	else //inserting into non empty tree
	{
		//new char is earlier in alphabet than this char? insert left of it.
		if (newData < pTree->getData()) //left subtree (only comparing the char for this)
		{
			//we found the place to insert into left
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new BSTNode<T, U>(newData, newData2));
			}
			else
			{
				//have to keep going down left subtree
				insert(newData, newData2, pTree->getLeftPtr());
			}
		}
		else if (newData > pTree->getData()) //right subtree
		{
			//found spot to insert into right
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new BSTNode<T, U>(newData, newData2));
			}
			else
			{
				//we need to go further down right subtree
				insert(newData, newData2, pTree->getRightPtr());
			}
		}
		else //duplicate entry
		{
			cout << "trying to insert duplicate: " << newData << " " << newData2 << endl;
		}
	}
}

template<class T, class U>
inline U BST<T, U>::search(const T itemLookedFor, BSTNode<T, U>* pTree) const
{
	if (pTree == nullptr)
	{
		return " ";
	}
	if (pTree->getData() == itemLookedFor)
	{
		return pTree->getMorse();
	}
	else if (itemLookedFor > pTree->getData())
	{
		return search(itemLookedFor, pTree->getRightPtr());
	}
	else if (itemLookedFor < pTree->getData())
	{
		return search(itemLookedFor, pTree->getLeftPtr());
	}
}

template<class T, class U>
inline void BST<T, U>::print(BSTNode<T, U>* pTree) const
{
	if (pTree != nullptr)
	{
		//go left, process, go right
		print(pTree->getLeftPtr()); //go left
		cout << pTree->getData() << " "; //process (print)
		cout << pTree->getMorse() << " ";
		print(pTree->getRightPtr());
	}
}

template<class T, class U>
inline void BST<T, U>::destroyTree(BSTNode<T, U>* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr()); //left subtree
		destroyTree(pTree->getRightPtr()); //right subtree

		delete pTree; //curr node
	}
}