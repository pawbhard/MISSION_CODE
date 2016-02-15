#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to reverse the linked list */
 void recreverse(struct node** head_ref)
{
	struct node* first;
	struct node* rest;

	if(*head_ref == NULL)
		return;

	first = *head_ref;
	rest = first->next;

	if(rest==NULL)
		return;

	recreverse(&rest);
	first->next->next=first;
	first->next=NULL;
	*head_ref = rest;
}
 
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);   
        temp = temp->next; 
    }
}   
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);     
     
     printList(head);   
     recreverse(&head);                     
     printf("\n Reversed Linked list \n");
     printList(head);   
     getchar();
}
