// C언어로 구현한 삽입정렬

#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length);

int main(int argc, char* argv[])
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	InsertionSort(DataSet, Length);

	printf("> InsertionSort\n");

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	return 0;
}

void InsertionSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 1; i < Length; i++)
	{
		if (DataSet[i - 1] <= DataSet[i])
		{
			continue;
		}

		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j] > value)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}