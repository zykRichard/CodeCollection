#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define NextPowerOfTwo(n)   \
    {                       \
        unsigned int v = n; \
        v--;                \
        v |= v >> 1;        \
        v |= v >> 2;        \
        v |= v >> 4;        \
        v |= v >> 8;        \
        v |= v >> 16;       \
        v++;                \
        n = v;              \
    }
#define Check(cur)            \
    if (cur == NULL)          \
    {                         \
        printf("alloc fail"); \
        assert(0);            \
    }

typedef struct block
{
    int sz;
    int id;
    struct block *next;
    struct block *prev;
} block;

int BlockCnt = 0;
block *head = NULL;

int GetPowerTwo(int n)
{
    int cnt = 0, base = 1;
    while (base < n)
    {
        cnt++;
        base = base << 1;
    }
    return cnt;
}

void InitBuddy(int n)
{
    head = (block *)malloc(sizeof(block));
    head->sz = n;
    head->id = 0;
    head->next = NULL;
    head->prev = NULL;
    BlockCnt = 1;
}

void QuerySolver()
{
    block *cur = head;
    printf("%d\n", BlockCnt);
    while (cur)
    {
        printf("%d ", cur->id);
        cur = cur->next;
    }
}

void alloc(int n, int id)
{

    int target = GetPowerTwo(n);
    block *cur = head;
    // while (cur && (cur->sz < target))
    //     cur = cur->next;

    // Check(cur);

    // while (cur && (cur->sz == target))
    // {
    //     if (cur->id == 0)
    //     {
    //         cur->id = id;
    //         return;
    //     }
    //     cur = cur->next;
    // }

    // Check(cur);

    // // find the first FREE block which has the size larger than target
    // while (cur && (cur->id != 0))
    //     cur = cur->next;

    // Check(cur);
    while (cur && (cur->sz < target || cur->id != 0))
        cur = cur->next;
    // cur -> sz > target:
    int newsz = cur->sz;

    // alloc new block
    // adapt sz = cur -> sz - 1
    while (newsz > target)
    {
        newsz--;
        cur->sz = cur->sz - 1;
        block *newblock = (block *)malloc(sizeof(block));
        BlockCnt++;
        newblock->id = 0;
        newblock->sz = newsz;
        newblock->next = cur;
        newblock->prev = cur->prev;

        if (cur->prev)
            cur->prev->next = newblock;
        cur->prev = newblock;

        cur = newblock;
    }

    cur->id = id;
    if (cur->prev == NULL)
        head = cur;
}

int main()
{
    int n, T;
    scanf("%d%d", &n, &T);
    InitBuddy(n);
    while (T--)
    {
        char newline = getchar();
        char op;
        scanf("%c", &op);
        if (op == 'Q')
            QuerySolver();
        else if (op == 'A')
        {
            int id, sz;
            scanf("%d%d", &id, &sz);
            alloc(sz, id);
        }
    }
    return 0;
}
