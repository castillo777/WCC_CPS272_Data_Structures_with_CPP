#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T> class MiniList;

template <typename T>
class ListNode
{
	friend class MiniList<T>;
public:
	ListNode(const T& info) : data(info), nextPtr(nullptr) {}
	T getData() const { return data; }
	void setNextPtr(ListNode *nPtr) { nextPtr = nPtr; }
	ListNode *getNextPtr() const { return nextPtr; }
private:
	ListNode<T> *nextPtr;
	T data;
};

#endif
