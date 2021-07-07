#include<iostream>
using namespace std;
void setarray(int *a,int size,int capacity)
{
	int n;
	for(int i=0;i<size;i++)
	{
		cin>>n;
		a[i]=n;
	}
}
void delete_ele(int *a,int size,int capacity,int index)
{
	if(index>=capacity)
	{
		cout<<"deletion failed"<<endl;
	}
	else
	{
	for(int i=index;i<size;i++)
	{
		a[i]=a[i+1];
	}
}
}
void display(int *a,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int capacity=100;
	int size=5;
	int index;
	int *a=new int[capacity];
	cout<<"enter the element of an array"<<endl;
	setarray(a,size,capacity);
	
	display(a,size);
	cout<<endl;
	cout<<"enter the inddex of element"<<endl;
	cin>>index;
	
	delete_ele(a,size,capacity,index);
	size-=1;
	display(a,size);
	return 0;
}
