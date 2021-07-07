#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Graph
{
	public:
		int v;
		list<int> *adj;
		Graph(int k);
		void addEdge(int u,int w);
		void DFS(int s);
		void DFS_recur(int s,bool *visited);
};

Graph :: Graph(int k)
{
	v=k;
	adj=new list<int>[v];
}

void Graph :: addEdge(int u,int w)
{
	adj[u].push_back(w);
}

void Graph ::  DFS_recur(int s,bool *visited)
{
	visited[s]=true;
	cout<<s<<" ";
	list<int> :: iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
		   DFS_recur(*it,visited);
	    }
	}
}

void Graph :: DFS(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	DFS_recur(s,visited);
}

int main()
{
	Graph g=Graph(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}
