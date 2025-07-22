#include "data.hpp"

Data::Data(int customerNumber, int serviceTime, int totalTime)
{
	this->customerNumber = customerNumber;
	this->serviceTime = serviceTime;
	this->totalTime = totalTime;
}

Data::~Data()
{
	//cout << "finished removing data" << endl;
}

void Data::setCustomerNumber(int custNum)
{
	this->customerNumber = custNum;
}

void Data::setServiceTime(int servTime)
{
	this->serviceTime = servTime;
}

void Data::setTotalTime(int totTime)
{
	this->totalTime = totTime;
}

int Data::getCustomerNumber()
{
	return this->customerNumber;
}

int Data::getServiceTime()
{
	return this->serviceTime;
}

int Data::getTotalTime()
{
	return this->totalTime;
}

ostream& operator<<(ostream& outputS, Data data)
{
	outputS << "Customer Number: " << data.customerNumber << " Service Time: " << data.serviceTime << " Total Time: " << data.totalTime<< endl;

		return outputS; //output is being put in 'cout' in our case
}
