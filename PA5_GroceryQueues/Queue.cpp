#include "Queue.hpp"

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::enqueue(const Data& newData)
{
	QueueNode* pNode = new QueueNode(newData); //dynamically allocate a new queuenode
	bool success = false;

	if (pNode != nullptr) //sucessfully made the node to add
	{
		if (this->mpHead == nullptr) //empty q
		{
			this->mpHead = this->mpTail = pNode; //the whole list is this new node
		}
		else 
		{ //its not empty
			this->mpTail->setNextPtr(pNode); //set the old tail's next to the new node
			this->mpTail = pNode; //and now update the tail to the new node
		}
		success = true;
	}
	return success;
}

Data Queue::dequeue()
{
	Data data = this->mpHead->getData(); //data is the head's data (which is the one we're about to delete)
	QueueNode* pTemp = this->mpHead;

	if (this->mpHead == this->mpTail) //theyre both null, or the only node in q
	{
		this->mpTail = nullptr;  //just make the tail null (which makes them both pt to null)
	}

	this->mpHead = this->mpHead->getNextPtr(); //new head = next

	delete pTemp; //lets invoke the destructor for a QueueNode
	//cout << "now dequeuing: " << data << endl; //overload the << constructor for data

	return data;
}

bool Queue::isEmpty() const
{
	return this->mpHead == nullptr && this->mpTail == nullptr; //both are null? evals to true
}

void Queue::printQueueRecursively()
{
	printQueueRecursively(this->mpHead);
}

Data Queue::getHeadData() const
{
	return this->mpHead->getData();
}

Data Queue::getTailData() const
{
	return this->mpTail->getData();
}

void Queue::runApp(int n)
{
	Queue normalLane;
	Queue expressLane;
	int totalTimeElapsed = 0;
	int arrivalTime = 0, eArrivalTime = 0;
	int serviceTime = 0, eServiceTime = 0;
	int checkoutTime = 0, eCheckoutTime = 0;
	int sumServiceTimes = 0, sumEServiceTimes = 0; //keep track
	int currCust = 1, currECust = 1;


	//first arrival
	arrivalTime = (rand() % 6) + 3; //3 - 8
	eArrivalTime = (rand() % 5) + 1; //1-5

	while (totalTimeElapsed <= n)
	{
		cout << endl << "-Minute: " << totalTimeElapsed << endl;
		//customer to arrive in normal lane
		if (totalTimeElapsed == arrivalTime)
		{
			serviceTime = (rand() % 6) + 3; //3 - 8 min
			checkoutTime = serviceTime + arrivalTime; //they need to check out = service time + the time they got there

			Data custData(currCust, serviceTime, checkoutTime);
			normalLane.enqueue(custData);
			cout << endl << "A new customer has arrived to the normal lane!" << endl;
			cout << "Arrival Time: " << arrivalTime << " Customer Number: " << custData.getCustomerNumber() << endl;

			arrivalTime = totalTimeElapsed + (rand() % 6) + 3; //arrivalTime for next cust (when this if will be activated again)
			currCust++;
		}
		//customer to arrive in express lane
		if (totalTimeElapsed == eArrivalTime)
		{
			eServiceTime = (rand() % 5) + 1; //1-5 min
			checkoutTime = eServiceTime + eArrivalTime; //they need to check out = service time + the time they got there

			Data eCustData(currECust, eServiceTime, checkoutTime);
			expressLane.enqueue(eCustData);
			cout << endl << "A new customer has arrived to the express lane!" << endl;
			cout << "Arrival Time: " << eArrivalTime << " Customer Number: " << eCustData.getCustomerNumber() << endl;

			eArrivalTime = totalTimeElapsed + (rand() % 5) + 1;
			currECust++;
		}

		if (!normalLane.isEmpty())
		{
			if (normalLane.getHeadData().getTotalTime() == totalTimeElapsed) //if the time == time elasped
			{
				cout << endl << "A customer is checking out of the normal line!" << endl << normalLane.getHeadData() << endl;
				normalLane.dequeue();
			}
		}
		if (!expressLane.isEmpty())
		{
			if (expressLane.getHeadData().getTotalTime() == totalTimeElapsed)
			{
				cout << endl << "A customer is checking out of the express line!" << endl << expressLane.getHeadData() << endl;
				expressLane.dequeue();
			}
		}

		if (totalTimeElapsed != 0 && totalTimeElapsed % 10 == 0) //if a 10 min increment
		{
			cout << "--CURRENT NORMAL LANE CONTENTS-- " << endl;
			normalLane.printQueueRecursively();
			cout << "-----" << endl;
			cout << "--CURRENT EXPRESS LANE CONTENTS-- " << endl;
			expressLane.printQueueRecursively();
			cout << "-----" << endl;
		}

		totalTimeElapsed++; //minute goes up by 1

		if (totalTimeElapsed == 1440) //hit 24h
		{
			currCust = 1;
			currECust = 1;
		}
	}
}



void Queue::printQueueRecursively(QueueNode* pCur)
{ //originally pass in head then go further

	if (pCur != nullptr)
	{
		cout << pCur->getData() << endl;

		pCur = pCur->getNextPtr();
		printQueueRecursively(pCur);
	}
}






