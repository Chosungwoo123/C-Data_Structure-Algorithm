// C언어로 구현한 버블 정렬

#include <stdio.h>

void BubbleSort(int DataSet[], int Length);

int main(int argc, char* argv[])
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	BubbleSort(DataSet, Length);

	printf("> BubbleSort\n");

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	return 0;
}

void BubbleSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < Length - 1; i++)
	{
		for (j = 0; j < Length - (i + 1); j++)
		{
			if (DataSet[j] > DataSet[j + 1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}