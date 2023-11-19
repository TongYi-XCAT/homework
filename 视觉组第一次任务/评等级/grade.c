#include<stdio.h>

struct grd
{
	int nu;
	double g1;
	double g2;
};

int main(void)
{
	int n=0;
	scanf("%d",&n);
	struct grd g[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&g[i].nu);
		scanf("%lf",&g[i].g1);
		scanf("%lf",&g[i].g2);
	}
	for(i=0;i<n;i++)
	{
		if(g[i].g1+g[i].g2>140&&g[i].g1*7+g[i].g2*3>=800)
			printf("Excellent\n");
		else
			printf("Not excellent\n");
	}
	return 0;
}
