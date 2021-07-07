#include<iostream>
using namespace std;
class circularQueue
{
	public:
		int f;
		int r;
		int size;
		int *arr;
		void display(circularQueue *cq)
		{
			for(int i=cq->f+1;i!=cq->r+1;i=(i+1)%cq->size)
			{
				cout<<cq->arr[i]<<" ";
			}
		}
		int isEmpty(circularQueue *cq)
		{
			if(cq->r==cq->f)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int isFull(circularQueue *cq)
		{
			if((cq->r+1)%size==cq->f)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void enqueue(circularQueue *cq,int data)
		{
			if(isFull(cq))
			{
				cout<<"queue is full"<<endl;
			}
			else
			{
				cq->r=(cq->r+1)%cq->size;
				cq->arr[cq->r]=data;
			}
		}
		int dequeue(circularQueue *cq)
		{
			if(isEmpty(cq))
			{
				cout<<"queue is empty"<<endl;
			}
			else
			{
				cq->f=(cq->f+1)%cq->size;
				int k=cq->arr[cq->f];
				return k;
			}
		}
		
};

int main()
{
	circularQueue *cq=new circularQueue();
	cq->f=cq->r=-1;
	cq->size=100;
	cq->arr=new int[cq->size];
	
	cq->enqueue(cq,1);
	cq->enqueue(cq,2);
	cq->enqueue(cq,3);
	cq->display(cq);
	
	cout<<"the dequeued element is "<<cq->dequeue(cq)<<endl;
	cq->display(cq);
	
	return 0;
	
}
