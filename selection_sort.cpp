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

void selection_sort(int *arr,int n)
{
	int i,j,min_index;
	for(i=0;i<n-1;i++)
	{
		min_index=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min_index]>arr[j])
			{
				min_index=j;
			}
		}
		swap(&arr[i],&arr[min_index]);
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
	
	selection_sort(arr,n);
	display(arr,n);
	
	return 0;
}
