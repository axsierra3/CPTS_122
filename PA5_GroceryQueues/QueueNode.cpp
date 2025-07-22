#include "QueueNode.hpp"

QueueNode::QueueNode(Data newData)
{ //lets dynamically allocate the data
	this->pData = (Data*)malloc(sizeof(Data)); //pdata ptr pts toward memory block it takes

	this->pData->setCustomerNumber( newData.getCustomerNumber() );
	this->pData->setServiceTime( newData.getServiceTime() );
	this->pData->setTotalTime(newData.getTotalTime());

}

QueueNode::~QueueNode()
{
	free(this->pData);
//(note: delete is used for memory allocated with 'this', free() is for malloc
}

Data QueueNode::getData() const
{
	return *pData;
}

QueueNode* QueueNode::getNextPtr() const
{
	return this->pNext;
}

void QueueNode::setNextPtr(QueueNode* const newNextPtr)
{
	this->pNext = newNextPtr;
}
