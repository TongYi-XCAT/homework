#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[6][17]={'0'};
	char cmp[27][11]={"zero","one","two","three","four","five","six","seven","eight","nine", 
	"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen",
	"nineteen","twenty","a","both","another","first","second","third"};
	int cmn[27]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
	int i=0,j=0;
	for (i=0;i<6;i++)
	{
		scanf("%s", str[i]);
//		getchar();
	}
	int num[6]={0};
	int m=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<27;j++)
		{
			if(strcmp(str[i],cmp[j])==0)
			{
				num[m]=cmn[j];
				m++;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		num[i]=num[i]*num[i]%100;
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<m-i;j++)
		{
			if(num[j]>num[j+1])
			{
				num[j]=num[j]+num[j+1];
				num[j+1]=num[j]-num[j+1];
				num[j]=num[j]-num[j+1];
			}
		}
	}
	int result=0;
	for(i=0;i<=m;i++)
	{
		result=result*100+num[i];
	}
	printf("%d\n",result);
	return 0;
}
