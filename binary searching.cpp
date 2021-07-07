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
int binary_search(int *a,int size,int capacity)
{
	int element;
	cout<<"enter the element you want to search"<<endl;
	cin>>element;
	int low,high,mid;
	low=0;
	high=size-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==element)
		{
			return mid;
		}
		else if(a[mid]<element)
		{
			low=mid;
		}
		else 
		{
			high=mid;
		}
	}
}
int main()
{
	int capacity=100;
	int size=5;
	int *arr=new int[capacity];
	setarray(arr,size);
	int found=binary_search(arr,size,capacity);
	cout<<"element found at pos "<<found<<endl;
	return 0;
}
