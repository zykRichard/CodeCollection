#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int rowpos[10];
bool col[10];
bool ndiag[20]; // sum : row + col
bool pdiag[20]; // sub : row - col + n - 1
int cnt = 0;

void dfs(int row, int n)
{
    if (row == n)
    {
        cnt++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != rowpos[i])
                    printf(".");
                else
                    printf("Q");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !ndiag[i + row] && !pdiag[row - i + n - 1]) // 当前位置可以放
        {
            col[i] = true;
            ndiag[i + row] = true;
            pdiag[row - i + n - 1] = true;
            rowpos[row] = i;
            dfs(row + 1, n);
            // backtrace
            col[i] = false;
            ndiag[i + row] = false;
            pdiag[row - i + n - 1] = false;
        }
    }
    return;
}

int NQsolver(int n)
{
    dfs(0, n);
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    // printf("%d", NQsolver(n));
    NQsolver(n);
    return 0;
}

// if(A==B) printf("C是伪币");
// else {
//     if(A==C) printf("")
// }
