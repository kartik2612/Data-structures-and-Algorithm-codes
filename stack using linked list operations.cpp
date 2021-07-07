#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	void traversal(Node *ptr)
	{
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	}
	int isEmpty(Node *top)
	{
		if(top==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isFull(Node *top)
	{
		Node *n=new Node();
		if(n==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	Node* push(Node *top,int data)
	{
		Node *n=new Node();
		if(isFull(top))
		{
			cout<<"stack overflow"<<endl;
		}
		else
		{
			n->data=data;
			n->next=top;
			top=n;
			return top;
		}
	}
	int pop(Node **top)
	{
		Node *n=*top;
		if(isEmpty(*top))
		{
			cout<<"stack underflow"<<endl;
		}
		else
		{
			int k=n->data;
			*top=(*top)->next;
			delete n;
			return k;
		}
	}
	int stackTop(Node *top)
	{
		return top->data;
	}
	int stackBottom(Node *ptr)
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		return ptr->data;
	}
	int peek(Node *top,int pos)
	{
		Node *ptr=top;
		for(int i=0;(i<pos-1&&ptr!=NULL);i++)
		{
			ptr=ptr->next;
		}
		if(ptr!=NULL)
		{
			return ptr->data;
		}
	}
};

int main()
{
	Node *top=new Node();
	top=NULL;
	
	top=top->push(top,1);
	top=top->push(top,2);
	top=top->push(top,3);
	//top->traversal(top);
	
	/*cout<<"the popped element is "<<top->pop(&top)<<endl;
	top->traversal(top);*/
	
	for(int j=1;j<4;j++)
	{
		cout<<"the element at pos "<<j<<" is "<<top->peek(top,j)<<endl;
	}
	
	cout<<"the topmost element in stack is "<<top->stackTop(top)<<endl;
	cout<<"the bottom_most element in stack is "<<top->stackBottom(top)<<endl;
	
	return 0;
}
