#include<iostream>

using namespace std;

struct node
{
	int data;
	node* link;
};
struct node* Newnode(int n)
{
	node* newnode =new node;
	newnode->data=n;
	newnode->link=NULL;
}
void disp(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->link;
		cout<<"   ";
	}
}
void middle(node* head)
{
	int i=0,count =0;
	node* temp=head;
	node* middle=head;
	while(temp!=NULL)
	{
		i++;
		if(i==3)
			{
				i=1;
				middle=middle->link;
			}	
			count++;
		temp=temp->link;
	}
	cout<<"\nNumber of elements are : "<<count<<"\n";
	if(count%2!=0)
	cout<<"\n Middle is : "<<middle->data<<"\n";
	else
	{
	cout<<"\n two Middles as number of elements are even :  "<<middle->data<<" , "<<middle->link->data<<"\n";
}
}
int main()
{
	node *head=Newnode(10);
	head->link=Newnode(9);
	head->link->link=Newnode(8);
	head->link->link->link=Newnode(7);
	head->link->link->link->link=Newnode(6);
	head->link->link->link->link->link=Newnode(5);
	head->link->link->link->link->link->link=Newnode(4);
	head->link->link->link->link->link->link->link=Newnode(3);
	head->link->link->link->link->link->link->link->link=Newnode(2);
	head->link->link->link->link->link->link->link->link->link=Newnode(1);
	head->link->link->link->link->link->link->link->link->link->link=Newnode(0);
	head->link->link->link->link->link->link->link->link->link->link->link=Newnode(-1);
	disp(head);
	middle(head);
	return 0;
}
