#include<iostream>
using namespace std;//min heap deletion
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
	int smallest=root;
	int l=2*root+1;
	int r=2*root+2;
	if(l<n && arr[l]<arr[smallest])
	{
		smallest=l;
	}
	if(r<n && arr[r]<arr[smallest])
	{
		smallest=r;
	}
	if(smallest!=root)
	{
		swap(&arr[root],&arr[smallest]);
		heapify(arr,n,smallest);
	}
}
void delete_root(int *arr,int &n)
{
	int lastelement=arr[n-1];
	arr[0]=lastelement;
	n=n-1;
	heapify(arr,n,0);
}
int main()
{
	int size=5;
	int *arr=new int[size];
	createarray(arr,size);
	delete_root(arr,size);
	printarray(arr,size);
	
	return 0;
}
