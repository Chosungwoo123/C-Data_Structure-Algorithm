// C언어로 구현한 배열로 만든 스택

#include "ArrayStack.h"

int main(int argc, char* arvc[])
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	AS_Push(Stack, 54);
	AS_Push(Stack, 12134);
	AS_Push(Stack, 15435);
	AS_Push(Stack, 112);
	AS_Push(Stack, 14);
	AS_Push(Stack, 12566);

	printf("Capacity : %d, Size : %d, Top : %d\n\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	int count = AS_GetSize(Stack);

	for (i = 0; i < count; i++)
	{
		if (AS_IsEmpty(Stack))
		{
			break;
		}

		if (AS_IsFull(Stack))
		{
			printf("Stack is full.\n");
		}
		else
		{
			printf("Stack is not full.\n");
		}

		printf("Popped : %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
		{
			printf("Current Top : %d\n\n", AS_Top(Stack));
		}
		else
		{
			printf("Stack is empty.\n\n");
		}
	}

	AS_DestroyStack(Stack);

	return 0;
}