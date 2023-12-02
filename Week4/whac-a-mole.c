#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int anscnt = 0;
int maxcnt = -99999;
int StoreX[360000];
int StoreY[360000];

int map[701][701];

int Left2Right(int initval, int row, int m, int d)
{
    int tmp = initval;
    for (int col = 1; col < m; col++)
    {
        for (int dy = -d; dy <= d; dy++)
        {
            int dx = d - abs(dy);
            tmp = tmp - map[row + dy + d][col - 1 - dx + d] + map[row + dy + d][col + dx + d];
        }
        if (tmp > maxcnt)
        {
            maxcnt = tmp;
            anscnt = 0;
            StoreX[anscnt] = row + 1;
            StoreY[anscnt] = col + 1;
            anscnt++;
        }
        else if (tmp == maxcnt)
        {
            StoreX[anscnt] = row + 1;
            StoreY[anscnt] = col + 1;
            anscnt++;
        }
    }
    return tmp;
}

int Right2Left(int initval, int row, int m, int d)
{
    int tmp = initval;
    for (int col = m - 2; col >= 0; col--)
    {
        for (int dy = -d; dy <= d; dy++)
        {
            int dx = d - abs(dy);
            // tmp = tmp - map[row + dy + d][col - 1 - dx + d] + map[row + dy + d][col + dx + d];
            tmp = tmp - map[row + dy + d][col + 1 + dx + d] + map[row + dy + d][col - dx + d];
        }
        if (tmp > maxcnt)
        {
            maxcnt = tmp;
            anscnt = 0;
            StoreX[anscnt] = row + 1;
            StoreY[anscnt] = col + 1;
            anscnt++;
        }
        else if (tmp == maxcnt)
        {
            StoreX[anscnt] = row + 1;
            StoreY[anscnt] = col + 1;
            anscnt++;
        }
    }
    return tmp;
}

int Descent(int row, int n, int m, int d, int oldinitval)
{
    int tmp = oldinitval;
    if (row == n - 1)
        return tmp; // 结束
    else if (row % 2 == 0)
    { // 最右边下降
        for (int dx = -d; dx <= d; dx++)
        {
            int dy = d - abs(dx);
            tmp = tmp - map[row - dy + d][m - 1 + dx + d] + map[row + 1 + dy + d][m - 1 + dx + d];
        }
    }
    else if (row % 2 == 1)
    { // 最左边下降
        for (int dx = -d; dx <= d; dx++)
        {
            int dy = d - abs(dx);
            tmp = tmp - map[row - dy + d][dx + d] + map[row + 1 + dy + d][dx + d];
        }
    }
    if (tmp > maxcnt)
    {
        maxcnt = tmp;
        anscnt = 0;
        StoreX[anscnt] = row + 1;
        StoreY[anscnt] = (row % 2 == 0) ? m : 1;
        anscnt++;
    }
    else if (tmp == maxcnt)
    {
        StoreX[anscnt] = row + 1;
        StoreY[anscnt] = (row % 2 == 0) ? m : 1;
        anscnt++;
    }

    return tmp;
}

void solver(int n, int m, int d)
{
    int LoopInit = 0;
    for (int i = d + 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            LoopInit += map[d + 1 - i + d][d + j];

    for (int row = 0; row < n; row++)
    {
        if (row % 2 == 0)
            LoopInit = Left2Right(LoopInit, row, m, d);
        else
            LoopInit = Right2Left(LoopInit, row, m, d);
        LoopInit = Descent(row, n, m, d, LoopInit);
    }
}

int main()
{
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i + d][j + d]);

    solver(n, m, d);
    printf("%d %d\n", maxcnt, anscnt);
    for (int i = 0; i < anscnt; i++)
        printf("%d %d\n", StoreX[i], StoreY[i]);

    return 0;
}
