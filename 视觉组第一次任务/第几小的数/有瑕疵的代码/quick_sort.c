#include<stdio.h>

int num[20]={0};

void sort(int* start, int* end, int length);

int main(void)
{
	int i=0; 
	for(i=0;i<20;i++)
	{
		num[i]=100-i;
		if(i==4)
		{
			num[i]=100;
		}
		printf("%d ",num[i]);
	}
	printf("\n\n");
	sort(num, num+19, 20);
	for(i=0;i<20;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n\n");
	return 0;
}

void sort(int* start, int* end, int length)
{
	int *p1=0, *p2=0;
	int* set=0;
	if(length==1||length==0)
	{
		return;
	}
	else
	{
		set=end;
		p1=start, p2=end-1;
		while(p1<p2)
		{
			if(*p1<*set&&p1<p2)
			{
				p1++;
			}
			if(*p2>*set&&p1<p2)
			{
				p2--;
			}
			if(*p1>=*set&&*p2<=*set&&p1<p2)
			{
				*p1=*p1+*p2;
				*p2=*p1-*p2;
				*p1=*p1-*p2;
			}
		}
		if(*p1>=*set)
		{
			*p1=*p1+*set;
			*set=*p1-*set;
			*p1=*p1-*set;
			set=p1;
		}
		else if((p1+1)!=set)
		{
			*(p1+1)=*(p1+1)+*set;
			*set=*(p1+1)-*set;
			*(p1+1)=*(p1+1)-*set;
			set=(p1+1);
		}
		else
		{
			set=(p1+1);
		}
		sort(start, set-1, (set-1)-start+1);
		sort(set+1, end, end-(set+1)+1);
	}
}
