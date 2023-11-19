#include<stdio.h>

int main(void)
{
	int n=0, t=0;
	scanf("%d%d", &n, &t);
	double coin[100][3]={0};
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf", &coin[i][0], &coin[i][1]);//mass value
		coin[i][2]=coin[i][1]/coin[i][0];//price
	}
	
	int index[100]={0};//sort
	for(i=0;i<n;i++)
	{
		index[i]=i;
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(coin[index[i]][2]<coin[index[j]][2])
			{
				index[i]+=index[j];
				index[j]=index[i]-index[j];
				index[i]-=index[j];
			}
		}
	}
	
//test
/*	for(i=0;i<n;i++)
	{
		printf("%d ",index[i]);
	}*/

	double result=0;
	i=0;
	while(t>coin[index[i]][0])
	{
		result+=coin[index[i]][1];
		t-=coin[index[i]][0];
		i++;
		if(i>n-1)
		{
			break;
		}
	}
	if(t>0&&i<n)
	{
		result+=coin[index[i]][2]*t;
	}
	printf("%.2lf\n", result);

	return 0;
}
