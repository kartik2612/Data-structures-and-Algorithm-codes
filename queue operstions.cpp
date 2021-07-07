#include<iostream>
using namespace std;
class Queue
{
	public:
	int f;
	int r;
	int size;
	int *arr;
	void display(Queue *q)
	{
		for(int i=q->f+1;i<=q->r;i++)
		{
			cout<<q->arr[i]<<" ";
		}
	}
	int isEmpty(Queue *q)
	{
		if(q->r==q->f)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isFull(Queue *q)
	{
		if(q->r==q->size-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void enqueue(Queue *q,int data)
	{
		if(isFull(q))
		{
			cout<<"queue overflow"<<endl;
		}
		else
		{
			q->r++;
			q->arr[q->r]=data;
		}
	}
	int dequeue(Queue *q)
	{
		if(isEmpty(q))
		{
			cout<<"queue underflow"<<endl;
		}
		else
		{
			q->f++;
			int k=q->arr[q->f];
			return k;
		}
	}
};

int main()
{
	Queue *q=new Queue();
	q->f=q->r=-1;
	q->size=100;
	q->arr=new int[q->size];
	q->enqueue(q,1);
	q->enqueue(q,2);
	q->enqueue(q,3);
	q->display(q);
	
	cout<<"the dequeued element is "<<q->dequeue(q)<<endl;
	q->display(q);
	
	return 0;
}
