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
	void preOrder(Node *root)
	{
		if(root!=NULL)
		{
			cout<<root->data<<" ";
			preOrder(root->left);
		    preOrder(root->right);
		}
	}
};

int main()
{
	//creting the root node
	Node *p=p->create_node(4);
	
	//creating the first child of root node
	Node *p1=p1->create_node(1);
	
	//creating the second child of root node
	Node *p2=p2->create_node(6);
	
	Node *p3=p3->create_node(5);
	
	Node *p4=p4->create_node(2);
	
	//linking the child nodes with root node
	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p1->right=p4;
	
	p->preOrder(p);
	
	return 0;
}
