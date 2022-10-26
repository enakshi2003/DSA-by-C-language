#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void peek();

struct node
{
    int data;
    struct node *next;
};
struct node *top;
int main()
{
    int choice;
    do
    {
        printf("\nEnter one of the stack operations:\n");
        printf("1. Push elements in stack\n");
        printf("2. Pop elements from stack\n");
        printf("3. Display elements of stack\n");
        printf("4. Print the top-most element of stack\n");
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
                pop();
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
                printf("Exited successfully\n");
                exit(0);
                break;
            }
            default:
            {
                printf("Enter the valid point\n");
            }
        }
    } while (choice!=5);    
}
void push()
{
    struct node *ptr;
    int val;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&val);
    if(top==NULL)
    {
        top=ptr;
        ptr->data=val;
        ptr->next=NULL;
        printf("Node pushed successfully\n");
    }
    else
    {
        ptr->data=val;
        ptr->next=top;
        top=ptr;
        printf("Node pushed successfully...\n");
    }
}
void pop()
{
    struct node *ptr;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        ptr=top;
        top=top->next;
        free(ptr);
        printf("Node deleted successfully\n");
    }
}
void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack in empty\n");
    }
    else
    {
        temp=top;
        printf("Printing...\n\n");
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
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The top-most element in stack is : %d\n",top->data);
    }
}