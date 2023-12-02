#include <stdio.h>

#define PrintArr(arr, len)        \
    for (int i = 0; i < len; i++) \
    printf("%d ", arr[i])

void fun1(int arr[], int len);
void fun2(int *arr, int len);
void fun3(const int arr[], int len);

void fun1(int arr[], int len)
{
    printf("size of arr is %d\n", sizeof(arr));

    for (int i = 0; i < len; i++)
    {
        arr[i] = i;
    }
}

void fun2(int *arr, int len)
{
    printf("size of arr is %d\n", sizeof(arr));

    for (int i = 0; i < len; i++)
        arr[i] = 2 * i;
}

// void fun3(const int arr[], int len)
// {
//     printf("size of arr is %d\n", sizeof(arr));

//     fun2(arr, len);
// for (int i = 0; i < len; i++)
//     arr[i] = 3 * i;
// }

int main()
{
    int a[5] = {1, 1, 1, 1, 1};
    printf("size of a is %d\n", sizeof(a));
    fun1(a, 5);
    PrintArr(a, 5);
    fun2(a, 5);
    PrintArr(a, 5);
}
