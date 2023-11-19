#include<stdio.h>

//计算数字位数 
int ws(int a)
{
	int w=0;
	while(a!=0)
	{
		a/=10;
		w++;
	}
	return w;
}

//质数筛（埃筛） 
int prm(int a)
{
	int i=0;
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
		return 1;
	}
}

int main(void)
{
	int i=0;
	int a = 5, b = 100000000;
	scanf("%d %d", &a, &b);

	//生成回文数，并存储其中质数 
	int min=ws(a), max=ws(b);
	int d1=1, d2=0, d3=0, d4=0;
	int p1[3]={5,7,0};
	int p2[2]={11,0};
	int p3[50]={0};
//	int p4[50]={0};
	int p5[500]={0};
//	int p6[500]={0};
	int p7[5000]={0};
//	int p8[5000]={0};
	int t=0;
	i=0;
	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			t=d1*100+d2*10+d1;
			if(prm(t))
			{
				p3[i]=t;
				i++;
			}
		}
	}
/*	i=0;
	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			t=d1*1000+d2*100+d2*10+d1;
			if(prm(t))
			{
				p4[i]=t;
				i++;
			}
		}
	}*/
	i=0;
	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			for(d3=0;d3<=9;d3++)
			{
				t=d1*10000+d2*1000+d3*100+d2*10+d1;
				if(prm(t))
				{
					p5[i]=t;
					i++;
				}
			}
		}
	}
/*	i=0;
	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			for(d3=0;d3<=9;d3++)
			{
				t=d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;
				if(prm(t))
				{
					p6[i]=t;
					i++;
				}
			}
		}
	}*/
	i=0;
	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			for(d3=0;d3<=9;d3++)
			{
				for(d4=0;d4<=9;d4++)
				{
					t=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
					if(prm(t))
					{
						p7[i]=t;
						i++;
					}
				}
			}
		}
	}
	i=0;
/*	for(d1=1;d1<=9;d1+=2)
	{
		for(d2=0;d2<=9;d2++)
		{
			for(d3=0;d3<=9;d3++)
			{
				for(d4=0;d4<=9;d4++)
				{
					t=d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;
					if(prm(t))
					{
						p8[i]=t;
						i++;
					}
				}
			}
		}
	}*/
	
	//根据范围输出 
	int *p=0;
	switch(min)
	{
		case 1:
			for(p=p1;*p!=0;p++)
			{
				if(*p<a)
				continue;
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==1)
				break;
		case 2:
			for(p=p2;*p!=0;p++)
			{
				if(*p<a)
				continue;
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==2)
				break;
		case 3:
			for(p=p3;*p!=0;p++)
			{
				if(*p<a)
				continue;
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==3)
				break;
		case 4:
/*			for(p=p4;*p!=0;p++)
			{
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==4)
				break;*/
		case 5:
			for(p=p5;*p!=0;p++)
			{
				if(*p<a)
				continue;
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==5)
				break;
		case 6:
/*			for(p=p6;*p!=0;p++)
			{
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==6)
				break;*/
		case 7:
			for(p=p7;*p!=0;p++)
			{
				if(*p<a)
				continue;
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==7)
				break;
/*		case 8:
			for(p=p8;*p!=0;p++)
			{
				if(*p>b)
				break;
				printf("%d\n",*p);
			}
			if(max==8)
				break;*/
	}
	return 0;
}
