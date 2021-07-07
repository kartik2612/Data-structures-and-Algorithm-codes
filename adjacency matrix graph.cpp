#include<iostream>
using namespace std;
int adj[20][20];

void printarray(int v)
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

void add_edge(int u,int v)
{
	/*as it is undirected graph so we can do it both sides
	u,v and v,u*/
	adj[u][v]=1;
	adj[v][u]=1;
}

int main()
{
	int v=6;//6 vertices of graph
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);
   
   printarray(v);
   
   return 0;
}
