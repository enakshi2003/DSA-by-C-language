#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#define null 0
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root;
void init();
int empty();
int insert(int);
void dele(int);
void preorder(struct node*);
void postorder(struct node *);
void inorder(struct node *);
void printtree(int);
void searchitem(int);
void init()
{
	root = (struct node*)malloc(sizeof(struct node));
	root = NULL;
}
int empty()
{
	return(root==NULL);
}
int insert(int x)
{
	struct node *p,*previous, *current;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("\n Out of memory");
		return 0;
	}
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	if(root == NULL)
	{
		root=p;
		return 1;
	}
	previous = NULL;
	current = root;
	while(current!=NULL)
	{
		previous = current;
		if(p->data < current->data)
		{
			current=current->left;
		}
		else
		{
			current = current->right;
		}
	}
	if(p->data <previous->data)
	{
		previous ->left=p;
	}
	else
	{
		previous->right=p;
	}
	return 1;
}
void dele(int x)
{
	struct node *ptr = root, *parent=NULL, *t2, *t1,*temp;
	while(ptr!=NULL && ptr->data !=x)
	{
		parent = ptr;
		if(x<ptr ->data)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr ->right;
		}
	}
	if(ptr == NULL)
	{
		printf("\n Delete element not found\n");
		return;
	}
	if(ptr==NULL)
	{
		t1=ptr->right;
	}
	else if(ptr->right==NULL)
	{
		t1=ptr->left;
	}
	else
	{
		t2=ptr;
		t1=ptr->right;
		temp=t1->left;
		while(temp!=NULL)
		{
			t2=t1;
			t1=temp;
			temp=t1->left;
		}
		if(t2!=ptr)
		{
			t2->left = t1->right;
			t1 ->right = ptr->right;
		}
		t1->left = ptr->left;
	}
	if(parent==NULL)
	{
		root=t1;
	}
	else
	{
		if(parent ->left == ptr)
		{
			parent->left=t1;
		}
		else
		{
			parent->right=t1;
		}
	}
	free(ptr);
}
void printtree(int x)
{
	if(x==1)
	{
		preorder(root);
	}
	else if(x==2)
	{
		inorder(root);
	}
	else
	{
		postorder(root);
	}
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%5d",p->data);
		inorder(p->right);
	}
}
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%5d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%5d",p->data);
	}
}
void searchitem(int sno)
{
	struct node *tnode;
	tnode = (struct node *)malloc(sizeof(struct node));
	tnode = root;
	while(tnode!=NULL && tnode->data !=sno)
	{
		if(tnode->data > sno)
		{
			tnode = tnode ->left;
		}
		else
		{
			tnode = tnode->right;
		}
	}
	if(tnode)
	{
		printf("\n Search number is present\n");
	}
	else
	{
		printf("\n Search number is not present\n");
	}
}
int main()
{
	int choice,no,x;
	init();
	do
	{
		printf("Insertion [1] \n");
		printf("preorder [2] \n");
		printf("Inorder [3] \n");
		printf("postorder [4] \n");
		printf("Deletion [5] \n");
		printf("Searching [6] \n");
		printf("Exit [7] \n");
		printf("Enter your choice-> \n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				{
					printf("Enter the element to insert\n");
					scanf("%d",&no);
					x=insert(no);
					if(x==1)
					{
						printf("Successfully inserted\n");
					}
					else
					{
						printf("Error in insertion\n");
					}
					break;
				}
			case 2:
				{
					if(root!=null)
					{
						printf("\n The preorder elements are\n");
						printtree(1);
						printf("\n");
					}
					else
					{
						printf("\n No elements to display\n");
					}
					break;
				}
			case 3:
				{
					if(root!=NULL)
					{
						printf("\n The inorder elements are\n");
						printtree(2);
						printf("\n");
					}
					else
					{
						printf("No elements to display");
					}
					break;
				}
			case 4:
				{
					if(root!=null)
					{
						printf("\n The postorder elements are \n");
						printtree(3);
						printf("\n");
					}
					else
					{
						printf("\n No elements to display\n");
					}
					break;
				}
			case 5:
				{
					printf("Enter the elements to delete\n");
					scanf("%d",&no);
					dele(no);
					break;
				}
			case 6:
				{
					printf("\n Enter the element to search\n");
					scanf("%d",&no);
					searchitem(no);
					break;
				}
			default:
				{
					printf("\n Bye...\n");
					exit(0);
				}
		}
		
	}
	while(choice<7);
}