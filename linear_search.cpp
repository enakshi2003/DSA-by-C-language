#include <stdio.h>
#include<conio.h>
void main()
{
 printf("enter the sixe of the array ");
 int b;
 scanf("%d",&b);
 int a[b],j, i=0,item;

 printf("enter the array elements ");
 for(j=0;j<b;j++)
 {
 scanf("%d",&a[j]);
 }
 printf("ente the searching item ");
 scanf("%d",& item);
 while(i<b)
 {
 if(a[i]==item)
 {
 printf("element is found & position is %d" ,i+1);
 break;
 }
 i++;
 }
 if(i>=b)
 printf("element not found ");
 getch();
}