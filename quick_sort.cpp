#include<iostream>
using namespace std;
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *a,int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	do
	{
		while(a[i]<=pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}while(i<j);
	swap(&a[low],&a[j]);
	return j;
}

void quick_sort(int *arr,int low,int high)
{
	int partition_index;
	if(low<high)
	{
	partition_index=partition(arr,low,high);
	quick_sort(arr,low,partition_index);
	quick_sort(arr,partition_index+1,high);
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
	
	int low=0;
	int high=n-1;
	
	quick_sort(arr,low,high);
	display(arr,n);
	
	return 0;
}
