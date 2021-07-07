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
	void enqueue_f(Queue *q,int val)
	{
		if(q->f==-1)
		{
			cout<<"no space in front to enqueue"<<endl;
		}
		else
		{
			q->arr[q->f]=val;
			q->f--;
		}
	}
	int dequeue_r(Queue *q)
	{
		if(q->r==-1)
		{
			cout<<"no element from rear to dequeue"<<endl;
		}
		else
		{
			int kk=q->arr[q->r];
			q->r--;
			return kk;
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
	//q->display(q);
	
	//cout<<"the dequeued element is "<<q->dequeue(q)<<endl;
	//q->display(q);
	
	/*q->enqueue_f(q,4);
	q->display(q);*/
	
	cout<<"the dequeued element from rear is "<<q->dequeue_r(q)<<endl;
	q->display(q);
	return 0;
}
