#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define sz 50

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};
struct node** createQ(int*, int*);
void enQ(struct node **, int*,struct node*);
struct node *deQ(struct node**, int *);

void print_level_order(struct node *root)
{
	int rear, front;
	node **queue=createQ(&front, &rear);
	node *temp=root;

	while(temp)
	{
		cout<<"\t "<<temp->data;

		if(temp->left)
			enQ(queue, &rear, temp->left);

		if(temp->right)
			enQ(queue, &rear, temp->right);

		temp=deQ(queue,&front); 	
	}
}

struct node** createQ(int *front, int *rear)
{
	struct node **queue=(struct node**)malloc(sizeof(struct node)*sz);
	*front=*rear=0;
	return queue;
}

void enQ(node **queue, int *rear, node *newnode)
{
	queue[*rear]=newnode;
	(*rear)++;
}

node *deQ(node **queue, int *front)
{
	(*front)++;
	return queue[*front -1];
}
struct node* newNode(int data)
{
struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return (node);
}

int main()
{
	node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);

	cout<<"\n LEVEL ORDER TRAVERSAL OF BINARY TREE IS \n";
	print_level_order(root);
	return 0;
}
