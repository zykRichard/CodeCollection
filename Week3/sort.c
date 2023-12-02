#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

int oldarec[100001];
int newarec[100001];
void BubbleSort(int *a, int n);
void InsertSort(int *a, int n);
void SelectionSort(int *a, int n);
void MergeSort(int *a, int n);
void QuickSort(int *a, int n);

void check(int *oldarr, int *arr, int n)
{ // check for consistency:
	memset(oldarec, 0, sizeof(oldarec));
	memset(newarec, 0, sizeof(newarec));
	for (int i = 0; i < n; i++)
	{
		oldarec[oldarr[i]]++;
		newarec[arr[i]]++;
	}

	for (int i = 0; i < 100001; i++)
		if (oldarec[i] != newarec[i])
		{
			printf(RED "Check Fail!\n" NONE);
			return;
		}
	int flag = 1;
	for (int i = 1; i < n; i++)
		if (arr[i] < arr[i - 1])
		{
			flag = 0;
			break;
		}
	if (flag)
		printf(GREEN "Check Pass!\n" NONE);
	else
		printf(RED "Check Fail!\n" NONE);
}

void generateTestCases(int n)
{
	FILE *file = fopen("test.txt", "w");

	if (file == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			fprintf(file, "%d ", rand() % 100000);
		}
		fprintf(file, "\n");
	}

	fclose(file);
}

int main()
{
	generateTestCases(100);

	FILE *file = fopen("test.txt", "r");

	if (file == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	int testCase[1005];
	int testCaseCount = 0;

	while (fscanf(file, "%d", &testCase[testCaseCount]) == 1)
	{
		++testCaseCount;

		if (testCaseCount == 1000)
		{
			int *TestBuffer = malloc(sizeof(testCase));
			memcpy(TestBuffer, testCase, sizeof(testCase));

			// What Sort

			check(TestBuffer, testCase, 1000);
			free(TestBuffer);
			testCaseCount = 0;
		}
	}

	fclose(file);
	return 0;
}

void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			// 如果相邻元素逆序，则交换它们
			if (a[j] > a[j + 1])
			{
				// 通过异或运算实现两数交换，不引入额外变量
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void InsertSort(int *a, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		// 将比 key 大的元素向后移动
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void SelectionSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		int temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *a, int low, int high)
{
	int pivot = a[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[i + 1], &a[high]);
	return i + 1;
}

void quickSort(int *a, int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);

		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

void QuickSort(int *a, int n)
{
	quickSort(a, 0, n - 1);
}
