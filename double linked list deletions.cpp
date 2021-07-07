#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *prev;
	Node *next;
	void traversal(Node *head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
	}
	Node* delete_begg(Node *head)
	{
		Node *p=head;
		head=head->next;
		delete p;
		return head;
	}
	Node* delete_index(Node *head,int index)
	{
		Node *p=head;
		Node *q=head->next;
		int i=0;
		while(i!=index-1)
		{
			p=p->next;
			q=q->next;
			i++;
		}
		p->next=q->next;
		q->next->prev=p;
		delete q;
		return head;
	}
	Node* delete_end(Node *head)
	{
		Node *p=head;
		Node *q=head->next;
		while(q->next!=NULL)
		{
			p=p->next;
			q=q->next;
		}
		p->next=NULL;
		delete q;
		return head;
	}
};
int main()
{
    Node *head=NULL;
	Node *second=NULL;
	Node *third=NULL;
	
	head=new Node();
	second=new Node();
	third=new Node();
	
	head->data=1;
	head->prev=NULL;
	head->next=second;	
	
	second->data=2;
	second->prev=head;
	second->next=third;
	
	third->data=3;
	third->prev=second;
	third->next=NULL;
	
	head->traversal(head);
	
	/*head=head->delete_begg(head);
	head->traversal(head);*/
	
	head=head->delete_end(head);
	head->traversal(head);
	
	/*head=head->delete_index(head,1);
	head->traversal(head);*/
	
	return 0;
}
