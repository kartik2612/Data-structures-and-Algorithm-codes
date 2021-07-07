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
	int isBST(Node *root)
	{
		static Node *prev=NULL; //tracking of prev node
		if(root!=NULL)
		{
			if(!isBST(root->left)) //checking for left subtree that is BST or not
			{
				return 0;
			}
			//checking data is smaller or greater
			if(prev!=NULL && root->data<=prev->data)
            {
				return 0;
			}
			prev=root;//updating the prev node to root
			return isBST(root->right);//checking for right subtree
		}
		else
		{
			return 1;
		}
	}
	Node* search_iterative(Node *root,int key)
	{
		while(root!=NULL)
		{
		if(key==root->data)
		{
			return root;
		}
		else if(key<root->data)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
		}
		return NULL;
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
	int k=p->isBST(p);
	if(k==1)
	{
		cout<<"it is a BST"<<endl;
	}
	else
	{
		cout<<"not a BST"<<endl;
	}
	Node *n=p->search_iterative(p,5);
	if(n!=NULL)
	{
		cout<<"element found is "<<n->data<<endl;
	}
	else
	{
		cout<<"element not found"<<endl;
	}
	return 0;
}
