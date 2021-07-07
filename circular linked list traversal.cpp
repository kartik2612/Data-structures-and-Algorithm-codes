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
	return 0;
}
