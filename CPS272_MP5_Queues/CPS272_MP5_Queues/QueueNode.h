#ifndef QUEUENODE_H
#define QUEUENODE_H

template <typename T> class MiniQueue;

template <typename T>
class QueueNode
{
	friend class MiniQueue<T>;
public:
	QueueNode(const T&);
	T getData() const;
private:
	T data;
	QueueNode<T> *nextPtr;
};

template <typename T>
QueueNode<T>::QueueNode(const T& info) : data(info), nextPtr(nullptr) {}

template <typename T>
T QueueNode<T>::getData() const { return data; }

#endif