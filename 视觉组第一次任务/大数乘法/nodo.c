#include<stdio.h>

int a[4000]={0}, b[4000]={0}, d[4000]={0};

void multiply(int a[], int na, int b[], int nb);
void carry(int a[], int n);

int main(void)
{
	int n=0, i=0, c[2]={0};
	do
	{
		scanf("%c",&n);
		//n=getchar()-48;
		a[i]=n-48;
		i++;
	}
	while(a[i-1]!='\n'-48);
	a[i-1]=0;
	c[0]=i-1;
	i=0;
	do
	{
		scanf("%c",&n);
		//n=getchar()-48;
		b[i]=n-48;
		i++;
	}
	while(b[i-1]!='\n'-48);
	b[i-1]=0;
	c[1]=i-1;
	
/*	for(i=0;i<c[0];i++)
	{
		printf("%d",a[i]);
	}*/
	
	multiply(a, c[0], b, c[1]);
	carry(d, c[0]+c[1]);
	
	/*int *p=d;
	while(*p==0)
	{
		p++;
	}*/
	
	i=0;
	while(d[i]==0)
	{
		i++;
		if(i==4000)
		{
			break;
		}
	}
	if(i==4000)
	{
		printf("0");
	}
	for(;i<4000;i++)
	{
		printf("%d",d[i]);
	}
	
	
	return 0;
}

void multiply(int a[], int na, int b[], int nb)
{
	int i=0, j=0;
	for(i=na-1;i>=0;i--)
	{
		for(j=nb-1;j>=0;j--)
		{
			d[3999-(na+nb-2-i-j)]+=b[j]*a[i];//from the last number to the first number
		}
	}
}

void carry(int a[], int na)
{
	int i=0;
	for(i=3999;i>=4000-na;i--)//need debug( ok
	{
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
}
