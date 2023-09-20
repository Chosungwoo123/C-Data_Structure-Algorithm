#include "LinkedQueue.h"

#pragma warning(disable : 4996)

void LQ_CreateQueue(LinkedQueue** Queue)
{
	// ť�� ���� ����ҿ� ����
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}

	// ť�� ���� ����ҿ��� ����
	free(Queue);
}

Node* LQ_CreateNode(const char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(NewData) + 1);

	strcpy(NewNode->Data, NewData);

	NewNode->NewtNode = NULL;

	return NewNode;
}

void LQ_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else
	{
		Queue->Rear->NewtNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
	// LQ_Dequeue() �Լ��� ��ȯ�� �ֻ��� ���
	Node* Front = Queue->Front;

	if (Queue->Front->NewtNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NewtNode;
	}

	Queue->Count--;

	return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}