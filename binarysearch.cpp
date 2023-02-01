#include<stdio.h>
int main()
{
	int a[12],n,i,j,hold=0,k,p,m;
	printf("How many numbers want to print?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	k=(n-1)/2;
	p=a[k];
	printf("which value you want to search?");
	scanf("%d",&m);
	if(m==a[k])
	{
		printf("%d that is the mid value, is found",m);
	}
	for(i=0;i<n;i++)
	{
		if(m>a[k])
		{
			k++;
			if(m==a[k])
			{ 
				printf("%d value is found\n",m);
			}
		}
		else if(m<a[k])
		{
			k--;
			if(m==a[k])
			{
			printf("%d value is found\n",m);
			}	
		}
	}	
}