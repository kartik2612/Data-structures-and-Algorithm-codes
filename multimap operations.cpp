#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main()
{
	multimap<int,int> m;
	m.insert({1,1});
	m.insert({2,2});
	m.insert({3,3});
	m.insert({4,4});
	m.insert({5,5});
	m.insert({5,6});
	multimap<int,int> :: iterator iter;
	cout<<"elements of map m after insertion"<<endl;
	for(iter=m.begin();iter!=m.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	cout<<"the size of map m is"<<endl;
	int size=m.size();
	cout<<size<<endl;
	multimap<int,int> m1(m.begin(),m.end());
	cout<<"elements in map m1 are"<<endl;
	for(iter=m1.begin();iter!=m1.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	m.erase(m.begin(),m.find(3));
	cout<<"elements of map m after erase are"<<endl;
	for(iter=m.begin();iter!=m.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	m1.erase(3);
	cout<<"elements of m1 after erasing 3 are "<<endl;
	for(iter=m1.begin();iter!=m1.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	cout<<"the count of 3 is"<<endl;
	int k=m.count(3);
	cout<<k<<endl;
	return 0;
}
