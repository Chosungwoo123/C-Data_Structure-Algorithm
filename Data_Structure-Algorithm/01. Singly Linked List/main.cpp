// C���� ������ �̱۸�ũ�� ����Ʈ

#include "SingleLinkedList.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	// ��� 5�� �߰�
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);


	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ����Ʈ�� �� ��° ��� �ڿ� �� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->Data);
	}

	// ����Ʈ�� �ټ� ��° ��� �տ� �� ��� ����
	printf("\nInserting 5000 After [5]...\n\n");

	Current = SLL_GetNodeAt(List, 5);
	NewNode = SLL_CreateNode(5000);

	SLL_InsertBefore(&List, Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->Data);
	}

	// ��� ��带 �޸𸮿��� ����
	SLL_DestroyAllNodes(&List);
}