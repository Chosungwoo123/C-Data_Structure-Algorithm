#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

enum Color
{
	RED,
	BLACK
};

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	Color color;

	ElementType Data;
} RBTNode;

void RBT_DestoryTree(RBTNode* Tree);

RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestroyNode(RBTNode* Node);

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);
RBTNode* RBT_SearchMinNode(RBTNode* Tree);
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);
void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X);
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data);
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor);

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);