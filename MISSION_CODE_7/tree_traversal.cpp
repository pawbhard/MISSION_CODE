#include <iostream>

using namespace std;

struct node 
{
	int data;
	node* left;
	node* right;
};

struct node* Newnode(int n)
{
	node* newnode= new node;
	newnode->data= n;
	newnode->left= NULL;
	newnode->right= NULL;
}

void preorder(node* node)
{
	if(node==NULL)
		return;
	cout<<node->data<<" ";
	
	preorder(node->left);
	preorder(node->right);
}

void inorder(node* node)
{
	if(node==NULL)
		return ;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

void postorder(node* node)
{
	if(node==NULL)
		return ;
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<" ";
}
int main()
{
	node *root= Newnode(1);

	root->left= Newnode(2);
	root->right= Newnode(3);
	root->left->left=Newnode(4);
	root->left->right=Newnode(5);
	cout<<"\n Preorder : ";
	preorder(root);
	cout<<"\n Inorder : ";
	inorder(root);
	cout<<"\n Postorder : ";
	postorder(root);
	return 0;
}
