#include<iostream>
using namespace std;
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void merge(int *a,int low,int high,int mid)
{
	int i,j,k;
	int b[100];
	i=low;
	k=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]>a[j])
	    {
	    	b[k]=a[j];
	    	j++;
	    	k++;
		}
		else
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(int i=low;i<=high;i++)
	{
		a[i]=b[i];
	}
}

void merge_sort(int *a,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high,mid);
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
	
	merge_sort(arr,low,high);
	display(arr,n);
	
	return 0;
}
