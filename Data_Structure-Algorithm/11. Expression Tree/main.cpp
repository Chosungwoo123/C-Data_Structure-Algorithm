// 수식트리를 활용한 계산기

#include "ExpressionTree.h"

int main(int argc, char* argv[])
{
	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	// 트리 출력
	printf("Preorder ...\n");
	ET_PreorderPrintTree(Root);
	printf("\n\n");

	printf("Inorder ...\n");
	ET_InorderPrintTree(Root);
	printf("\n\n");

	printf("Postorder ...\n");
	ET_PostorderPrintTree(Root);
	printf("\n");

	printf("Evaulation Result : %f \n", ET_Evaluate(Root));

	// 트리 소멸시키기
	ET_DestoryTree(Root);

	return 0;
}