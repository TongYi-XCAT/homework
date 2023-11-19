#include<stdio.h>

int n;
int b[100]={0}, a[100];

void print();
void DFScreat(int k);

int main(void)
{
	scanf("%d",&n);
	DFScreat(0);
	
	return 0;
}

void print()
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}

void DFScreat(int k)
{
	int i=0;
	if(k==n)
	{
		print();
		return;
	}
	for(i=0;i<n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			a[k]=i+1;
			DFScreat(k+1);
			b[i]=0;
		}
	}
}
