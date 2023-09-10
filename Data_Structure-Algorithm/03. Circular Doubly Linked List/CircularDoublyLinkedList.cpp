#include "CircularDoublyLinkedList.h"

// ��� ����
Node* CDLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void CDLL_DestroyNode(Node* Node)
{
	free(Node);
}

// ��� �߰�
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;

		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		// ���ϰ� ��� ���̿� NewNode�� �����Ѵ�.
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		// ������ ������ ���ο� ������ PrevNode�� ����Ų��.
		NewNode->NextNode = *Head;
		NewNode->PrevNode = Tail;
	}
}

// ��� ����
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}

// ��� ����
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// ��� Ž��
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� �� ����
int CDLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;

		if (Current == Head)
		{
			break;
		}
	}

	return Count;
}

// ��� ��� ����
void CDLL_DestroyAllNodes(Node** List)
{
	int Count = CDLL_GetNodeCount(*List);
	Node* Current = NULL;

	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt(*List, 0);

		if (Current != NULL)
		{
			CDLL_RemoveNode(List, Current);
			CDLL_DestroyNode(Current);
		}
	}
}