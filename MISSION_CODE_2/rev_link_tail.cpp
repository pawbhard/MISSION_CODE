#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void rev_util(node *curr, node *prev, node **head);

void reverse(node **head)
{
	if(!head)
		return;
	rev_util(*head, NULL, head);		
}

void rev_util(node *curr, node *prev, node **head)
{
	if(!curr->next)
	{
		*head = curr;
		curr->next=prev;
		return;
	}

	node *next = curr->next;
	curr->next=prev;

	rev_util(next, curr, head);
}

node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printlist(node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    cout << "Given linked list\n";
    printlist(head1);
    reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
