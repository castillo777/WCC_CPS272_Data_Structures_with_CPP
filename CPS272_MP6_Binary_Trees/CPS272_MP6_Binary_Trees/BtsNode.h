#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct BstNode {
	string data;
	BstNode *lchild;
	BstNode *rchild;
};

void PreOrder(BstNode* rootptr)
{
	if (rootptr != NULL)
	{
		// if(rootptr->lchild==NULL && rootptr->rchild==NULL) //If you want to print only leaf nodes (uncomment this)
		cout << rootptr->data << " ";
		PreOrder(rootptr->lchild);
		PreOrder(rootptr->rchild);
	}
}

void InOrder(BstNode* rootptr)
{
	if (rootptr != NULL)
	{
		InOrder(rootptr->lchild);
		cout << rootptr->data << " ";
		InOrder(rootptr->rchild);
	}
}

void PostOrder(BstNode* rootptr)
{
	if (rootptr != NULL)
	{
		PostOrder(rootptr->lchild);
		PostOrder(rootptr->rchild);
		cout << rootptr->data << " ";
	}
}

int FindHeight(BstNode* temp)
{
	if (temp == NULL)
		return -1;
	return (max(FindHeight(temp->lchild), FindHeight(temp->rchild)) + 1);

}

BstNode* Insert(BstNode* rootptr, string value)
{
	BstNode* temp = NULL;

	if (rootptr == NULL)
	{
		temp = new BstNode();
		temp->data = value;
		temp->rchild = temp->lchild = NULL;
		rootptr = temp;
	}
	else if (value > rootptr->data)
	{
		rootptr->rchild = Insert(rootptr->rchild, value);
	}
	else
	{
		rootptr->lchild = Insert(rootptr->lchild, value);
	}

	return rootptr;
}

int getLeafCount(BstNode* node)
{
	if (node == NULL)
		return 0;
	if (node->lchild == NULL && node->rchild == NULL)
		return 1;
	else
		return getLeafCount(node->lchild) + getLeafCount(node->rchild);
}
