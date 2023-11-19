#include<stdio.h>

void print_x(int n);
void print_coe(int n);

int main(void)
{
	int n=0;
	scanf("%d",&n);
	int coe[200]={0}, i=0;
	for(i=0;i<=n;i++)
	{
		scanf("%d",&coe[i]);
	}
	int flag=1;//if only one number
	for(i=0;i<n;i++)
	{
		if(coe[i])//to find the first number and print
		{
			if(coe[i]!=1&&coe[i]!=-1)
			{
				printf("%d",coe[i]);
			}
			else if(coe[i]==-1)
			{
				printf("-");
			}
			print_x(n-i);
			i++;//to prepare for the #2
			flag=0;
			break;
		}
	}
	if(i==n&&flag==1)//if the first is the last 
	{
		printf("%d",coe[i]);
		i+=2;//to skip the fellow orders
	}
	
	//#2
	for(;i<=n;i++)//after the first number
	{
		if(coe[i])
		{
			print_coe(coe[i]);
			print_x(n-i);
		}
	}
	if(coe[i-1]==1||coe[i-1]==-1)
	{
		printf("1");
	}
	return 0;
}

void print_x(int n)
{
	if(n==0)
	{
		return;
	}
	else if(n==1)
	{
		printf("x");
	}
	else
	{
		printf("x^%d",n);
	}
}

void print_coe(int n)
{
	if(n==-1)
	{
		printf("-");
	}
	else if(n==1)
	{
		printf("+");
	}
	else
	{
		printf("%+d",n);
	}
} 
