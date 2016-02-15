#include<iostream>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
};

struct node *newNode(int k)
{
	node* newnode = new node;
	newnode->key=k;
	newnode->right =NULL;
	 newnode->left =NULL;
	return newnode;
}

unsigned int countNodes(node* root)
{
	if(root == NULL)
		return 0;
	return (1 +countNodes(root->left) + countNodes(root->right));	
}

bool isComplete(node* root, unsigned int index, unsigned int number_nodes)
{
	if(root == NULL)
		return (true);
	if(index >= number_nodes)
		return (false);
	return (isComplete(root->left, 2*index+1,number_nodes) && isComplete(root->right, 2*index+2, number_nodes));
}

bool ismaxHeap(node* root)
{
	if(root->left == NULL && root->right == NULL)
		return (true);
	if(root->right == NULL)
		return (root->key >= root->left->key);
	else
	{
		if(root->key >= root->left->key && root->key >= root->right->key)
			return (ismaxHeap(root->left) && ismaxHeap(root->right));
		else
			return (false);
	}
}

bool isHeap(node* root)
{
	unsigned int node_count= countNodes(root);
	unsigned int index=0;

	if(isComplete(root, index, node_count) && ismaxHeap(root))
		return true;
	else 
		return (false);
}

int main()
{
	node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
 
    if (isHeap(root))
        cout<<"Given binary tree is a Heap\n";
    else
        cout<<"Given binary tree is not a Heap\n"; 
	return 0;
}
