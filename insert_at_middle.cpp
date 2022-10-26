#include<stdio.h>
#include<stdlib.h>
void creationNode();
void displayNode();
void insertAtmid();
struct node
{
	int data;
	struct node *next;
};
struct node *head;
int main()
{
	int choice,ch;
	do
	{
		printf("Enter a choice: \n");
		printf("1. Creation\n");
		printf("2. Display\n");
		printf("3. Insert at middle\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
			    creationNode();
			    break;
			}
			case 2:
	        	{
	            	    displayNode();
			    break;
	        	}
			case 3:
			{
			   insertAtmid();
			   break; 
			}
			case 4:
			{
				printf("Exit point");
				exit(0);
				break;
			}
			default:
				printf("Enter valid input\n");	
		}
	}while(choice!=4);
}
void creationNode()
{
	struct node *ptr1,*temp;
	int value;
	ptr1 = (struct node*)malloc(sizeof(struct node));
	temp=head;
	printf("Enter the value: \n");
	scanf("%d",&value);
	ptr1->data=value;
	ptr1->next=NULL;
	if(head==NULL)
	{
		head=ptr1;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr1;
	}	
}
void displayNode()
{
	struct node *ptr;
	ptr = head;
	if(ptr->next==NULL)
	{
		printf("There is no node to display\n");
	}
	else
	{
		printf("\nPrinting...\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
            		ptr=ptr->next;
		}
	}
}
void insertAtmid()
{
    struct node*ptr;
    int val;
    struct node *temp;
    printf("Enter value to be inserted\n");
    scanf("%d",&val);
    struct node *slow=head;
    struct node *fast=head;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        temp=head;
        while(temp->next!=slow)
        {
            temp=temp->next;
        }
        ptr->data=val;
        ptr->next=slow;
        temp->next=ptr;
    }    
}
