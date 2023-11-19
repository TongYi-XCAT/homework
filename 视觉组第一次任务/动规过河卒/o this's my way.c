#include<stdio.h>

int checkerboard[21][21]={0};

int main(void)
{
//draw board
	int i=0, j=0;
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			checkerboard[i][j]=1;
		}
	}
	int fin_x=0, fin_y=0, set_x=0, set_y=0;
	scanf("%d%d%d%d", &fin_x, &fin_y, &set_x, &set_y);
	checkerboard[set_x][set_y]=0;
	if(set_x-1>=0&&set_x-1<=20&&set_y-2>=0&&set_y-2<=20)
	{
		checkerboard[set_x-1][set_y-2]=0;
	}
	if(set_x-2>=0&&set_x-2<=20&&set_y-1>=0&&set_y-1<=20)
	{
		checkerboard[set_x-2][set_y-1]=0;
	}
	if(set_x+1>=0&&set_x+1<=20&&set_y-2>=0&&set_y-2<=20)
	{
		checkerboard[set_x+1][set_y-2]=0;
	}
	if(set_x+2>=0&&set_x+2<=20&&set_y-1>=0&&set_y-1<=20)
	{
		checkerboard[set_x+2][set_y-1]=0;
	}
	if(set_x-1>=0&&set_x-1<=20&&set_y+2>=0&&set_y+2<=20)
	{
		checkerboard[set_x-1][set_y+2]=0;
	}
	if(set_x-2>=0&&set_x-2<=20&&set_y+1>=0&&set_y+1<=20)
	{
		checkerboard[set_x-2][set_y+1]=0;
	}
	if(set_x+1>=0&&set_x+1<=20&&set_y+2>=0&&set_y+2<=20)
	{
		checkerboard[set_x+1][set_y+2]=0;
	}
	if(set_x+2>=0&&set_x+2<=20&&set_y+1>=0&&set_y+1<=20)
	{
		checkerboard[set_x+2][set_y+1]=0;
	}

//test
/*	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			printf("%d ", checkerboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

//draw way
	long long way[21][21]={0};
	way[0][0]=1;

	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			if(checkerboard[i][j]==0)
			{
				way[i][j]=0;
			}
			else
			{
				if(i-1>=0)
				{
					way[i][j]+=way[i-1][j];
				}
				if(j-1>=0)
				{
					way[i][j]+=way[i][j-1];
				}
			}
		}
	} 

//test
/*	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			printf("%lld ", way[i][j]);
		}
		printf("\n");
	}*/

	printf("%lld", way[fin_x][fin_y]);

	return 0;
}

//bug:19 19 1 0 2203961430, 
