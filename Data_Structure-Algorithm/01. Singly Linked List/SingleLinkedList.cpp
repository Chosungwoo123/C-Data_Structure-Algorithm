#include "SingleLinkedList.h"

// 노드 생성
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;	// 데이터를 저장한다.
	NewNode->NextNode = NULL;	// 다음 노드에 대한 포인터는 NULL로 초기화한다.

	return NewNode;				// 노드의 주소를 반환한다.
}

// 노드 소멸
void SLL_DestroyNode(Node* node)
{
	free(node);
}

// 노드 추가
void SLL_AppendNode(Node** Head, Node* NewData)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head
	if ((*Head) == NULL)
	{
		*Head = NewData;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = *Head;

		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewData;
	}
}

// 노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// 새로운 해드 추가
void SLL_InsertNewHead(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		NewNode->NextNode = *Head;
		*Head = NewNode;
	}
}

// 노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;

		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}

		SLL_DestroyNode(Remove);
	}
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 수 세기
int SLL_GetNodeCount(Node* Head)
{
	int count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		count++;
		Current = Current->NextNode;
	}

	return count;
}

// 노드 앞에 삽입
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
	if ((*Head) == Current)
	{
		NewNode->NextNode = *Head;
		*Head = NewNode;
	}
	else
	{
		Node* BeforeNode = *Head;

		while (BeforeNode != NULL && BeforeNode->NextNode != Current)
		{
			BeforeNode = BeforeNode->NextNode;
		}

		if (BeforeNode != NULL)
		{
			BeforeNode->NextNode = NewNode;
			NewNode->NextNode = Current;
		}
	}
}

// 모든 노드 삭제
void SLL_DestroyAllNodes(Node** List)
{
	int count = SLL_GetNodeCount(*List);
	Node* Current = NULL;

	printf("\nDestroying List...\n");

	for (int i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(*List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(List, Current);
			SLL_DestroyNode(Current);
		}
	}

	count = SLL_GetNodeCount(*List);

	for (int i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(*List, i);

		if (Current != NULL)
		{
			// 메모리 제거 실패
			printf("실패...");
			return;
		}
	}
}