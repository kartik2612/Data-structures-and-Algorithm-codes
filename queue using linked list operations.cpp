#include<iostream>
using namespace std;
class Node;
Node *f=NULL;
Node *r=NULL;
class Node
{
	public:
	int data;
	Node *next;
    void traversal(Node *f)
    {
    	while(f!=NULL)
    	{
    		cout<<f->data<<" ";
    		f=f->next;
		}
	}
	void enqueue(int data)
	{
		Node *n=new Node();
		if(n==NULL)
		{
			cout<<"queue is full"<<endl;
		}
		else
		{
			n->data=data;
			n->next=NULL;
			if(f==NULL)
			{
				f=r=n;
			}
			else
			{
				r->next=n;
				r=n;
			}
		}
	}
	int dequeue()
	{
		Node *ptr=f;
		if(f==NULL)
		{
			cout<<"queue is empty"<<endl;
		}
		else
		{
			f=f->next;
			int val=ptr->data;
			delete ptr;
			return val;
		}
	}
};

int main()
{
	f->enqueue(1);
	f->enqueue(2);
	f->enqueue(3);
	f->traversal(f);
	
	cout<<"the dequeued element is "<<f->dequeue()<<endl;
	f->traversal(f);
	
	return 0;
}
