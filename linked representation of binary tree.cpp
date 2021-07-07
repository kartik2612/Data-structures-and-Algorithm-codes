#include<iostream>
using namespace std; //linked representation of binary tree
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	Node* create_node(int data) //function for creating the nodes
	{
		Node *n=new Node();
		n->data=data;
		n->left=NULL;
		n->right=NULL;
		return n;
	}
};

int main()
{
	//creting the root node
	Node *root;
	root->create_node(1);
	
	//creating the first child of root node
	Node *child_1;
	child_1->create_node(2);
	
	//creating the second child of root node
	Node *child_2;
	child_2->create_node(3);
	
	//linking the child nodes with root node
	root->left=child_1;
	root->right=child_2;
	
	return 0;
}
