#include<iostream>
using namespace std;
struct myarray
{
	int totalsize;
	int usedsize;
	int *arr;
};
void create_array(struct myarray *a,int tsize,int usize)
{
	a->totalsize=tsize;
	a->usedsize=usize;
	a->arr=new int[tsize];
}
void setarray(struct myarray *a)
{
	int n;
	cout<<"enter the elements of an array"<<endl;
	for(int i=0;i<a->usedsize;i++)
	{
		cin>>n;
		a->arr[i]=n;
	}
}
void printarray(struct myarray *a)
{
	for(int i=0;i<a->usedsize;i++)
	{
		cout<<a->arr[i]<<" ";
	}
}
int main()
{
	struct myarray marks;
	create_array(&marks,100,2);
	setarray(&marks);
	printarray(&marks);
	return 0;
}
