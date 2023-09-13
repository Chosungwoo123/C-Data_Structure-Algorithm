#include "Calucalator.h"
#pragma warning(disable : 4996)

char NUMBER[] = { '1','2','3','4','5','6','7','8','9','0','.' };

int IsNumber(char Cipher)
{
	int i = 0;
	int ArrayLength = sizeof(NUMBER);

	for (i = 0; i < ArrayLength; i++)
	{
		if (Cipher == NUMBER[i])
		{
			return 1;
		}
	}

	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE)
{
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++)
	{
		Token[i] = Expression[i];

		if (IsNumber(Expression[i]) == 1)
		{
			*TYPE = OPERAND;

			if (IsNumber(Expression[i + 1]) != 1)
			{
				break;
			}
		}
		else
		{
			*TYPE = Expression[i];
			break;
		}
	}

	Token[++i] = '\0';

	return i;
}

int GetPriority(char Operator, int InStack)
{
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack)
		{
			Priority = 3;
		}
		else
		{
			Priority = 0;
		}
		break;

	case MULTIPLY:
	case DIVIDE:
		Priority = 1;
		break;

	case PLUS:
	case MINUS:
		Priority = 2;
		break;
	}

	return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
	return(GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;

	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	LLS_CreateStack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type);

		// 타입이 만약 피연산자라면 숫자를 출력
		if (Type == OPERAND)
		{
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");
		}
		// 오른쪽 괄호일때
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(Stack))
			{
				Node* Popped = LLS_Pop(Stack);

				// 왼쪽괄호가 나올때까지 모든 숫자는 출력
				if (Popped->Data[0] == LEFT_PARENTHESIS)	// 왼쪽 괄호가 나오면 삭제하고 나감
				{
					LLS_DestroyNode(Popped);
					break;
				}
				else
				{
					strcat(PostfixExpression, Popped->Data);	// 숫자는 출력
					LLS_DestroyNode(Popped);
				}
			}
		}
		// 연산자랑 왼쪽 괄호일때
		else
		{
			while (!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
			{
				Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] != LEFT_PARENTHESIS)
				{
					strcat(PostfixExpression, Popped->Data);
				}

				LLS_DestroyNode(Popped);
			}

			LLS_Push(Stack, LLS_CreateNode(Token));

		}
	}

	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);

		if (Popped->Data[0] != LEFT_PARENTHESIS)
		{
			strcat(PostfixExpression, Popped->Data);
		}

		LLS_DestroyNode(Popped);
	}

	LLS_DestroyStack(Stack);
}

double Calculate(char* PostfixExpression)
{
	LinkedListStack* Stack;
	Node* ResultNode;

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreateStack(&Stack);

	while (Read < Length)
	{
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE)
		{
			continue;
		}

		if (Type == OPERAND)
		{
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode);
		}
		else
		{
			char ResultString[32];
			double Operator1, Operator2, TempResult;
			Node* OperatorNode;

			OperatorNode = LLS_Pop(Stack);
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack);
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS:
				TempResult = Operator1 + Operator2;
				break;
			case MINUS:
				TempResult = Operator1 - Operator2;
				break;
			case MULTIPLY:
				TempResult = Operator1 * Operator2;
				break;
			case DIVIDE:
				TempResult = Operator1 / Operator2;
				break;
			}

			// 소수로 되어 있는 계산 결과를 문자열로 변환
			gcvt(TempResult, 10, ResultString);
			LLS_Push(Stack, LLS_CreateNode(ResultString));
		}
	}

	ResultNode = LLS_Pop(Stack);
	Result = atof(ResultNode->Data);
	LLS_DestroyNode(ResultNode);

	LLS_DestroyStack(Stack);

	return Result;
}