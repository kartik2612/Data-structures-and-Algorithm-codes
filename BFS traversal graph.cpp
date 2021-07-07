#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Graph
{
	public:
		int v;
		list<int> *adj;
		Graph(int v);
		void addEdge(int u,int w);
		void BFS(int s);
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

void Graph :: BFS(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	list<int> :: iterator it;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				queue.push_back(*it);
			}
		}
	}
}
int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    
    return 0;
}
