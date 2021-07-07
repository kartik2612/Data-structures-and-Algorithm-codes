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
	void inOrder(Node *root)
	{
		if(root!=NULL)
		{
			inOrder(root->left);
			cout<<root->data<<" ";
			inOrder(root->right);
		}
	}
    //Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
 Node* Delete( Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
};

int main()
{
	//creting the root node
	Node *p=p->create_node(5);
	
	//creating the first child of root node
	Node *p1=p1->create_node(3);
	
	//creating the second child of root node
	Node *p2=p2->create_node(6);
	
	Node *p3=p3->create_node(1);
	
	Node *p4=p4->create_node(4);
	
	//linking the child nodes with root node
	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p1->right=p4;
	
	p->inOrder(p);
	
	cout<<endl;
	
	p=p->Delete(p,3);
	cout<<"inorder becomes"<<endl;
	p->inOrder(p);
	
	return 0;
}
