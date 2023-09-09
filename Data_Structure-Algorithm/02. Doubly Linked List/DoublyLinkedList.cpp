#include "DoublyLinkedList.h"

// ��� ����
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void DLL_DestroyNode(Node* node)
{
	free(node);
}

// ��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = *Head;
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; // ������ ������ �� ������ PrevNode�� ����Ų��.
	}
}

// ��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}

// ��� ����
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}

		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// ��� Ž��
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� �� ����
int DLL_GetNodeCount(Node* Head)
{
	unsigned int	Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// ��� ����
void DLL_InsertBefore(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current;
	NewNode->PrevNode = Current->PrevNode;

	Current->PrevNode->NextNode = NewNode;
	Current->PrevNode = NewNode;
}

// ��� ��� ����
void DLL_DestroyAllNodes(Node** List)
{
	int count = DLL_GetNodeCount(*List);
	Node* Current = NULL;

	for (int i = 0; i < count; i++)
	{
		Current = DLL_GetNodeAt(*List, 0);

		DLL_RemoveNode(List, Current);
		DLL_DestroyNode(Current);
	}

	count = DLL_GetNodeCount(*List);

	for (int i = 0; i < count; i++)
	{
		Current = DLL_GetNodeAt(*List, i);

		if (Current != NULL)
		{
			// �޸� ���� ����
			printf("����...");
			return;
		}
	}
}

// �������� ���
void DLL_PrintReverse(Node* Head)
{
	Node* Tail = Head;

	while (Tail->NextNode != NULL)
	{
		Tail = Tail->NextNode;
	}

	int Count = DLL_GetNodeCount(Head);

	// ���
	while (Tail != NULL)
	{
		printf("List[%d] = %d\n", Count - 1, Tail->Data);
		Tail = Tail->PrevNode;
		Count--;
	}
}