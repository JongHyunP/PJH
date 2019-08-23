#include "Queue.h"

Queue::Queue()
{
	itsNumber = 0;
	pHead = new Node;
	pLast = pHead;
}

Queue::~Queue()
{
	Node* pDelete;

	while (pHead != pLast)
	{
		pDelete = pHead;
		pHead = pDelete->itsNext;
		delete pDelete;
	}

	delete pLast;

}

void Queue::Push(int newMember)
{
	pLast->itsMember = newMember;
	pLast->itsNext = new Node;

	pLast = pLast->itsNext;
	itsNumber++;
}

int Queue::Pop()
{
	int returnValue = 0;
	Node* deleteNode;

	if (itsNumber > 0)
	{
		deleteNode = pHead;
		pHead = deleteNode->itsNext;

		returnValue = deleteNode->itsMember;
		delete deleteNode;

		itsNumber--;
	}

	return returnValue;
}

int Queue::GetNumber()
{
	return itsNumber;
}
