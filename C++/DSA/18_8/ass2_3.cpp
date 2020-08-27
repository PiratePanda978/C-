#include<stdio.h>
#include<stdlib.h>
struct node{
	int number;
	struct node* link;
};

void InsertAtEnd(struct node** head,struct node** tail)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("\n Enter the no to be inderted at tha last");
	scanf("%d",&temp->number);
	if(*head==NULL)
	{
		temp->link=*head;
		*head=temp;
		*tail=temp;
	}
	else
	{
		(*tail)->link=temp;
		temp->link=NULL;
		*tail=temp;
	}
}
void Print(struct node** head,struct node** tail)
{
	struct node* temp=*head;
	while(temp!=NULL)
	{
		printf("%d ",temp->number);
		temp=temp->link;
	}
}
void MiddleElement(struct node** head)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	int size=0;
	temp=*head;
	
	while(temp!=NULL)
	{
		size++;
		temp=temp->link;	
	}
	int count=0;
	int index=size/2;

	temp=*head;
	if(size%2==0)
	{
		while(count<(index-1))
		{
			count++;
			temp=temp->link;
		}
		printf("\nMiddle Elements %d %d",temp->number,temp->link->number);

	}
	else
	{
		while(count<(index-1))
		{
			count++;
			temp=temp->link;
		}
		printf("\nMiddle Element %d",temp->link->number);
		
	}
}
int main()
{
	struct node* head=NULL;
	struct node* tail=NULL;
	InsertAtEnd(&head,&tail);
	InsertAtEnd(&head,&tail);
	InsertAtEnd(&head,&tail);
	InsertAtEnd(&head,&tail);
	Print(&head,&tail);
	MiddleElement(&head);
	InsertAtEnd(&head,&tail);
	Print(&head,&tail);
	MiddleElement(&head);

	return 0;
}