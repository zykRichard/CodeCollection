#include <stdio.h>
#include <stdlib.h>

char state[101][101] = {0};
int N;
// N * N
// char grid[N][N]
void search(char grid[3][3], int i, int j)
{
    if (grid[i][j] == '1')
        state[i][j] = 1;
        if (i > 0)
            search(grid, i - 1, j);
        if (i < N - 1)
            search(grid, i + 1, j);
        if (j > 0)
            search(grid, i, j - 1);
        if (j < N - 1)
            search(grid, i, j + 1);
}
int numIsands(char grid[3][3])
{
    int t = 0;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '1' && state[i][j] == 0)
            {
                t++;
                if (i > 0)
                    search(grid, i - 1, j);
                if (i < N - 1)
                    search(grid, i + 1, j);
                if (j > 0)
                    search(grid, i, j - 1);
                if (j < N - 1)
                    search(grid, i, j + 1);
            }

            if (grid[i][j] == '1' && state[i][j] == 1)
            {
                if (i > 0)
                    search(grid, i - 1, j);
                if (i < N - 1)
                    search(grid, i + 1, j);
                if (j > 0)
                    search(grid, i, j - 1);
                if (j < N - 1)
                    search(grid, i, j + 1);
            }
        }
    }
    return t;
}

int main()
{
    char grid[3][3] = {
        {'1', '0', '1'},
        {'1', '0', '1'},
        {'1', '1', '1'}};
    N = 3;
    printf("%d", numIsands(grid));
    return 0;
}
