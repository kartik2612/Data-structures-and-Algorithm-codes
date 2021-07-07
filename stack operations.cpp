#include<iostream>
using namespace std;
class stack
{
	public:
	int size;
	int top;
	int *arr;
	void display(stack *s)
	{
		for(int i=0;i<=s->top;i++)
		{
			cout<<s->arr[i]<<" ";
		}
	}
	int isEmpty(stack *s)
	{
		if(s->top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isFull(stack *s)
	{
		if(s->top==s->size-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void push(stack *s,int data)
	{
		if(isFull(s))
		{
			cout<<"stack is overflow"<<endl;
		}
		else
		{
			s->top++;
			s->arr[s->top]=data;
		}
	}
	int pop(stack *s)
	{
		if(isEmpty(s))
		{
			cout<<"stack is underflow"<<endl;
		}
		else
		{
			int k=s->arr[s->top];
			s->top--;
			return k;
		}
	}
	int stackTop(stack *s)
	{
	    return s->arr[s->top];
	}
	int stackBottom(stack *s)
	{
	    return s->arr[0];
	}
	int peek(stack *s,int i)
	{
		int kk=s->top-i+1;
		if(kk<0)
		{
			return -1;
		}
		else
		{
			return s->arr[kk];
		}
	}
};

int main()
{
	stack *s=new stack();
	
	s->size=100;
	s->top=-1;
	s->arr=new int[s->size];
	
	s->push(s,1);
	s->push(s,2);
	s->push(s,3);
	//s->display(s);
	
	/*cout<<"popped element is "<<s->pop(s)<<endl;
	s->display(s);*/
	
	/*for(int j=1;j<=s->top+1;j++)
	{
		cout<<"the element at top pos "<<j<<" is "<<s->peek(s,j)<<endl;
	}*/
	
	cout<<"the topmost element in stack is "<<s->stackTop(s)<<endl;
	cout<<"the bottom_most element in stack is "<<s->stackBottom(s)<<endl;
	
	return 0;
}
