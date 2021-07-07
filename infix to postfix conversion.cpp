#include<iostream>
#include<cstring>
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
	int stackTop(stack *s)
	{
	    return s->arr[s->top];
	}
	int stackBottom(stack *s)
	{
	    return s->arr[0];
	}
	int isOperator(char a)
	{
		if(a=='/'||a=='*'||a=='-'||a=='+')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int precedence(char ch)
	{
		if(ch=='/'||ch=='*')
		{
			return 3;
		}
		else if(ch=='+'||ch=='-')
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	
	char* infix_to_postfix_conversion(char *infix)
	{
		stack *s=new stack();
		s->top=-1;
		s->size=100;
		s->arr=new char[s->size];
		char *postfix=new char[strlen(infix)+1];
	int i=0;
	int j=0;
	while(infix[i]!='\0')
	{
		if(!isOperator(infix[i]))
		{
			postfix[j]=infix[i];
			i++;
			j++;
		}
		else
		{
			if(precedence(infix[i])>precedence(stackTop(s)))
			{
				push(s,infix[i]);
				i++;
			}
			else
			{
				postfix[j]=pop(s);
				j++;
			}
		}
	}
	while(!isEmpty(s))
		{
			postfix[j]=pop(s);
			j++;
		}
		postfix[j]='\0';
		return postfix;
	}
};

int main()
{
	char *infix=new char[100];
	cin>>infix;
	stack *s;
	cout<<"the postfix expression is "<<s->infix_to_postfix_conversion(infix)<<endl;
	
	return 0;
	
}
