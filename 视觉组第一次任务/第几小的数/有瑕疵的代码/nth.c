#include<stdio.h>

int num[5000]={0};

void special_quick_sort(int* start, int* end, int nth);

int main(void)
{
	int n=0, m=0;
	scanf("%d%d", &n, &m);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d", &num[i]);
	}
	
	special_quick_sort(num, num+n-1, m);
	
	return 0;	
}

void special_quick_sort(int* start, int* end, int nth)
{
	int *p1=0, *p2=0;
	int *set=0;
	int length=0;
	p1=start, p2=end-1, set=end;
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
	length=(set-1)-start+1;
	if(length==nth)
	{
		printf("%d", *set);
		return;
	}
	else if(length>nth)
	{
		special_quick_sort(start, set-1, nth);
		return;
	}
	else
	{
		special_quick_sort(set+1, end, nth-(length+1));
		return;
	} 
}
