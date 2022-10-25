#include<stdio.h>
#include<stdlib.h>
void creationNode();
void displayNode();
void insertAtfront();
void insertAtanypoint();
void insertAtMid();
void deleAtFront();
void deleAtanyPoint();
void insertionAtEnd();
void deletionAtEnd();
void deletionAtMid();
int countLengthList();
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
		printf("3. Insert at front\n");
		printf("4. Insert at any point\n");
		printf("5. Insertion at end\n");
		printf("6. Insert at middle\n");
		printf("7. Deletion at any point\n");
		printf("8. Delete at front\n");
		printf("9. Delete at end\n");
		printf("10. Delete at middle\n");
		printf("11. Exit\n");
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
			   insertAtfront();
			   break; 
			}
			case 4:
	        	{
	            	   insertAtanypoint();
			    break;   
	        	}
			case 5:
			{
				insertionAtEnd();
				break;	
			}
			case 6:
			{
				insertAtMid();
				break;
			}
			case 7:
			{
				deleAtanyPoint();
				break;
			}
			case 8:
			{
				deleAtFront();
				break;
			}
			case 9:
			{
				deletionAtEnd();
				break;
			}
			case 10:
			{
				deletionAtMid();
				break;
			}
			case 11:
			{
				printf("Exit point");
				exit(0);
				break;
			}
			default:
				printf("Enter valid input\n");	
		}
	}while(choice!=11);
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
void insertionAtEnd(){
	struct node *ptr,*temp;
	int val;
	temp=head;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		printf("Enter the value to be inserted:\n");
		scanf("%d",&val);
		ptr->data = val;
		if(ptr == NULL)
		{
			ptr -> next = NULL;
			head = ptr;
			printf("\nNode inserted");
		}
		else
		{
			temp = head;
			while (temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp->next = ptr;
			ptr->next = NULL;
			printf("\nNode inserted");
		}
	}
}
void insertAtMid()
{
	struct node *temp,*ptr;
	int val,loc;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted:\n");
	scanf("%d",&val);
	ptr->data=val;
	int count = countLengthList();
	if(head==NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		temp=head;
		for(loc=0;loc<count/2;loc++)
		{
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next=ptr;
	}
}

void insertAtfront()
{
    struct node*ptr;
    int val;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        printf("Enter the value to be inserted:\n");
        scanf("%d",&val);
        ptr->data = val;
        ptr->next=head;
        head=ptr;
        printf("Node inserted\n");
    }
}
void insertAtanypoint()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        printf("Enter the value to be inserted: \n ");
        scanf("%d",&item);
        ptr->data=item;
        printf("Enter the location you want to insert\n");
        scanf("%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("Can't insert\n");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("Node inserted\n");
    }
}
void deleAtFront()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("Nothing to delete\n");
	}
	else
	{
		ptr=head;
		head=head->next;
		free(ptr);
		printf("Node deleted...\n");
	}
}
void deleAtanyPoint()
{
	struct node *temp1,*temp;
	int item,loc,i;
	if(head==NULL)
	{
		printf("Nothing to be deleted\n");
	}
	else
	{
        printf("Enter the location you want to delete\n");
        scanf("%d",&loc);
	temp=head;
        for(i=0;i<loc;i++)
        {
	    temp1=temp;
            temp=temp->next;
            if(temp==NULL)
            {
                printf("Node is not present\n");
            }
        }
        temp1->next=temp->next;
        free(temp);
        printf("Node deleted !!!\n");
	}
}
void deletionAtEnd(){
	struct node *ptr,*temp;
	temp=head;
	if(head==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("Last node has been deleted\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		free(temp);
		printf("\nNode deleted...\n");
	}
}
void deletionAtMid()
{
	struct node *temp,*ptr;
	int loc;
	int count = countLengthList();
	if(head==NULL)
	{
		printf("Memory is empty\n");
	}
	else
	{
		temp=head;
		for(loc=0;loc<count/2;loc++)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;
		free(temp);
		printf("Node deleted successfully\n");
	}
}
int countLengthList()
{
	struct node *temp;
	int count=0;
	if(head==NULL)
	{
		count=0;
		//printf("Length of the Linked list is %d\n",count);
		return count;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			count++;
		}
		//printf("Length of the linked list is %d\n",count+1);
		return count;
	}
}
