#include<iostream>
using namespace std;
void setarray(int *a,int size)
{
	int n;
	cout<<"enter the elements in an array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>n;
		a[i]=n;
	}
}
void linear_search(int *a,int size,int capacity)
{
	int element;
	cout<<"enter the element you want to search"<<endl;
	cin>>element;
	for(int i=0;i<size;i++)
	{
		if(a[i]==element)
		{
			cout<<"element is "<<element<<" found at index "<<i;
		}
	}
}
int main()
{
	int capacity=100;
	int size=5;
	int element;
	int *arr=new int[capacity];
	setarray(arr,size);
	linear_search(arr,size,capacity);
	return 0;
}
