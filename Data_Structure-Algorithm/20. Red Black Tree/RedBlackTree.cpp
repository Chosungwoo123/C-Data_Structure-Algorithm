#include "RedBlackTree.h"

#pragma warning(disable : 4996)

extern RBTNode* Nil;

void RBT_DestoryTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
		RBT_DestoryTree(Tree->Right);

	if (Tree->Left != Nil)
		RBT_DestoryTree(Tree->Left);

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	NewNode->color = BLACK;

	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return NULL;

	if (Tree == NULL)
		return NULL;

	if (Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);
	else if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);
	else
		return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return Nil;

	if (Tree->Left == Nil)
		return Tree;
	else
		return RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
	if ((*Tree) == NULL)
		(*Tree) = NewNode;

	if ((*Tree)->Data < NewNode->Data)
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
	}
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
		LeftChild->Right->Parent = Parent;

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
		(*Root) = LeftChild;
	else
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = LeftChild;
		else
			Parent->Parent->Right = LeftChild;
	}

	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
		RightChild->Left->Parent = Parent;

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
		(*Root) = RightChild;
	else
	{
		if (Parent == Parent->Parent->Left)
			Parent->Parent->Left = RightChild;
		else
			Parent->Parent->Right = RightChild;
	}

	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
	while (X != (*Root) && X->Parent->color == RED)
	{
		if (X->Parent == X->Parent->Parent->Left)
		{
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->color == RED)
			{
				X->Parent->color = BLACK;
				Uncle->color = BLACK;
				X->Parent->Parent->color = RED;

				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Right)
				{
					X = X->Parent;
					RBT_RotateLeft(Root, X);
				}

				X->Parent->color = BLACK;
				X->Parent->Parent->color = RED;

				RBT_RotateRight(Root, X->Parent->Parent);
			}
		}
		else
		{
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->color == RED)
			{
				X->Parent->color = BLACK;
				Uncle->color = BLACK;
				X->Parent->Parent->color = RED;
				X = X->Parent->Parent;
			}
			else
			{
				if (X == X->Parent->Left)
				{
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}

				X->Parent->color = BLACK;
				X->Parent->Parent->color = RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	(*Root)->color = BLACK;
}

RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL)
		return NULL;

	if (Target->Left == Nil || Target->Right == Nil)
	{
		Removed = Target;
	}
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
		Successor = Removed->Left;
	else
		Successor = Removed->Right;

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL)
		(*Root) = Successor;
	else
	{
		if (Removed == Removed->Parent->Left)
			Removed->Parent->Left = Successor;
		else
			Removed->Parent->Right = Successor;
	}

	if (Removed->color == BLACK)
		RBT_RebuildAfterRemove(Root, Successor);

	return Removed;
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;

	while (Successor->Parent != NULL && Successor->color == BLACK)
	{
		if (Successor == Successor->Parent->Left)
		{
			Sibling = Successor->Parent->Right;

			// 형제가 빨간색인 경우
			if (Sibling->color == RED)
			{
				Sibling->color = BLACK;
				Successor->Parent->color = RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			// 형제가 검정색이고
			else
			{
				// 양쪽 자식이 모두 검은색인 경우
				if (Sibling->Left->color == BLACK &&
					Sibling->Right->color == BLACK)
				{
					Sibling->color = RED;
					Successor = Successor->Parent;
				}
				// 왼쪽 자식이 빨간색인 경우
				else
				{
					if (Sibling->Left->color == RED)
					{
						Sibling->Left->color = BLACK;
						Sibling->color = RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					// 오른쪽 자식이 빨간색인 경우
					Sibling->color = Successor->Parent->color;
					Successor->Parent->color = BLACK;
					Sibling->Right->color = BLACK;
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
		else
		{
			Sibling = Successor->Parent->Left;

			if (Sibling->color = RED)
			{
				Sibling->color = BLACK;
				Successor->Parent->color = RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if (Sibling->Right->color == BLACK &&
					Sibling->Left->color == BLACK)
				{
					Sibling->color = RED;
					Successor = Successor->Parent;
				}
				else
				{
					if (Sibling->Right->color == RED)
					{
						Sibling->Right->color = BLACK;
						Sibling->color = RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					Sibling->color = Successor->Parent->color;
					Successor->Parent->color = BLACK;
					Sibling->Left->color = BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}

	Successor->color = BLACK;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	int i = 0;
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
		return;

	if (Node->color == BLACK)
		BlackCount++;

	if (Node->Parent != NULL)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
			c = 'L';
		else
			c = 'R';
	}

	if (Node->Left == Nil && Node->Right == Nil)
		sprintf(cnt, "\t--------- %d", BlackCount);
	else
		sprintf(cnt, "");

	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%d %s [%c,%d] %s\n", Node->Data,
		(Node->color == RED) ? "RED" : "BLACK", c, v, cnt);

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}