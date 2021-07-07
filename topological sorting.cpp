#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph
{
	public:
		int v;
		list<int> *adj;
		Graph(int k);
		void addEdge(int u,int w);
		void topologicalSort();
		void topoSort_util(int s,bool *visited,stack<int> &st);
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

void Graph :: topoSort_util(int s,bool *visited,stack<int> &st)
{
	visited[s]=true;
	list<int> :: iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
			topoSort_util(*it,visited,st);
		}
	}
	st.push(s);
}

void Graph :: topologicalSort()
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	stack<int> st;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			topoSort_util(i,visited,st);
		}
	}
	while(!st.empty())
    {
    	cout<<st.top()<<" ";
    	st.pop();
	}
}

int main()
{
	// Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    g.topologicalSort(); 
  
    return 0; 
}
