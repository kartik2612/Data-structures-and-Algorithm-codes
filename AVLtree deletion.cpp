#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	int height;
	Node* createnode(int data)
	{
		Node *n=new Node();
		n->data=data;
		n->left=NULL;
		n->right=NULL;
		n->height=1;
	}
	int height_node(Node *node)
	{
		int l,r;
		if(node==NULL)
		{
			return 0;
		}
		else
		{
			l=height_node(node->left);
			r=height_node(node->right);
		}
		if(l>r)
		{
			return l+1;
		}
		else
		{
			return r+1;
		}
	}
	int balancefactor(Node *n)
	{
		return height_node(n->left)-height_node(n->right);
	}
	
	Node* leftrotation(Node *y)
	{
		Node *x=y->right;
		Node *T2=x->left;
		
		x->left=y;
		y->right=T2;
		
		y->height=height_node(y);
		x->height=height_node(x);
		
		return x;
	}
	
	Node* rightrotation(Node *x)
	{
		Node *y=x->left;
		Node *T2=y->right;
		
		y->right=x;
		x->left=T2;
		
		x->height=height_node(x);
		y->height=height_node(y);
		
		return y;
	}
	Node* insert(Node *node,int data)
	{
		if(node==NULL)
		{
			return createnode(data);
		}
		if(data<node->data)
		{
			node->left=insert(node->left,data);
		}
		else if(data>node->data)
		{
			node->right=insert(node->right,data);
		}
		else
		{
			return node;
		}
		
		int balance=balancefactor(node);
		
		if(balance>1 && data<node->left->data)
		{
			return rightrotation(node);
		}
		if(balance<-1 && data>node->right->data)
		{
			return leftrotation(node);
		}
		if(balance>1 && data>node->left->data)
		{
			node->left=leftrotation(node->left);
			return rightrotation(node);
		}
		if(balance<-1 && data<node->right->data)
		{
			node->right=rightrotation(node->right);
			return leftrotation(node);
		}
		return node;
	}
	void preorder(Node *node)
	{
		if(node!=NULL)
		{
			cout<<node->data<<" ";
			preorder(node->left);
			preorder(node->right);
		}
	}
	Node* findmin(Node *n)
	{
		while(n->left!=NULL)
		{
			n=n->left;
		}
		return n;
	}
	Node* delete_node(Node *root,int data)
	{
		if(root==NULL)
		{
			return root;
		}
		if(data<root->data)
		{
			root->left=delete_node(root->left,data);
		}
		else if(data>root->data)
		{
			root->right=delete_node(root->right,data);
		}
		else
		{
			//for leaf node
			if(root->left==NULL&&root->right==NULL)
			{
				delete root;
				root=NULL;
			}
			else if(root->left==NULL)
			{
				Node *temp=root;
				delete temp;
				root=root->right;
			}
			else if(root->right==NULL)
			{
				Node *temp=root;
				delete temp;
				root=root->left;
			}
			else
			{
				Node *temp=findmin(root->right);
				root->data=temp->data;
				root->right=delete_node(root->right,temp->data);
			}
			if(root==NULL)
			{
				return root;
			}
			root->height=height_node(root);
			int balance=balancefactor(root);
			if(balance>1 && balancefactor(root->left)>=0)
			{
				return rightrotation(root);
			}
			if(balance<-1 && balancefactor(root->right)<=0)
			{
				return leftrotation(root);
			}
			if(balance>1 && balancefactor(root->right)<0)
			{
				root->left=leftrotation(root->left);
				return rightrotation(root);
			}
			if(balance<-1 && balancefactor(root->left)>0)
			{
				root->right=rightrotation(root->right);
				return leftrotation(root);
			}
			return root;
		}
	}
};

int main()
{
	Node *root=NULL;
	root=root->insert(root,10);
	root=root->insert(root,20);
	root=root->insert(root,30);
	root=root->insert(root,40);
	root=root->insert(root,50);
	root=root->insert(root,25);
	
	root->preorder(root);
	cout<<endl;
	
	cout<<"after deletion preorder becomes"<<endl;
	root=root->delete_node(root,40);
	
	root->preorder(root);
	
	return 0;
}
