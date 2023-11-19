#include<stdio.h>

int f(n)
{
	int i=1;
	for(i=1;n>1;n--)
		i*=n;
	return i;
}

void ppt(int n, int k, int b[], int c[], int *a)
//n is n!, k is the column need write, b[] c[] used to chose number, a[] use to put answer
{
	int i=0, j=0;
	if(n==0)//can i reset c[] ?
	{
		for(i=0;i<n;i++)
		{
			c[i]=0;
		}
		return;
	}
	else
	{
		for(i=0;i<n+k;i++)//there is a bug! 
		{
			for(j=0;j<f(n-1);j++)
			{
				if(!c[i])
				{
//					a[j+i*f(n-1)][k]=b[i];
					*(a+(j+i*f(n-1))*(k+n)+k)=b[i];//k+n=n(in the 'main'); i=circle number=the numer row nmber need plus
					c[i]=1;
					ppt(n-1, k+1, b, c, a);
				}
			}
		}
	}
}

int main(void)
{
	int n=0;
	scanf("%d",&n);
	int m=f(n);
	int a[m][n];
	int i=0, j=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}

	int b[n], c[n];
	for(i=0;i<n;i++)
	{
		b[i]=i+1;
		c[i]=0;
	}

	ppt(n, 0, b, c, a);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("%d",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
