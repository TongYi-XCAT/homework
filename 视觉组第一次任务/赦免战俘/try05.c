//i want to change mat from n*n to 2*2, but now i can't
//yes you can

#include<stdio.h>

void mch(int m, int n, int *a)
{
	int *p=0;
	if(n==2)
	{
		p=a;
		*p=0;
		*(p+1)=1;
		*(p+m)=1;
		*(p+m+1)=1;
	}
	else
	{
		for(p=a;p<a+m*n/2;p+=m)
		{
			int *i=p+n/2;
			for(;p<i;p++)
			{
				*p=0;
			}
			p=i-n/2;//reset
		}
		mch(m, n/2, a+n/2);
		mch(m, n/2, a+m*n/2);
		mch(m, n/2, a+m*n/2+n/2);
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
	int t=m;
	mch(m, t, mat);
	
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
