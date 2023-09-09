#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

// �Լ� ���� ����
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);
void DLL_InsertBefore(Node* Current, Node* NewNode);
void DLL_DestroyAllNodes(Node** List);
void DLL_PrintReverse(Node* Head);