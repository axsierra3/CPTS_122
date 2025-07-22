//PA 5
//Name: Arantxa Sierra
//Description: Main is used to call the function to run rhe application, contained in the 
// queue class.
// Main prompts the user for a number of minutes that the simulation should run
// for and passes it into the function. 
// The simulation starts two distinct queues in a grocery store, a "normal" line and 
// an "express line". The program prints how customers in both lines enter the line
// and leave the line as time passes in the simulation, until the deseired time is reached.
// Information such as customer number, arrival time, service time, and total time is printed.
// In addition, main is used to tun the test functions for the queue.

#include "Queue.hpp"
#include "testQueue.hpp"
#include <ctime>

int main() {

	testQueue test;
	/*test.testEmptyEnqueue();*/
	//test.testOneEnqueue();
	//test.testOneDequeue();
	//test.testTwoDequeue();
	//test.run24HrSim();

	int n = 0;

	srand(time(0));
	cout << "--Welcome to the Grocery Store Line simulator!--" << endl << endl;
	cout << "How many minutes should the simulation last?: ";
	cin >> n;

	Queue::runApp(n);
	
	return 0;
}