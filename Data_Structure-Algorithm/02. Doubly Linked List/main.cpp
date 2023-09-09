// C���� ������ ����ũ�� ����Ʈ

#include "DoublyLinkedList.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	// ��� 5�� �߰�
	for (i = 0; i < 5; i++)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->Data);
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->Data);
	}

	printf("\nPrintReverse\n\n");

	// �������� ���
	DLL_PrintReverse(List);

	// ��� ��带 �޸𸮿��� ����
	printf("\nDestroying List...\n");

	DLL_DestroyAllNodes(&List);
}