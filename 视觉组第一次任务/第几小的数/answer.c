#include<stdio.h>
#include<stdlib.h>

int num[5000]={0}, m=0;

void special_sort(int left, int right);

int main(void)
{
	int n=0;
	scanf("%d%d", &n, &m);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d", &num[i]);
	}
	special_sort(0, n-1);
	return 0;
}

void special_sort(int left, int right)
{
	int i=left, j=right, mid=num[(left+right)/2];
	do
	{
		while(num[j]>mid)
		{
			j--;
		}
		while(num[i]<mid)
		{
			i++;
		}
		if(i<=j)
		{
			int temp=num[i];
			num[i]=num[j];
			num[j]=temp;
			i++;
			j--;
		}
	}
	while(i<=j);
	
	if(m<=j)
	{
		special_sort(left, j);
	}
	else if(i<=m)
	{
		special_sort(i, right);
	}
	else
	{
		printf("%d",num[j+1]);
		exit(0);
	}
}
