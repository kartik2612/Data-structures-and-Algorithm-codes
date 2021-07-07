#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	void traversal(Node *head)
	{
		Node *p=head;
		do
		{
			cout<<p->data<<" ";
			p=p->next;
		}while(p!=head);	
	}
	Node* delete_begg(Node *head)
	{
		Node *p=head;
		Node *q=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		head=head->next;
		p->next=head;
		delete q;
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
		delete q;
		return head;
	}
	Node* delete_end(Node *head)
	{
		Node *p=head;
		Node *q=head->next;
		while(q->next!=head)
		{
			p=p->next;
			q=q->next;
		}
		p->next=head;
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
	head->next=second;
	
	second->data=2;
	second->next=third;
	
	third->data=3;
	third->next=head;
	
	head->traversal(head);
	
	/*head=head->delete_begg(head);
	head->traversal(head);*/
	
	/*head=head->delete_index(head,1);
	head->traversal(head);*/
	
	head=head->delete_end(head);
	head->traversal(head);
	
	return 0;
}
