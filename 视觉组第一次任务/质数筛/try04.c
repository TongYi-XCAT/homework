#include<stdio.h>

int prm(int a)
{
	unsigned int i=0;
	if(a<2)
	{
		return 0;
	}
	else
	{
		for(i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int main(void)
{
	unsigned int a[100]={0}, n=0;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<n;i++)
	{
		if(prm(a[i]))
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}
