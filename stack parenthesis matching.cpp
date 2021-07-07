#include<iostream>
using namespace std;
class stack
{
	public:
	int top;
	char *arr;
	int size;
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
	void push(stack *s,char data)
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
	int parenthesis_match(char *exp)
	{
		stack *s=new stack();
		s->top=-1;
		s->size=100;
		s->arr=new char[s->size];
		for(int i=0;exp[i]!='\0';i++)
		{
			if(exp[i]=='(')
			{
				push(s,'(');
			}
			else if(exp[i]==')')
			{
				if(isEmpty(s))
				{
					return 0;
				}
				pop(s);
		    }
		}
		if(isEmpty(s))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
int main()
{
	char *exp="8-(5*6)";
	stack *s;
	if(s->parenthesis_match(exp))
	{
		cout<<"parenthesis are matching"<<endl;
	}
	else
	{
		cout<<"not matching"<<endl;
	}
	return 0;
}
