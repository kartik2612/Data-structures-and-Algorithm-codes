#include<iostream>
#include<limits>
#include<vector>
using namespace std;
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int max_ele(int *a,int n)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

void count_sort(int *a,int n)
{
	int maxx=max_ele(a,n);
	vector<int> vec(maxx+1,0);
	for(int i=0;i<n;i++)
	{
		vec[a[i]]=vec[a[i]]+1;
	}
	int i=0; //for tracing count array
	int j=0;  //for tracing a array
	while(i<=maxx)
	{
		if(vec[i]>0)
		{
			vec[i]=vec[i]-1;
			a[j]=i;
			j++;
		}
		else
		{
			i++;
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
	
	count_sort(arr,n);
	display(arr,n);
	
	return 0;
}
