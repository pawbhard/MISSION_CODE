#include<iostream>

using namespace std;

struct node
{
	int data;
	node *link;
};
struct node* front(node* temp, node** head,node* prev)
{
	prev->link=temp->link;
	temp->link=*head;
	*head= temp;
	return (prev->link);
}
struct node* back(node* temp, node** head,node* prev)
{
        prev->link=temp->link;
        node* temp1 = (*head)->link;
	(*head)->link = temp;
	temp->link = temp1;

        return (prev->link);
}

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


struct node* func(node* head)
{
	node* temp=head;
	node* temp1;
	node* prev;
	node* i_head=head;
	while(temp!=NULL)
	{
//		if(temp->data==0)
//		{
//			cout<<"\n head data : "<<head->data;
//			temp=front(temp, &head, prev);
//			cout<<"\n head data : "<<head->data;
//		}
//		else 
			if(temp->data==1)
                {
			temp1=temp;
                       // cout<<"\n head data : "<<head->data;
                        temp=back(temp, &i_head, prev);
			prev=temp1;
                        //cout<<"\n head data : "<<head->data;
                }

		/*else if(temp->data==1)
		{
			temp1=temp;
			temp=temp->link;
			temp1->link=temp1;
			temp1->link=i_head;
			i_head=temp1;
		}
*/
		else
			{	
				prev=temp;
				temp=temp->link;
			}
		
	}
	return head;
}

int main()
{
		node *head=Newnode(1);
        head->link=Newnode(0);
        head->link->link=Newnode(0);
        head->link->link->link=Newnode(2);
        head->link->link->link->link=Newnode(1);
        head->link->link->link->link->link=Newnode(1);
        head->link->link->link->link->link->link=Newnode(2);
        head->link->link->link->link->link->link->link=Newnode(0);
        head->link->link->link->link->link->link->link->link=Newnode(0);
        head->link->link->link->link->link->link->link->link->link=Newnode(1);
        cout<<"\n list : ";
		disp(head);
		cout<<"\n";
		head=func(head);
		cout<<"\n list : ";
        disp(head);
        cout<<"\n";
	return 0;
}
