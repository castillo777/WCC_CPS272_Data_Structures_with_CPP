#include <ctime>
#include <cstdlib>
#include "MiniQueue.h"

int getRandomNumber(int range)
{
	int randomNumber = 1 + rand() % range;
	return randomNumber;
}

int customersInQueue()
{
	return 0;
}

int main()
{
	MiniQueue<int> myQueue;
	
	int maxCustomers = 0;
	const int RANGE = 4;

	srand(time(0));

	int arrivalTime = getRandomNumber(RANGE); // (1 + rand() % 3);
	int serviceTime = getRandomNumber(RANGE);
	int scheduleTime = arrivalTime + getRandomNumber(RANGE);
	int longestWait = scheduleTime;

	myQueue.insertQueue(arrivalTime);

	for (int currentTime = arrivalTime; currentTime <= 120; currentTime++)
	{
		if (scheduleTime == currentTime)
		{
			myQueue.insertQueue(currentTime);
			scheduleTime = currentTime + getRandomNumber(RANGE);
		}

		if (currentTime == serviceTime)
		{
			if (myQueue.size() > 0)
			{
				int waitTime = currentTime - myQueue.queueFirstData();
				
				if (longestWait < waitTime)
					longestWait = waitTime;
			}

			myQueue.deleteQueue();
			serviceTime = currentTime + getRandomNumber(RANGE);
		}

		if (maxCustomers < myQueue.size())
			maxCustomers = myQueue.size();

		cout << endl << "Current Time = " << currentTime
			 << " - waiting time = " << longestWait
			 << " - # of customers in queue = " << maxCustomers
			 << endl;
	}

	cout << endl << "Number of customers in queue is = "
		 << myQueue.size() << endl << "Longest wait time is = "
		 << longestWait << endl << endl;

	system("pause");
	return 0;
}