// C언어로 구현한 퀵정렬 알고리즘

#include <stdio.h>
#include "Score.h"

void Swap(Score* A, Score* B);

int Partition(Score DataSet[], int Left, int Right);

void QuickSort(Score DataSet[], int Left, int Right);

int main(int argc, char* argv[])
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	QuickSort(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++)
	{
		printf("%d등 : %d번 %.2f점\t4", i + 1, DataSet[i].number, DataSet[i].score);
	}

	return 0;
}

void Swap(Score* A, Score* B)
{
	Score Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(Score DataSet[], int Left, int Right)
{
	int First = Left;
	Score Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		// 내림차순
		while (DataSet[Left].score >= Pivot.score && Left < Right)
			++Left;

		while (DataSet[Right].score <= Pivot.score && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(Score DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}