// C언어로 구현한 링크드 리스트로 만든 계산기

#include <stdio.h>
#include <string.h>
#include "Calucalator.h"

#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	char InfixExpresstion[100];
	char PostfixExpresstion[100];

	double Result = 0.0;

	memset(InfixExpresstion, 0, sizeof(InfixExpresstion));
	memset(PostfixExpresstion, 0, sizeof(PostfixExpresstion));

	printf("Enter Infix Expresstion : ");
	scanf("%s", InfixExpresstion);

	GetPostfix(InfixExpresstion, PostfixExpresstion);

	printf("Infix : %s\nPostfix : %s\n", InfixExpresstion, PostfixExpresstion);

	Result = Calculate(PostfixExpresstion);

	printf("Calculation Result : %f\n", Result);

	return 0;
}