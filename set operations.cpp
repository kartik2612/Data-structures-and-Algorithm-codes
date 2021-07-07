#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main()
{
	set<int,int> s;
	s.insert(2);
	s.insert(1);
	s.insert(6);
	s.insert(4);
	s.insert(3);
	set<int> :: iterator iter;
	cout<<"elements of set s after insertion"<<endl;
	for(iter=s.begin();iter!=s.end();iter++)
	{
		cout<<*iter<<endl;
	}
	cout<<"the size of set s is"<<endl;
	int size=s.size();
	cout<<size<<endl;
	set<int> s1(s.begin(),s.end());
	cout<<"elements in set s1 are"<<endl;
	for(iter=s1.begin();iter!=s1.end();iter++)
	{
		cout<<*iter<<endl;
	}
	s.erase(s.begin(),s.find(3));
	cout<<"elements of set s after erase are"<<endl;
	for(iter=s.begin();iter!=s.end();iter++)
	{
		cout<<*iter<<endl;
	}
	s1.erase(4);
	cout<<"elements of s1 after erasing 4 are "<<endl;
	for(iter=s1.begin();iter!=s1.end();iter++)
	{
		cout<<*iter<<endl;
	}
	cout<<"the count of 2 is"<<endl;
	int k=s.count(3);
	cout<<k<<endl;
	return 0;
}
