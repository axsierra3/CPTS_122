#include "testQueue.hpp"

void testQueue::testEmptyEnqueue(void)
{
	Queue testQ; //automatically, both head ptrs should be empty
	Data testD(1, 2, 3);

	int success = testQ.enqueue(testD);

	if (!testQ.isEmpty() && success == 1)
	{
		cout << "Queue is not empty! node enqueued!" << endl;
	}
	if (testQ.getHeadData().getCustomerNumber() == 1)
	{
		cout << "The correct data has been allocated!" << endl;
	}
}

void testQueue::testOneEnqueue(void)
{
	Queue testQ; 
	Data testD(1, 2, 3);
	Data test2(2, 3, 6);

	testQ.enqueue(testD); // one node in q
	int success = testQ.enqueue(test2);

	if (success == 1)
	{
		cout << "2nd node enqueued!" << endl;
	}
	if (testQ.getHeadData().getCustomerNumber() == 1 && testQ.getTailData().getCustomerNumber() == 2)
	{
		cout << "Correct data for head and tail pointer" << endl;
	}
}

void testQueue::testOneDequeue(void)
{
	Queue testQ; 
	Data testD(1, 2, 3);

	testQ.enqueue(testD);
	testQ.dequeue();

	if (testQ.isEmpty())
	{
		cout << "Queue is empty! Dequeue successful!" << endl;
	}
}

void testQueue::testTwoDequeue(void)
{
	Queue testQ;
	Data testD(1, 2, 3);
	Data test2(2, 3, 6);

	testQ.enqueue(testD); 
	testQ.enqueue(test2); //2 nodes in q 

	testQ.dequeue(); //first data should be gone now

	if (testQ.getHeadData().getCustomerNumber() == 2)
	{
		cout << "Dequeue on list of two successful!" << endl;

	}


}

void testQueue::run24HrSim(void)
{
	Queue::runApp(1440);
}
