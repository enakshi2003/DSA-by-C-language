#include<stdio.h>
#include<stdlib.h>
void push();
void display();
void pop();
void peek();
int stack[100],n;
int top=-1;
int main()
{
    int choice;
    printf("\nHow many memory you want to allocate?\n");
    scanf("%d",&n);
    do
    {
        printf("Enter one of the stack operations:\n");
        printf("1. Push elements in stack\n");
        printf("2. Display elements of stack\n");
        printf("3. Pop elements from stack\n");
        printf("4. Print the top most element of stack\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5:
            {
                printf("Exit point\n");
                exit(0);
                break;
            }
            default:
            {
                printf("Enter valid option\n");
            }
        }
    } while (choice!=5);
    
}
void push()
{
    int x;
    printf("Which value you want to posh?\n");
    scanf("%d",&x);
    if(top>=(n-1))
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=x;
        printf("Element pushed successfully\n");
    }
}
void display()
{
    int loc;
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing...\n");
        for(loc=top;loc>=0;loc--)
        {
            printf("%d\n",stack[loc]);
        }
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        int item;
        item=stack[top];
        printf("%d element is popped\n",item);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The top-most element of the stack is : %d\n",stack[top]);
    }
}