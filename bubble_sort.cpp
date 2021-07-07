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

int bubble_sort(int *arr,int n)
{
	for(int i=0;i<n-1;i++) //for no. of passess
	{
		for(int j=0;j<n-1-i;j++)  //for no. of comparisions in each passess
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);;//swapping
			}
		}
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
	
    bubble_sort(arr,n);
	display(arr,n);
	
	return 0;	
}
