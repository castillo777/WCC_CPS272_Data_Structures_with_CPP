#ifndef MINILIST_H
#define MINILIST_H
#include <iostream>
#include "ListNode.h"

using namespace std;

template <typename T>
class MiniList
{
public:
	MiniList();
	MiniList(const MiniList<T>& copy);
	~MiniList();
	void insertInOrder(const T& value);
	void insertAtFront(const T& value);
	void insertAtBack(const T& value);
	bool removeFromFront(T& value);
	bool removeFromBack(T& value);
	int length() const;
	bool search(const T& value);
	void print() const;	
	bool isEmpty() const;
	T front();
	T back();
	int size();
	MiniList<T> operator=(const MiniList<T>& rhs);
protected:
	ListNode<T> *firstPtr;
	ListNode<T> *lastPtr;
	ListNode<T> *getNewNode(const T& value);
private:
	int count;
};

template <typename T>
MiniList<T> MiniList<T>::operator=(const MiniList<T>& rhs)
{
	ListNode<T> *temp = rhs.firstPtr;

	if (rhs.isEmpty())
		return MiniList<T>();

	while (temp != nullptr)
	{
		this->insertAtBack(temp->data);
		temp = temp->nextPtr;
	}
}

template <typename T>
int MiniList<T>::size()
{
	ListNode<T> *temp = firstPtr;
	int counter = 0;

	if (isEmpty())
		return counter;

	counter++;

	while (temp != lastPtr)
	{
		temp = temp->nextPtr;
		counter++;
	}

	return counter;
}

template <typename T>
T MiniList<T>::back()
{
	if (!isEmpty())
		return lastPtr->data;
	return NULL;
}

template <typename T>
T MiniList<T>::front()
{
	if (!isEmpty())
		return firstPtr->data;
	return NULL;
}

template <typename T>
bool MiniList<T>::removeFromBack(T& value)
{
	if (isEmpty())
		return false;
	else
	{
		ListNode<T> *temp = lastPtr;

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = nullptr;
		else
		{
			ListNode<T> *currentPtr = firstPtr;
			
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;

			lastPtr = currentPtr;
			currentPtr->nextPtr = NULL;
		}

		value = temp->data;
		delete temp;
		return true;
	}
}

template <typename T>
bool MiniList<T>::removeFromFront(T& value)
{
	if (isEmpty())
		return false;
	else
	{
		ListNode<T> *temp = firstPtr;

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = nullptr;
		else
			firstPtr = firstPtr->nextPtr;
		value = temp->data;

		delete temp;
		return true;
	}
}

template <typename T>
void MiniList<T>::print() const
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	ListNode<T> *currPtr = firstPtr;

	while (currPtr != nullptr)
	{
		cout << currPtr->data << "\t";
		currPtr = currPtr->nextPtr;
	}

	cout << endl;
}

template <typename T>
bool MiniList<T>::search(const T& value)
{
	bool found = false;

	ListNode<T> *p;
	p = firstPtr;

	while (p != nullptr && !found)
	{
		if (p->data >= value)
			found = true;
		else
			p = p->nextPtr;
	}

	if (found)
		found = (p->data == value);

	return found;
}

template <typename T>
int MiniList<T>::length() const
{
	return count;
}

template <typename T>
bool MiniList<T>::isEmpty() const
{
	return firstPtr == nullptr;
}

template <typename T>
void MiniList<T>::insertAtBack(const T& value)
{
	ListNode<T> *nPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = nPtr;
	else
	{
		lastPtr->nextPtr = nPtr;
		lastPtr = nPtr;
	}

	count++;
}

template <typename T>
void MiniList<T>::insertAtFront(const T& value)
{
	ListNode<T> *nPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = nPtr;
	else
	{
		nPtr->nextPtr = firstPtr;
		firstPtr = nPtr;
	}

	count++;
}

template <typename T>
void MiniList<T>::insertInOrder(const T& value)
{
	if (isEmpty())
	{
		ListNode<T> *newPtr = getNewNode(value);
		firstPtr = lastPtr = newPtr;
	}
	else
	{
		if (firstPtr->getData() > value)
			insertAtFront(value);
		else if (lastPtr->getData() < value)
			insertAtBack(value);
		else
		{
			ListNode<T> *currentPtr = firstPtr->getNextPtr();
			ListNode<T> *previousPtr = firstPtr;
			ListNode<T> *newPtr = getNewNode(value);

			while (currentPtr != lastPtr && currentPtr->getData() < value)
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr->getNextPtr();
			}

			previousPtr->setNextPtr(newPtr);
			newPtr->setNextPtr(currentPtr);
		}
	}

	count++;
}

template <typename T>
MiniList<T>::MiniList() : firstPtr(nullptr), lastPtr(nullptr), count(0) {}

template <typename T>
MiniList<T>::MiniList(const MiniList<T>& copy)
{
	firstPtr = lastPtr = nullptr;
	
	ListNode<T> *currentPtr = copy.firstPtr;

	while (currentPtr != nullptr)
	{
		insertAtBack(currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
}

template <typename T>
MiniList<T>::~MiniList()
{
	if (!isEmpty())
	{
		ListNode<T> *currentPtr = firstPtr;
		ListNode<T> *tempPtr;

		while (currentPtr != nullptr)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}

		count = 0;
	}
}

template <typename T>
ListNode<T>* MiniList<T>::getNewNode(const T& value)
{
	return new ListNode<T>(value);
}

#endif
