//mat from 0 to n*n

#include<stdio.h>

void mcy(int n, int *a, int *b)
{
	int i=0,j=0;
	for(i=n;i<n*2;i++)
	{
		for(j=n;j<n*2;j++)
		{
			*(b+i*2*n+j)=*(a+(i-n)*n+(j-n));
		}
	}
	for(i=n;i<n*2;i++)
	{
		for(j=0;j<n;j++)
		{
			*(b+i*2*n+j)=*(a+(i-n)*n+j);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=n;j<n*2;j++)
		{
			*(b+i*2*n+j)=*(a+i*n+(j-n));
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(b+i*2*n+j)=0;
		}
	}
}

int main(void)
{
	int n=0;
	scanf("%d",&n);
	int m=1,i=0,j=0;
	for(i=0;i<n;i++)
		 m*=2;
	int mat[m][m];
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			mat[i][j]=1;
	int t=m,s=0;
	while(t)
	{
		
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-1;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("%d",mat[i][j]);
		printf("\n");
	}
	return 0;
}
