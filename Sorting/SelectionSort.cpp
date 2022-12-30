#include<stdio.h>
int selectionSort(int a[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
}
int main()
{
    int a[100];
    int n,i;
    printf("How many number you want to insert?\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}