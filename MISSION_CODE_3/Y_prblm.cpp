//#include "Y_prblm.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

int getCount(struct node* head);

int _getIntNode(int d, struct node* head1, struct node* head2);

int getIntNode( struct node* head1, struct node* head2)
{
	struct node* h1=head1;
	struct node* h2=head2;
	int c1=getCount(h1);
	int c2=getCount(h2);
	int d;

	if(c1>c2)
	{
		d=c1-c2;
		return _getIntNode(d,h1, h2);
	}
	else
	{
		d=c2-c1;
		return _getIntNode(d,h2,h1);
	}
}

int _getIntNode(int d, struct node* head1, struct node* head2)
{
	int i;
	struct node* current1=head1;
	struct node* current2=head2;

	for(i=0; i<d;i++)
	{
		if(current1==NULL)
			return -1;
	
		current1=current1->next;
	}

	while(current1 != NULL && current2 != NULL)
	{
		if(current1==current2)
			return current1->data;
		current1=current1->next;
		current2=current2->next;
	}
	return -1;
}

int GetCount(struct node* head)
{
	struct node* current = head;
	int count =0;

	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntNode(head1, head2));
 
  getchar();
}
