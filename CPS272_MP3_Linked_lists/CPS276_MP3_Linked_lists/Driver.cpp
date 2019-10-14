#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "MiniList.h"

template <typename T>
void mergeLists(MiniList<T>& list1, MiniList<T>& list2, MiniList<T>& resultantList)
{
	MiniList<T> tempList1(list1);
	MiniList<T> tempList2(list2);
	T value1;
	T value2;	

	while (!tempList1.isEmpty() && !tempList2.isEmpty())
	{
		tempList1.removeFromFront(value1);
		tempList2.removeFromFront(value2);

		if (value1 != value2)
		{
			if (resultantList.search(value1) == false)
				resultantList.insertInOrder(value1);

			if (resultantList.search(value2) == false)
				resultantList.insertInOrder(value2);		
		}
		else
		{
			if (resultantList.search(value1) == false)
				resultantList.insertInOrder(value1);
		}
	}

	while ((!tempList1.isEmpty()) && (tempList2.isEmpty()))
	{	
		tempList1.removeFromFront(value1);

		if (resultantList.search(value1) == false)
			resultantList.insertInOrder(value1);
	}

	while ((tempList1.isEmpty()) && (!tempList2.isEmpty()))
	{
		tempList2.removeFromFront(value2);

		if (resultantList.search(value2) == false)
			resultantList.insertInOrder(value2);
	} 
}

int sumList(MiniList<int> &listReference)
{
	MiniList<int> temp(listReference);
	int sum = 0;
	int value;

	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		sum += value;
	}

	return sum;
}

double averageOfList(MiniList<int> &listReference)
{
	MiniList<int> temp(listReference);
	double sum = 0.0;
	int value = 0;

	while (!temp.isEmpty())
	{
		temp.removeFromFront(value);
		sum += value;
	}

	return (static_cast<double>(sum / temp.length()));
}

int main()
{
	MiniList<int> listA;
	MiniList<int> listB;
	MiniList<int> listC;

	srand(time(0));

	int sum = 0;
	double average = 0.00;

	for (int i = 0; i < 20; i++)
	{
		listA.insertInOrder(rand() % 101);
	}

	for (int i = 0; i < 15; i++)
	{
		listB.insertInOrder(rand() % 101);
	}

	mergeLists(listA, listB, listC);
	sum = sumList(listC);
	average = averageOfList(listC);

	cout << "List A elements: " << endl;
	listA.print();
	cout << endl;
	cout << "List B elements: " << endl;
	listB.print();
	cout << endl;
	cout << "List C elements merged from List A and List B: " << endl;
	listC.print();
	cout << endl;
	cout << "The sum of the elements is: " << sum << endl << endl;
	cout << fixed << showpoint << setprecision(1);
	cout << "The average of the elements is: " << average << endl << endl;

	system("pause");
	return 0;
}