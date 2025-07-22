//Data: data class is used to represent the data that makes up a student in a course, used in node

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::stack;
using std::to_string;


class Data
{
public:
	//constructors
	Data(int recordNumber = 0, int ID = 0, string name = "", string email = "", string units = "", string major = "", string level = "") :
		mRecordNumber(recordNumber), mID(ID), mName(name), mEmail(email), mUnits(units), mMajor(major), mLevel(level), numAbsences(0) {};

	//getters
	int getRecordNumber();
	int getID();
	string getName();
	int getNumAbsences();
	stack<string>& getAbsencesStack();
	stack<string> getAbsencesStackCopy();
	string getEmail();
	string getUnits();
	string getMajor();
	string getLevel();

	//setters
	void setRecordNumber(int recordNum);
	void setID(int ID);
	void setName(string name);
	void setEmail(string email);
	void setUnits(string units);
	void setMajor(string major);
	void setLevel(string level);
	void setNumAbsences(int numAbsences);


private:
	//fields
	int mRecordNumber;
	int mID;
	string mName;
	string mEmail;
	string mUnits;
	string mMajor;
	string mLevel;

	int numAbsences;
	stack<string> absenceDates; //each student has a stack, everytime theres an absence add the string date to the top of their personal stack
};