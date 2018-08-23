#include<stdio.h>
#include<stdlib.h>

//Structure for creating node
typedef struct node{
	int data;
	struct node *next;
}node;


//Function to accept data from STDIN and create a node* type object
node *create()
{
	int data;
	printf("\n-----------------------------------------------------------------------\n");
	printf("\nEnter data:\t");
	scanf("%d",&data);
	printf("\n-----------------------------------------------------------------------\n");
	node* new_node=(node*)malloc(sizeof(node));
	new_node->data=data;
	new_node->next=NULL;
	
	return new_node;

}

//Function to insert node at the beginning of the existing linked list
node* Insert_Beginning(node* head)
{
	//create a new node
	node *new_node=create();
	node *temp=head;
	head=new_node;
	new_node->next=temp;
	return head;
}


// O(1) method to append a node at the end
node * Insert_End(node* head, node** rear)
{
	//create a new node
	node *new_node=create();
	
	//if it is the first node then both head and rear are pointing to NULL
	if (*rear!=NULL)
		(*rear)->next=new_node;
	else
		head=new_node;
	*rear=new_node;
	return head;
}




//Function to display the linked list
void Display(node * np)
{
	printf("\n-----------------------------------------------------------------------\n");
	while(np!=NULL)
	{
		printf("%d->",np->data);
		np=np->next;
	}
	printf("NULL");
	printf("\n-----------------------------------------------------------------------\n");
}


//The main function.
int main(int argc, char const *argv[])
{
	node* start=NULL;
	node* rear=NULL;
	int n,flag=1;
	while(flag)
	{
		
		printf("\nEnter your choice:\n1.Append Data\n2.Prepend data\n3.Display\n4.Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:start=Insert_End(start,&rear);break;
			case 2:start=Insert_Beginning(start);break;
			case 3:Display(start);break;
			case 4:flag=0;break;
			default:printf("\nWrong choice. Try again..........\n"); 
		}
	}
	return 0;
}
