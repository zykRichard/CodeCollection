#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vis[10001];
int N;
int num[10001];
int FindandCheck()
{
	for (int i = 1; i <= N; i++)
		if (!vis[i])
			return i;
	return -1; // Failure!
}

void backtrace(int s)
{
	vis[s] = 0;
}

void dfs(int n)
{
	if (n == 0)
	{
		printf("\n");
		return;
	}

	while (1)
	{
		int s_next = FindandCheck();
		if (s_next > 0)
		{
			printf("%d ", s_next);
			vis[s_next] = 1;
			dfs(n - 1);
			backtrace(s_next);
		}

		else if (s_next == -1)
		{
			return;
		}
	}
}

void permutate(int n)
{
	if (n == 0)
	{
		for (int i = 0; i < N; i++)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}
	else
	{
		// int flag = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!vis[i])
			{
				num[N - n] = i;
				// flag = 1;
				vis[i] = 1;
				permutate(n - 1);
				vis[i] = 0;
			} // 下一个状态
		}
		// if (!flag)
		// 	return;
	}
}


void permutate2(int n){
	
	for(int i = 1; i <= N; i++){
		if(num[i]!= 0)
			{
			printf("%d ", i);
			num[i] = 0;
			permutate2(n - 1);
			num[i] = i;
			}
			
	}
}

int main()
{
	memset(vis, 0, sizeof(vis));
	N = 5;
	for(int i = 1; i <= N; i++)
		num[i] = i;
	permutate(5);
	return 0;
}
