#include <stdio.h>
#include <stdlib.h>
void creationNode();
void displayNode();
void insertionAtFront();
void insertionAtanypoint();
void insertAtEnd();
void insertAtMid();
void deleAtFront();
void deletionAtanypoint();
void deletionAtEnd();
void deletionAtMid();
int countLengthList();

struct node {
    int data;
    struct node * next;
};
struct node *head;
int main()
{
    int choice;
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
        	printf("11. Length of linked list\n");
        	printf("12. Exit point\n");
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
                	    countLengthList();
                            break;
            		}
			case 12:
			{
				printf("Exit point");
				exit(0);
				break;
			}
			default:
				printf("Enter valid input\n");	
		}
	}while(choice!=12);
}
void creationNode()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted\n");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        head=ptr;
        ptr->next=head;
        printf("Node inserted...\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
        printf("Node inserted\n");
    }
}
void displayNode(){
        struct node *ptr;
	ptr = head;
	if(head==NULL)
	{
		printf("There is no node to display\n");
	}
	else
	{
		printf("\nPrinting...\n");
		while(ptr->next!=head)
		{
			printf("%d\n",ptr->data);
           		ptr=ptr->next;
		}
        	printf("%d\n",ptr->data);
	}
}
void insertionAtFront(){
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value:\n");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        head=ptr;
        temp->next=head;
        printf("Node inserted successfully...\n");
    }
}
void insertionAtanypoint()
{
    struct node *ptr,*temp,*temp1;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val,loc,i;
    printf("Enter the location you want to inset:\n");
    scanf("%d",&loc);
    printf("Enter the value:\n");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        temp=head;
        for(i=0;i<loc-1;i++)
        {
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("Node inserted Successfully\n");
    }
}
void insertAtEnd()
{
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value to be inserted\n");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        temp->next=ptr;
        printf("Node inserted Successfully\n");
    }
}
void insertAtMid()
{
    int count=countLengthList();
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    int val,loc;
    printf("Now, enter the value to be inserted\n");
    scanf("%d",&val);
    ptr->data=val;
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
        printf("Node inserted successfully\n");
    }
    
}
void deleAtFront()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("Node deleted Successfully...\n");
    }
    else
    { 
        temp = head;
        while(temp-> next != head)
        {
            temp= temp-> next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        printf("Node deleted Successfully...\n");
    }
}
void deletionAtanypoint()
{
    struct node *ptr,*temp;
    int loc,i;
    printf("Enter the location of the node to be deleted\n");
    scanf("%d",&loc);
    if(head==NULL)
    {
        printf("Memory is empty\n");
    }
    else
    {
        temp=head;
        for(i=0;i<loc;i++)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        free(temp);
        printf("Node deleted successfully\n");
    }
}
void deletionAtEnd()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
    }   
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=head;
        free(temp);
        printf("Node deleted Successfully\n");
    }
}
int countLengthList()
{
    struct node *temp;
    int count=0;
    if(head==NULL)
    {
        count=0;
        printf("Lenth of the linked list is %d\n",count);
        return count;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            count++;
        }
        printf("Length of the linked list is %d\n",count+1);
        return count;
    }
}
void deletionAtMid()
{
    int count = countLengthList();
    struct node *ptr,*temp;
    int loc;
    if(head==NULL)
    {
        printf("Memory is not allocated\n");
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
        printf("Node deleted Successfully\n");
    }
}

        
