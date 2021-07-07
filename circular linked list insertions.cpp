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
	Node* insert_begg(Node *head,int data)
	{
		Node *new_node=new Node();
		Node *p=head;
		new_node->data=data;
		while(p->next!=head)
		{
			p=p->next;
		}
		new_node->next=head;
		p->next=new_node;
		return new_node;
	}
	Node* insert_index(Node *head,int data,int index)
	{
		Node *new_node=new Node();
		Node *p=head;
		Node *q=head->next;
		new_node->data=data;
		int i=0;
		while(i!=index-1)
		{
			p=p->next;
			q=q->next;
			i++;
		}
		new_node->next=q;
		p->next=new_node;
		return head;
	}
	Node* insert_end(Node *head,int data)
	{
		Node *new_node=new Node();
		Node *p=head;
		new_node->data=data;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=new_node;
		new_node->next=head;
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
	
	/*head=head->insert_begg(head,5);
	head->traversal(head);*/
	
	/*head=head->insert_index(head,5,1);
	head->traversal(head);*/
	
	head=head->insert_end(head,5);
	head->traversal(head);
	
	return 0;
}
