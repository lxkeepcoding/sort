#define _CRT_SECURE_NO_WARNINGS   1

#include"sort.h"
void TestInsertSort()
{
	int a[] = { 1, 6, 2, 5, 9, 7, 0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9,1,2,4,3,8,5,6,0,7 };
	ShellSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestSelectSort()
{
	int a[] = { 4,8,6,7,9,3,2,5 };
	SelectSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestHeapSort()
{
	int a[] = {2,6,3,9,7,5,0,8};
	HeapSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestBubbleSort()
{
	int a[] = { 9, 3, 5, 8, 2, 4, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestQuickSort()
{
	int a[] = { 6, 3, 2, 1, 9, 7, 4, 5, 8 };
	QuickSort(a, 0,(sizeof(a) / sizeof(int)-1));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	MergeSort(a,sizeof(a) / sizeof(int));
	ArrayPrint(a, sizeof(a) / sizeof(int));
}
void TestIS()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	free(a1);
	free(a2);
}

int main()
{
	
	return 0;
}