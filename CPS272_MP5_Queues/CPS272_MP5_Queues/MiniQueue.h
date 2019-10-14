#ifndef MINIQUEUE_H
#define MINIQUEUE_H
#include "QueueNode.h"
#include <iostream>

using namespace std;

template <typename T>
class MiniQueue
{
public:
	MiniQueue();
	~MiniQueue();
	void insertQueue(const T&);
	void deleteQueue();
	bool isEmpty() const;
	void printQueue() const;
	const T queueFirstData() const;
	int size() const;
protected:
	QueueNode<T> *firstPtr;
	QueueNode<T> *getNewNode(const T&);
};

template <typename T>
MiniQueue<T>::MiniQueue() : firstPtr(nullptr) {}

template <typename T>
MiniQueue<T>::~MiniQueue()
{
	cout << endl << endl;

	if (!isEmpty())
	{
		while (firstPtr != nullptr)
		{
			QueueNode<T> *currentPtr = firstPtr;
			
			firstPtr = firstPtr->nextPtr;
			delete currentPtr;
		}
	}
}

template <typename T>
void MiniQueue<T>::insertQueue(const T& value)
{
	QueueNode<T> *newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = newPtr;
	else
	{
		QueueNode<T> *tempPtr = firstPtr;

		while (tempPtr->nextPtr != nullptr)
			tempPtr = tempPtr->nextPtr;

		tempPtr->nextPtr = newPtr;
	}
}

template <typename T>
void MiniQueue<T>::deleteQueue()
{
	if (!isEmpty())
	{
		QueueNode<T> *tempPtr = firstPtr;

		firstPtr = firstPtr->nextPtr;
		delete tempPtr;
	}
}

template <typename T>
bool MiniQueue<T>::isEmpty() const
{
	return firstPtr == nullptr;
}

template <typename T>
QueueNode<T> *MiniQueue<T>::getNewNode(const T& value)
{
	return new QueueNode<T>(value);
}

template <typename T>
void MiniQueue<T>::printQueue() const
{
	if (isEmpty())
		return;

	QueueNode<T> *currentPtr = firstPtr;
	
	cout << endl << endl << "The Queue is: ";

	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << " ";
		currentPtr = currentPtr->nextPtr;
	}
}

template <typename T>
const T MiniQueue<T>::queueFirstData() const
{
	return firstPtr->data;
}

template <typename T>
int MiniQueue<T>::size() const
{
	int counter = 0;

	QueueNode<T> *currentPtr = firstPtr;

	while (currentPtr != nullptr)
	{
		counter++;
		currentPtr = currentPtr->nextPtr;
	}

	return counter;
}

#endif
