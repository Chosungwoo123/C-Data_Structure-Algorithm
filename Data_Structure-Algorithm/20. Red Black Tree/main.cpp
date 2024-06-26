// C언어로 구현한 레드블랙트리

#include "RedBlackTree.h"

#pragma warning(disable : 4996)

RBTNode* Nil;

int main(int argc, char* argv[])
{
	RBTNode* Tree = NULL;
	RBTNode* Node = NULL;

	Nil = RBT_CreateNode(0);
	Nil->color = BLACK;

	while (1)
	{
		int cmd = 0;
		int param = 0;

		printf("Enter command number : \n");
		printf("(1) Create a node, (2) Remove a node, (3) Search a Node\n");
		printf("(4) Display Tree, (5) quit\n");
		printf("command number : ");

		scanf("%d", &cmd);

		if (cmd < 1 || cmd > 5)
		{
			printf("Invalid command number.\n");
			continue;
		}
		else if (cmd == 4)
		{
			RBT_PrintTree(Tree, 0, 0);
			printf("\n");
			continue;
		}
		else if (cmd == 5)
			break;

		printf("Enter parameter (1~200) : \n");

		scanf("%d", &param);

		if (param < 1 || param > 200)
		{
			printf("Invalid parameter. %d\n", param);
			continue;
		}

		switch (cmd)
		{
		case 1:
			Node = RBT_SearchNode(Tree, param);

			if (Node == NULL)
			{
				RBT_InsertNode(&Tree, RBT_CreateNode(param));
			}

			break;

		case 2:
			Node = RBT_RemoveNode(&Tree, param);

			if (Node == NULL)
				printf("Not found node to delete : %d\n", param);
			else
				RBT_DestroyNode(Node);

			break;

		case 3:
			Node = RBT_SearchNode(Tree, param);

			if (Node == NULL)
				printf("Not found node : %d\n", param);
			else
				printf("Found Node : %d (Color : %s)\n", Node->Data, (Node->color == RED) ? "RED" : "BLACK");
			break;
		}

		printf("\n");
	}

	RBT_DestoryTree(Tree);

	return 0;
}