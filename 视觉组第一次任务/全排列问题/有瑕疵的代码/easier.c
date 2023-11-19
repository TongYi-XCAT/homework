#include<stdio.h>

int f(n)
{
	int i=1;
	for(i=1;n>1;n--)
		i*=n;
	return i;
}

int ppt(int n, int k, int b[], int c[])
{
	int i=0, j=0;
	if(n==0)
	{
		printf("\n");
		for(i=0;i<n+k;i++)
		{
			c[i]=0;
		}
		return;
	}
	else
	{
		for(i=0;i<n+k;i++)
		{
			if(!c[i])
			{
				printf("%5d",b[i]);
				ppt(n-1, k+1, b, c);
			}
		}
	}
}

int main(void)
{
	int n=0;
	scanf("%d",&n);
	int i=0;
	
	int b[n], c[n];
	for(i=0;i<n;i++)
	{
		b[i]=i+1;
		c[i]=0;
	}

	ppt(n, 0, b, c);

	return 0;
}
