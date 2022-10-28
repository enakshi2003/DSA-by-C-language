#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
void peek();
int queue[100];
int front=-1;
int rear=-1;
int size;
int main()
{
    int choice;
    printf("How many elements you want to insert\n");
    scanf("%d",&size);
    do
    {
        printf("\nEnter one of the operation of queue\n");
        printf("1. Enqueue (Insert value into queue)\n");
        printf("2. Dequeue (Delete value from queue)\n");
        printf("3. Display the elements from queue\n");
        printf("4. Which element is at front right now?\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5:
            {
                printf("Exiting...\n");
                exit(0);
                break;
            }
            default:
            {
                printf("Enter valid option\n");
            }
        }
    }while(choice!=5);
}
void enqueue()
{
    int val;
    printf("Enter the value to be inserted\n");
    scanf("%d",&val);
    if(rear==(size-1))
    {
        printf("Overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=val;
        printf("Element inserted Successfully...\n");
    }
    else
    {
        rear++;
        queue[rear]=val;
        printf("Element inserted Successfully\n");
    }
}
void dequeue()
{
    int val;
    if(front==-1 || front>rear)
    {
        printf("Underflow\n");
    }
    else
    {
        val=queue[front];
        printf("%d value is deleted successfully\n",val);
        front++;
    }
}
void display()
{
    int loc;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Printing...\n");
        for(loc=front;loc<=rear;loc++)
        {
            printf("%d\t",queue[loc]);
        }
    }
}
void peek()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d is now at front\n",queue[front]);
    }
}