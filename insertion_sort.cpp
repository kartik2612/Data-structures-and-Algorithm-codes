#include<iostream>
using namespace std;
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void insertion_sort(int *arr,int n)
{
	int key,j;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		key=arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	int *arr=new int[100];
	int n=5;
	cout<<"enter the elements of an array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	display(arr,n);
	cout<<endl;
	
	insertion_sort(arr,n);
	display(arr,n);
	
	return 0;
}
