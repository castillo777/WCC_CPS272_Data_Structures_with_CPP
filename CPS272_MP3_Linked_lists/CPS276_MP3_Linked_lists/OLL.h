#pragma once
#include <iostream>

using namespace std;

// Node struct declaration
template <typename T>
struct nodeType
{
	T info;
	nodeType<T> *link;
	nodeType() : info(NULL), link(nullptr) {}
	nodeType(const T& data) : info(data), link(nullptr) {}
};

// Linked List Iterator class declaration
template <typename T>
class LLI
{
public:
	LLI();
	LLI(nodeType<T> *ptr);
	LLI<T> operator++();
	bool operator==(const LLI<T> &rhs) const;
	bool operator!=(const LLI<T> &rhs) const;
	T operator*();
private:
	nodeType<T> *curr;
};

// Linked List Type class declaration
template <typename T>
class LinkedListType
{
public:
	LinkedListType();
	LinkedListType(const LinkedListType<T> &otherList); // copy constructor
	~LinkedListType();
	LLI<T> begin();
	LLI<T> end();	
	T front() const;
	T back() const;
	void print() const;
	int length() const;
	virtual void insertFirst(const T& item) = 0;
	virtual void insertLast(const T& item) = 0;
	virtual void insertAtFront(const T& item) = 0;
	virtual void insertAtBack(const T& item) = 0;
	virtual bool removeFromFront(T& item) = 0;
	virtual bool removeFromBack(T& item) = 0;
	virtual void deleteNode(const T& item) = 0;
	virtual bool search(const T& item) = 0;
	void initializeList();
	bool isEmpty() const;
	void destroyList();
	void copyList(const LinkedListType<T>& otherlist);
public:
	int count;
	nodeType<T> *first;
	nodeType<T> *last;
	nodeType<T> *getNewNode(const T& value);
};

// Ordered Linked List class declaration
template <typename T>
class OLL : public LinkedListType<T>
{
public:
	bool search(const T& item);
	void insertFirst(const T& item);
	void insertLast(const T& item);
	void insertAtFront(const T& item);
	void insertAtBack(const T& item);
	bool removeFromFront(T& item);
	bool removeFromBack(T& item);
	void deleteNode(const T& item);
	void helpInsert(const T& item);
	//int sumListElements();
	//double findAverageOfListElements();
};

// Begin LLI class implementation
template <typename T>
LLI<T>::LLI()
{
	curr = nullptr;
}

template <typename T>
LLI<T>::LLI(nodeType<T> *ptr)
{
	curr = ptr;
}

template <typename T>
LLI<T> LLI<T>::operator++()
{
	curr = curr->link;
	return *this;
}

template <typename T>
bool LLI<T>::operator==(const LLI<T> &rhs) const
{
	return (this->curr == rhs.curr);
}

template <typename T>
bool LLI<T>::operator!=(const LLI<T> &rhs) const
{
	return (this->curr != rhs.curr);
}

template <typename T>
T LLI<T>::operator*()
{
	return curr->info;
} // End LLI class implementation

// Begin Linked List Type class implementation
template <typename T>
LinkedListType<T>::LinkedListType()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}

template <typename T>
LinkedListType<T>::LinkedListType(const LinkedListType<T> &otherList)
{
	first = nullptr;
	copyList(otherList);
}

template <typename T>
LinkedListType<T>::~LinkedListType()
{
	destroyList();
}

template <typename T>
LLI<T> LinkedListType<T>::begin()
{
	LLI<T> it(first);
	return it;
}

template <typename T>
LLI<T> LinkedListType<T>::end()
{
	LLI<T> it(nullptr);
	return it;
}

template <typename T>
T LinkedListType<T>::front() const
{
	return first->info;
}

template <typename T>
T LinkedListType<T>::back() const
{
	return last->info;
}

template <typename T>
void LinkedListType<T>::print() const
{
	nodeType<T> *p;
	p = first;

	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->link;
	}

	cout << endl;
}

template <typename T>
int LinkedListType<T>::length() const
{
	return count;
}

template <typename T>
void LinkedListType<T>::initializeList()
{
	destroyList;
}

template <typename T>
bool LinkedListType<T>::isEmpty() const
{
	return count == 0;
}

template <typename T>
void LinkedListType<T>::destroyList()
{
	nodeType<T> *temp;

	while (first != nullptr)
	{
		temp = first;
		first = first->link;
		delete temp;
	}

	last = nullptr;
	count = 0;
}

template<typename T>
inline nodeType<T>* LinkedListType<T>::getNewNode(const T& value)
{
	return new nodeType<T>(value);
}

template <typename T>
void LinkedListType<T>::copyList(const LinkedListType<T>& otherlist)
{
	/*
	1. create a node and call it newNode
	2. Copy the info of the node into newNode
	3. Insert newNode at the end of the list being created
	*/

	nodeType<T> *newNode;
	nodeType<T> *p;

	if (first != nullptr)
		destroyList();
	if (otherlist.first == nullptr)
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		p = otherlist.first;
		count = otherlist.count;
		first = new nodeType<T>;
		first->info = p->info;
		first->link = nullptr;
		last = first;
		p = p->link;

		while (p != nullptr)
		{
			newNode = new nodeType<T>;
			newNode->info = p->info;
			newNode->link = nullptr;
			last->link = newNode;
			last = newNode;
			p = p->link;
		}
	}
} // End LLT class implementation

// Begin OLL class implementation
template <typename T>
bool OLL<T>::search(const T& item)
{
	bool found = false;

	nodeType<T> *p;
	p = this->first;

	while (p != nullptr && !found)
	{
		if (p->info >= item)
			found = true;
		else
			p = p->link;
	}

	if (found)
		found = (p->info == item);

	return found;
}

template <typename T>
void OLL<T>::insertFirst(const T& item)
{
	helpInsert(item);
}

template <typename T>
void OLL<T>::insertLast(const T& item)
{
	helpInsert(item);
}

template <typename T>
void OLL<T>::helpInsert(const T& item)
{
	nodeType<T> *p = nullptr, *t = nullptr, *n = nullptr;
	bool found = false;

	n = new nodeType<T>;
	n->info = item;
	n->link = nullptr;

	// Case 1
	if (this->first == nullptr)
	{
		this->first = n;
		this->last = n;
		this->count++;
	}
	else
	{
		p = this->first;
		found = false;

		while (p != nullptr && !found)
		{
			if (p->info >= item)
				found = true;
			else
			{
				t = p;
				p = p->link;
			}
		}
		
		if (p == this->first) // Case 2
		{
			n->link = this->first;
			this->first = n;
			this->count++;
		}
		else //Case 3
		{
			t->link = n;
			n->link = p;

			if (p == nullptr)
				this->last = n;
			this->count++;
		}
	}
}

template <typename T>
void OLL<T>::insertAtFront(const T& item)
{
	nodeType<T> *nPtr = this->getNewNode(item);

	if (this->isEmpty())
		this->first = this->last = nPtr;
	else
	{
		nPtr->link = this->first;
		this->first = nPtr;
	}
}

template <typename T>
void OLL<T>::insertAtBack(const T& item)
{
	nodeType<T> *nPtr = this->getNewNode(item);

	if (this->isEmpty())
		this->first = this->last = nPtr;
	else
	{
		this->last->link = nPtr;
		this->last = nPtr;
	}
}

template <typename T>
bool OLL<T>::removeFromFront(T& item)
{
	if (this->isEmpty())
		return false;
	else 
	{
		nodeType<T> *temp = this->first;
		if (this->first == this->last)
			this->first = this->last = nullptr;
		else
		{
			this->first = this->first->link;
			item = temp->info;
		}
		delete temp;
		
		return true;
	}
}

template <typename T>
bool OLL<T>::removeFromBack(T& item)
{
	if (this->isEmpty())
		return false;
	else
	{
		nodeType<T> *temp = this->last;

		if (this->first == this->last)
			this->first = this->last = nullptr;
		else
		{
			nodeType<T> *curr = this->first;

			while (curr->link != this->last)
				curr = curr->link;

			this->last = curr;
			curr->link = nullptr;
			delete curr;
		}

		item = temp->info;
		temp->link = nullptr;
		delete temp;

		return true;
	}
}

template <typename T>
void OLL<T>::deleteNode(const T& item)
{
	nodeType<T> *p = nullptr, *t = nullptr;
	bool found = false;

	if (this->first == nullptr)
		cout << "Empty list" << endl;
	else
	{
		p = this->first;
		found = false;

		while (p != nullptr && !found)
		{
			if (p->info >= item)
				found = true;
			else
			{
				t = p;
				p = p->link;
			}
		}

		if (p == nullptr)
			cout << "Item not found." << endl;
		else if (p->info == item)
		{
			if (this->first == p)
			{
				this->first = this->first->link;

				if (this->first == nullptr)
					this->last = nullptr;
				delete p;
			}
			else
			{
				t->link = p->link;

				if (p == this->last)
					this->last = t;
				delete p;
			}

			this->count++;
		}
		else
			cout << "Item does not exist." << endl;
	}
} // End OLL class implementation 
