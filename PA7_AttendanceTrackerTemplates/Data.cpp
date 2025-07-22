#include "Data.hpp"

int Data::getRecordNumber()
{
	return this->mRecordNumber;
}

int Data::getID()
{
	return this->mID;
}

string Data::getName()
{
	return this->mName;
}

int Data::getNumAbsences()
{
	return this->numAbsences;
}

stack<string>& Data::getAbsencesStack()
{
	return this->absenceDates;
}

stack<string> Data::getAbsencesStackCopy()
{
	return this->absenceDates;
}

string Data::getEmail()
{
	return this->mEmail;
}

string Data::getUnits()
{
	return this->mUnits;
}

string Data::getMajor()
{
	return this->mMajor;
}

string Data::getLevel()
{
	return this->mLevel;
}


void Data::setRecordNumber(int recordNum)
{
	this->mRecordNumber = recordNum;
}

void Data::setID(int ID)
{
	this->mID = ID;
}

void Data::setName(string name)
{
	this->mName = name;
}

void Data::setEmail(string email)
{
	this->mEmail = email;
}

void Data::setUnits(string units)
{
	this->mUnits = units;
}

void Data::setMajor(string major)
{
	this->mMajor = major;
}

void Data::setLevel(string level)
{
	this->mLevel = level;
}

void Data::setNumAbsences(int numAbsences)
{
	this->numAbsences = numAbsences;
}













