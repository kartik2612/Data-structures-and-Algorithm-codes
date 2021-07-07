#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	void traversal(Node *head);
	Node* insert_begg(Node *head,int data);
	Node* insert_index(Node *head,int index,int data);
	Node* insert_end(Node *head,int data);
};

void Node :: traversal(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

Node*  Node :: insert_begg(Node *head,int data)
{
	Node *new_node=new Node();
	new_node->data=data;
	new_node->next=head;
	return new_node;
}

Node* Node :: insert_index(Node *head,int index,int data)
{
	Node *new_node=new Node();
	Node *p=head;
	new_node->data=data;
	new_node->next=NULL;
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	new_node->next=p->next;
	p->next=new_node;
	return head;
}

Node* Node :: insert_end(Node *head,int data)
{
	Node *new_node=new Node();
	Node *p=head;
	new_node->data=data;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=new_node;
	return head;
}

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
	third->next=NULL;
	
	head->traversal(head);
	
	/*head=head->insert_begg(head,5);
	head->traversal(head);*/
	
	/*head=head->insert_index(head,2,5);
	head->traversal(head);*/
	
	head=head->insert_end(head,5);
	head->traversal(head);
	
	return 0;
}
