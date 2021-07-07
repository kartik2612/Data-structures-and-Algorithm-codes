#include<iostream>
using namespace std;
void setarray(int *a,int capacity,int size)
{
	int n;
	cout<<"enter the elements of an array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>n;
		a[i]=n;
	}
}
void insert(int *a,int element,int index,int size,int capacity)
{
	if(size>=capacity)
	{
		cout<<"insertion failed"<<endl;
	}
	else
	{
		for(int i=size-1;i>=index;i--)
	    {
	    	a[i+1]=a[i];
		}
		a[index]=element;
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
	int size=5;
	int capacity=100;
	int *a=new int[capacity];
	setarray(a,capacity,size);
	display(a,size);
	cout<<endl;
	int element=6;
	int index=3;
	insert(a,element,index,size,capacity);
	size+=1;
	cout<<"elements after insertion"<<endl;
	display(a,size);
	return 0;
}
