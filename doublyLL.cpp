#include<stdio.h>
#include<stdlib.h>
void deleAtFront();
void deletionAtanypoint();
void creationNode();
void displayNode();
void insertionAtFront();
void insertionAtanypoint();
void insertAtEnd();
void insertAtMid();
void deletionAtEnd();
void deletionAtMid();
int countLinkedList();
struct node
{
    int data;
    struct node*prev;
    struct node*next;
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
        	printf("3. insertion at front\n");
        	printf("4. Insertion at any point\n");
        	printf("5. Insertion at End\n");
        	printf("6. Insertion at middle\n");
        	printf("7. Delete at front\n");
        	printf("8. Delete at any point\n");
        	printf("9. Delete at End\n");
        	printf("10. Delete at middle\n");
        	printf("11. Exit point\n");
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
                	    insertionAtFront();
                	    break;
            		}
            		case 4:
            		{
                	    insertionAtanypoint();
                	    break;
            		}
            		case 5:
            		{
                	    insertAtEnd();
                	    break;
            		}
            		case 6:
            		{
                	    insertAtMid();
                	    break;
            		}
            		case 7:
            		{
                	    deleAtFront();
                	    break;
            		}
            		case 8:
            		{
                	    deletionAtanypoint();
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
    struct node*ptr,*temp;
    int val;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->next=NULL;
    printf("Enter value:\n");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        head=temp=ptr;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=NULL;
    }
    
}
void displayNode()
{
    struct node *ptr;
    printf("\nPrinting values...\n");
    ptr = head;
    if(ptr->next==NULL)
    {
        printf("No node to display\n");
    }
    while(ptr!= NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void insertionAtFront()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {   
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item value");
        scanf("%d",&item);
        if(head==NULL)
        {
            ptr->next= NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head=ptr;
        }
        else
        {
            ptr->data=item;  
            ptr->prev=NULL;
            ptr->next = head;
            head=ptr;
        }
        printf("\nNode inserted\n");
    }
}
void insertionAtanypoint()
{
    struct node *ptr,*temp,*temp1;
    int item,loc,i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp=head;
        printf("Enter the location");
        scanf("%d",&loc);
        for(i=0;i<loc-1;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value");
        scanf("%d",&item);
        ptr->data = item;
        temp1=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=temp1;
        printf("\nnode inserted\n");
    }
}
void insertAtEnd()
{
    struct node *ptr,*temp;
    int val;
    ptr=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(ptr==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        printf("Enter the value to be inserted:\n");
        scanf("%d",&val);
        ptr->data=val;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        ptr->next=NULL;
        printf("Node inserted...\n");
    }
}
void insertAtMid()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val,loc;
    printf("Enter the value you want to insert\n");
    scanf("%d",&val);
    ptr->data=val;
    int count=countLinkedList();
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
        ptr->prev=temp;
        temp->next->prev=ptr;
        printf("Node inserted successfully...\n");
    }
}
void deleAtFront(){
    struct node *temp;
    if(head==NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
        printf("Node deleted successfully\n");
    }
}
void deletionAtanypoint()
{
    struct node *ptr, *temp,*temp1;
    int loc,i;
    printf("Enter the location where we are going to delete node\n");
    scanf("%d",&loc);
    if(head==NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        temp=head;
        for(i=0;i<loc;i++)
        {
            ptr=temp;
            temp=temp->next;
        }
        temp1=temp->next;
        ptr->next=temp1;
        temp1->prev=ptr;
        printf("Node deleted successfully\n");   
    }
}
void deletionAtMid()
{
    struct node *ptr,*temp;
    int loc;
    int count=countLinkedList();
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
        temp->next->prev=ptr;
        free(temp);
        printf("Node deleted Successfully\n");
    }
}
void deletionAtEnd()
{
    struct node *temp,*ptr,*temp1;
    if(head==NULL)
    {
        printf("Nothing to be deleted\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        ptr=temp;
        temp1->next=NULL;
        free(ptr);
        printf("Node is deleted successfully\n");
    }
}
int countLinkedList()
{
    struct node*temp;
    int count=0;
    if(head==NULL)
    {
        count=0;
        //printf("Length is %d\n",count);
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
        //printf("length is %d\n",count+1);
        return count;
    }
}
