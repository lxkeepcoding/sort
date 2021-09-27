#define _CRT_SECURE_NO_WARNINGS   1

#include"sort.h"

//打印
void ArrayPrint(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}


//插入排序
void InsertSort(int *a, int n)
{
		for (int i = 0; i < n - 1; ++i)
		{
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + 1] = a[end];
					--end;
				}
				else
				{
					break;
				}
			}
			a[end + 1] = tmp;
		}
}
//希尔排序
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3+1);
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int *a, int n)
{
	int left = 0, right = n - 1;
	int minIndex = left, maxIndex = right;
	while (left < right)
	{
		for (int i = left; i<= right; ++i)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);
		if (maxIndex == left)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}
//堆排序
void AdgustDwon(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a, int n)
{
	//升序，建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdgustDwon(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdgustDwon(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int *a, int n)
{
	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1]>a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}
//快速排序
int PartSortHoare(int *a,int left,int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left<right&&a[right]>=a[keyi])
			--right;
		while (left < right&&a[left] <= a[keyi])
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
int PartSortHole(int *a, int left, int right)
{
	int key = a[left];
	while (left < right)
	{
		while (left < right&&a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
		while (left < right&&a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
int PartSortPoint(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	int meeti = prev;
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]>a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left]<a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//void QuickSort(int *a, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	if (end - begin > 10)
//	{
//		//可换成另外两种方法
//		int keyi = PartSortPoint(a, begin, end);
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//	else
//	{
//		InsertSort(a + begin, end - begin + 1);
//	}
//}


void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	//可换成另外两种方法
	int keyi = PartSortPoint(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


//void QuickSortNonR(int* a, int left, int right)
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, left);
//	StackPush(&st, right);
//	while (StackEmpty(&st) != 0)
//	{
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//			int div = PartSort1(a, begin, end);
//		if (begin < div - 1)
//		{
//			StackPush(&st, begin);
//			StackPush(&st, div - 1);
//		}
//		if (div + 1 < end)
//		{
//			StackPush(&st, div + 1);
//			StackPush(&st, end);
//		}
//	}
//}

//归并排序
void _MergeSort(int *a,int left,int right,int *tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= right; ++j)
	{
		a[j] = tmp[j];
	}
}
void MergeSort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}

