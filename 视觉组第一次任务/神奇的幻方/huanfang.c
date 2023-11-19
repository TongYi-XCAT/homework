#include<stdio.h>

int main()
{
	int n = 0;
	int z[40][40] = { 0 };
	scanf("%d", &n);
	int i = 0, j = 0, m = 0;
	z[0][n / 2] = 1;
	i = 0, j = n / 2;

	for (m = 2; m <= (n * n); m++)
	{
		if (i == 0 && j != n - 1)
		{
			z[n - 1][j + 1] = m;
			i = n - 1, j = j + 1;
		}
		else if (i != 0 && j == n - 1)
		{
			z[i - 1][0] = m;
			i = i - 1, j = 0;
		}
		else if (i == 0 && j == n - 1)
		{
			z[i + 1][j] = m;
			i = i + 1, j = j;
		}
		else if (i != 0 && j != n - 1)
		{
			if (z[i - 1][j + 1] == 0)
			{
				z[i - 1][j + 1] = m;
				i = i - 1, j = j + 1;
			}
			else
			{
				z[i + 1][j] = m;
				i = i + 1, j = j;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			printf("%d ", z[i][j]);
		}
		printf("%d\n", z[i][j]);
	}
	return 0;
}
