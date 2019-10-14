#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

template <typename T>
class MiniVector
{
public:
	MiniVector(size_t = 0);
	MiniVector(const MiniVector<T>&);
	~MiniVector();
	void push_back(const T&);
	void pop_back();
	T& front();
	T& back();
	size_t size() const;
	bool empty() const;
	//MiniVector& operator= (const MiniVector<T>&);
	T& operator[](size_t);
	T& operator[](size_t) const;
private:
	T *ptr;
	size_t vSize;
	size_t capacity;
};


template <typename T>
MiniVector<T>::MiniVector(size_t size) : vSize(0), capacity(0), ptr(nullptr)
{
	if (size == 0)
		return;

	ptr = new T[size];
	vSize = size;
	capacity = size;

	for (size_t i = 0; i < vSize; i++)
		ptr[i] = T();
}

template <typename T>
MiniVector<T>::MiniVector(const MiniVector<T>& obj)
{
	ptr = new T[obj.vSize];
	this->vSize = obj.vSize;

	for (size_t i = 0; i < obj.size(); i++)
		ptr[i] = obj.ptr[i];
}

template <typename T>
MiniVector<T>::~MiniVector()
{
	if (ptr != nullptr)
		delete[] ptr;
}

template <typename T>
void MiniVector<T>::push_back(const T& obj)
{
	if (vSize == capacity)
	{
		if (capacity == 0)
		{
			capacity = 1;
			ptr = new T[1];
		}
		else
		{
			T *tempPtr;
			tempPtr = new T[2 * capacity];

			for (size_t i = 0; i < vSize; i++)
				tempPtr[i] = ptr[i];
			capacity *= 2;

			if (ptr != nullptr)
				delete[] ptr;
			ptr = tempPtr;
		}
	}

	ptr[vSize] = obj;
	vSize++;
}

template <typename T>
void MiniVector<T>::pop_back()
{
	if (vSize == 0)
		throw exception("Nothing to delete");
	vSize--;
}

template <typename T>
T& MiniVector<T>::front()
{
	if (empty())
		throw exception("Vector is empty");
	return ptr[0];
}

template <typename T>
T& MiniVector<T>::back()
{
	if (empty())
		throw exception("Vector is empty");
	return ptr[vSize - 1];
}

template <typename T>
T& MiniVector<T>::operator[](size_t idx)
{
	if (idx < 0 || idx >= vSize)
		throw exception("Out of Range");
	return ptr[idx];
}

template <typename T>
T& MiniVector<T>::operator[](size_t idx) const
{
	if (idx < 0 || idx >= vSize)
		throw exception("Out of Range");
	return ptr[idx];
}

template <typename T>
size_t MiniVector<T>::size() const
{
	return vSize;
}

template <typename T>
bool MiniVector<T>::empty() const
{
	return vSize == 0;
}
