#include<bits/stdc++.h> 

using namespace std; 

class Graph 
{ 
	int v; // No. of vertices 
	list<int> *adj; // Pointer to an array containing adjacency lists 
	bool iscyclicutil(int s, bool *visited, int parent); // used by isCyclic() 
public: 
	Graph(int k); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	bool iscyclic(); // returns true if there is a cycle in this graph 
}; 

Graph::Graph(int k) 
{ 
	v=k; 
	adj = new list<int>[v]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

bool Graph :: iscyclicutil(int s,bool *visited,int parent)
{
	visited[s]=true;
	list<int> :: iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it] && iscyclicutil(*it,visited,s))
		{
			return true;
		}
		else if(*it!=parent)
		{
			return true;
		}
	}
	return false;
}

bool Graph :: iscyclic()
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			if(iscyclicutil(i,visited,-1))
			{
				return true;
			}
		}
	}
	return false;
}

int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	if(g.iscyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 
