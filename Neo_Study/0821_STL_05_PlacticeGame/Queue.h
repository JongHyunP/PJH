#pragma once
class Node
{
	int itsMember;
	Node* itsNext;
public:
	friend class Queue;
};

class Queue
{
	int itsNumber;
	Node* pHead;
	Node* pLast;
public:
	Queue();
	~Queue();
	void Push(int newMember);
	int Pop();
	int GetNumber();
};
