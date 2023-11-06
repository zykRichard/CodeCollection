#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
typedef long long ll;

#define Traverse(arr, n)        \
    for (int i = 0; i < n; i++) \
    printf("%x ", arr[i])

#define Traversell(arr, n)      \
    for (int i = 0; i < n; i++) \
    printf("%lx ", arr[i])
// void *memset(void* str, int c, size_t n);
// void *malloc(size_t size);
void demo1();
void demo2();
void demo3();

int main(int argc, char *argv[], char *envp[])
{
    assert(argc > 1);
    if (strcmp("demo1", argv[1]) == 0)
    {
        demo1();
        printf("Return");
    }
    else if (strcmp("demo2", argv[1]) == 0)
        demo2();
    else if (strcmp("demo3", argv[1]) == 0)
        demo3();
    else
        assert(0);
}

// Comprehension of array memory arrangement
void demo1()
{
    int a[10] = {100, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {2, 3};

    char passwords[] = "dadadadad";

    // ....

    // int a[10] = {0, 1};
    // int *p = a; // (int *)

    // printf("address of a is %lx\n", a);
    // printf("address of a[1] is %lx\n", (void *)(a + 4));
    // int k = 4;
    // void *c = (void *)a + k; // void *c =  (void *)(int*)(a + 4)
    // printf("address of c is %lx\n", c);
    // assert(*(int *)c == a[1]);
    // assert(a[1] == *(a + 4));
    // printf("a[1] is %d\n", a[1]);
    // printf("a[1] is %d\n", *(a + 4));
    // printf("a[1] is %d\n", *(a + 1));
    // printf("a[1] is %d\n", *(p + 1));
    // printf("a[1] is %d\n", *(p + 4));

    // Type Cast to point
    // ll *pll = (ll *)a;
    // printf("What's that: %lx\n", *(pll + 1));

    // Out of Boundary Access:
    // Hacking

    // printf("b[10] is %d\n", b[10]);
    // assert(b[10] == 1);
    // printf("b[10] is %d\n", *(b + 10 * sizeof(int)));
    // int *k = b;
    // printf("b[10] is %d\n", *(k + 10));
    sleep(30);
    memset(b, 0, 10000);
    for (int i = 0; i < 10; i++)
        printf("a[%d] is %d\n", a[i]);
    // void memset(void *ptr, int n, size_t n);
}

// Value Assignment && Array Type Cast
void demo2()
{
    // int cards[4] = {3, 6, 8, 10}; //allowed
    // int hands[4];
    // hands = {5, 6, 7, 9}; // not allowed
    // int *k;
    // k = cards;
    // hands = cards; // not allowed

    char arrchar[3] = {1, 2, 3};
    char __arrchar[3] = {(char)257, (char)258, (char)259};
    // Traverse(__arrchar, 3);
    int arrint[3] = {100, 'c', 320};
    int __arrint[3] = {100, 'c', arrchar};
    // Traverse(__arrint, 3);
    ll arrll[3] = {100, ((ll)2) << 31, ((ll)2) << 63};
    ll __arrll[3] = {(ll)2 << 64, ((ll)2) << 65, __arrchar};
    Traversell(__arrll, 3);
}

// Memory Allocation
void demo3()
{
    int n;
    scanf("%d", &n);
    // int a[n];
    // int b[10];

    // void *malloc(size_t n);
    int *k = malloc(n * sizeof(int)); // k[n]

    int *p = malloc(20);
    // Traverse(k, n);
    // memset(b, 0, sizeof(b));
    // memset(k, 0, 4 * n);
    // Traverse(k, n);
    // memset(k, 1, 4 * n);
    // Traverse(k, n);
    // memset(k, 23456, 4 * n);
    // Traverse(k, n);
    memset(k, -1, 4 * n);
    Traverse(k, n);
}
