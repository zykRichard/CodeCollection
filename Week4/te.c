#include <stdio.h>
#include <math.h>
int map[653][653];
int tmp, sum, x, y;
void solve(int n, int m, int d)
{
    for (int i = 51; i <= 50 + n; i++)
    {
        int j;
        if (i % 2 == 1)
        {
            tmp = 0;
            for (j = 51; j <= 50 + m; j++)
            {
                for (int dy = -d; dy <= d; dy++)
                {
                    int dx = d - abs(dy);
                    tmp = tmp - map[i + dy][j - dx] + map[i + dy][j + 1 + dx];
                }
                if (tmp > 0)
                {
                    sum += tmp;
                    y = i;
                    x = j + 1;
                }
            }
        } // 奇数行从左往右更新sum；
        if (i % 2 == 0)
        {
            tmp = 0;
            for (j = 51 + m; j >= 51; j++)
            {
                for (int dy = -d; dy <= d; dy++)
                {
                    int dx = d - abs(dy);
                    tmp = tmp + map[i + dy][j - 1 - dx] - map[i + dy][j + dx];
                }
                if (tmp > 0)
                {
                    sum += tmp;
                    y = i;
                    x = j - 1;
                }
            }
        } // 偶数行从右往左更新sum；
        tmp = 0;
        for (int dx = -d; dx <= d; dx++)
        {
            int dy = d - abs(dx);
            tmp = tmp + map[i + 1 + dy][j + dx] - map[i - dy][j + dx];
        }
        if (tmp > 0)
        {
            sum += tmp;
            y = i + 1;
            x = j;
        } // 下移更新sum；
    }
}
int main()
{
    int n, m, d, sum = 0;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 51; i <= 51 + n; i++)
    {
        for (int j = 51; j <= 51 + m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for (int dx = -d; dx <= d; dx++)
    {
        for (int dy = -d; dy <= d; dy++)
        {
            if (abs(dx) + abs(dy) <= d)
                sum += map[51 + dy][51 + dx];
        }
    }
    solve(n, m, d);
    printf("%d 1\n%d %d\n", sum, x, y);
}

