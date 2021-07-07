#include<iostream>
using namespace std;//max heap deletion
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void createarray(int *arr,int n)
{
	int ele;
	cout<<"enter the element of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		arr[i]=ele;
	}
}

void printarray(int *arr,int n)
{
	cout<<"array elements are"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void heapify(int *arr,int n,int root)
{
	int largest=root;
	int l=2*root+1;
	int r=2*root+2;
	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=root)
	{
		swap(&arr[root],&arr[largest]);
		heapify(arr,n,largest);
	}
}
void heap_sort(int *arr,int n)
{
	for(int i=(n/2-1);i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
int main()
{
	int size=5;
	int *arr=new int[size];
	createarray(arr,size);
	heap_sort(arr,size);
	printarray(arr,size);
	
	return 0;
}
