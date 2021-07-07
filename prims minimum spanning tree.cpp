#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
typedef pair<int,int> ipair;

class Graph
{
	public:
		int v;
		Graph(int k);
		list<pair<int,int> > *adj;
		void addEdge(int u,int v,int w);
		void primMST();
};

Graph :: Graph(int k)
{
	v=k;
	adj=new list<ipair>[v];
}

void Graph :: addEdge(int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph :: primMST()
{
	priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
	vector<int> key(v,INT_MAX);
	vector<int> parent(v,-1);
	vector<bool> isMST(v,false);
	int s=0;
	key[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		isMST[u]=true;
		list<pair<int,int> > :: iterator it;
		for(it=adj[u].begin();it!=adj[u].end();it++)
	    {
	    	int v=(*it).first;
	    	int weight=(*it).second;
	    	if(isMST[v]==false && key[v]>weight)
	    	{
	    		key[v]=weight;
	    		pq.push(make_pair(key[v],v));
	    		parent[v]=u;
			}
	    }
	}
	for(int i=1;i<v;++i)
	{
		cout<<parent[i]<<"->"<<i<<endl;
	}
}

int main()
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g=Graph(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.primMST(); 
  
    return 0; 
} 
