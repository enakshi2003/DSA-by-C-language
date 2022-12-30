#include<stdio.h>
void bubbleSort(int arr[],int n)
{
    int temp=0;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }   
    }
}
int main()
{
    int arr[100];
    int n,i;
    printf("How many numbers you want to insert\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]= \n",i);
        scanf("%d",&arr[i]);   
    }
    bubbleSort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]= %d\n",i,arr[i]);
    }
}
