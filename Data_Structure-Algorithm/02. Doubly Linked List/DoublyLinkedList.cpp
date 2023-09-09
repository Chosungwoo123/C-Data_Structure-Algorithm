#include "DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* node)
{
	free(node);
}

// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = *Head;
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; // 기존의 테일을 새 테일의 PrevNode가 가리킨다.
	}
}

// 노드 삽입
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

// 노드 제거
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

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 수 세기
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

// 노드 삽입
void DLL_InsertBefore(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current;
	NewNode->PrevNode = Current->PrevNode;

	Current->PrevNode->NextNode = NewNode;
	Current->PrevNode = NewNode;
}

// 모든 노드 삭제
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
			// 메모리 제거 실패
			printf("실패...");
			return;
		}
	}
}

// 역순으로 출력
void DLL_PrintReverse(Node* Head)
{
	Node* Tail = Head;

	while (Tail->NextNode != NULL)
	{
		Tail = Tail->NextNode;
	}

	int Count = DLL_GetNodeCount(Head);

	// 출력
	while (Tail != NULL)
	{
		printf("List[%d] = %d\n", Count - 1, Tail->Data);
		Tail = Tail->PrevNode;
		Count--;
	}
}