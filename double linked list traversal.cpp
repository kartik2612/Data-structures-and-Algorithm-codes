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
	return 0;
}
