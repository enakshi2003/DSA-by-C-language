#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
void peek();

struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
int main()
{
    int choice;
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
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter value to be inserted\n");
    scanf("%d",&val);
    ptr->data=val;
    if(ptr==NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        if(front==NULL && rear==NULL)
        {
            front=ptr;
            rear=ptr;
            ptr->next=NULL;
            printf("Node inserted successfully...\n");
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
            printf("Node inserted successfully\n");
        }
    }
}
void dequeue()
{
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
        printf("Node deleted successfully\n");
    }
}
void display()
{
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty...\n");
    }
    else
    {
        printf("Printing...\n");
        temp=front;
        while(temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void peek()
{
    struct node *ptr;
    if(front==NULL)
    {
        printf("Queue is empty!!!\n");
    }
    else
    {
        ptr=front;
        printf("%d is now at front\n",ptr->data);
    }
}