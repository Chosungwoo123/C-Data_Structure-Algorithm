// ����Ʈ���� Ȱ���� ����

#include "ExpressionTree.h"

int main(int argc, char* argv[])
{
	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	// Ʈ�� ���
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

	// Ʈ�� �Ҹ��Ű��
	ET_DestoryTree(Root);

	return 0;
}