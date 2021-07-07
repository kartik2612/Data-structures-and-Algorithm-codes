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
	
	int match(char a,char b)
	{
		if(a=='('&&b==')')
		{
			return 1;
		}
		if(a=='{'&&b=='}')
		{
			return 1;
		}
		if(a=='['&&b==']')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int parenthesis_matching(char *exp)
	{
		stack *s=new stack();
		s->size=100;
		s->top=-1;
		s->arr=new char[s->size];
		char popped_ele;
		for(int i=0;exp[i]!='\0';i++)
		{
			if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			{
				push(s,exp[i]);
			}
			else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
			{
				if(isEmpty(s))
				{
					return 0;
				}
				popped_ele=pop(s);
				if(!match(popped_ele,exp[i]))
				{
					return 0;
				}
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
	char *exp=new char[100];
	cin>>exp;
	stack *s;
	if(s->parenthesis_matching(exp))
	{
	    cout<<"parenthesis are matching"<<endl;
	}
	else
	{
		cout<<"not matching"<<endl;
	}
	
	return 0;
}
