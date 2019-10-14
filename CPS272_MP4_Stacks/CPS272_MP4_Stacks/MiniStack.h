#pragma once
#include <iostream>

using namespace std;

template <typename T>
class miniStack
{
private:
	T * ptr;
	int counter;
	int length;
public:
	miniStack(int s = 0);
	bool empty() const;
	int size() const;
	void push(const T& item);
	void pop();
	T& top();
};

template <typename T>
miniStack<T>::miniStack(int s)
{
	if (s > 0)
		length = s;
	else
		length = 10;

	ptr = new T[length];
	counter = -1;
}

template <typename T>
int miniStack<T>::size() const
{
	return counter + 1;
}

template <typename T>
bool miniStack<T>::empty() const
{
	return counter == -1;
}

template <typename T>
void miniStack<T>::push(const T& item)
{
	counter++;
	ptr[counter] = item;
}

template <typename T>
void miniStack<T>::pop()
{
	if (empty())
		throw exception("stack is empty");
	counter--;
}

template <typename T>
T& miniStack<T>::top()
{
	if (empty())
		throw exception("out of range");
	return ptr[counter];
}
