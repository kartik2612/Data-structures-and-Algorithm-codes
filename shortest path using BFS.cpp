#include<iostream>
#include<vector>
#include<list>
using namespace std;

void add_edge(vector<int> adj[],int u,int w)
{
	adj[u].push_back(w);
	adj[w].push_back(u);
}

bool BFS(vector<int> adj[],int v,int pred[],int dist[],int s,int d)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		pred[i]=-1;
		dist[i]=INT_MAX;
	}
	visited[s]=true;
	dist[s]=0;
	list<int> queue;
	queue.push_back(s);
	while(!queue.empty())
	{
		int u=queue.front();
		queue.pop_front();
		for(int i=0;i<adj[u].size();i++)
		{
			if(visited[adj[u][i]]==false)
			{
				visited[adj[u][i]]=true;
				dist[adj[u][i]]=dist[u]+1;
				pred[adj[u][i]]=u;
				queue.push_back(adj[u][i]);
				if(adj[u][i]==d)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void shortest_path(vector<int> adj[],int v,int s,int d)
{
	int pred[v],dist[v];
	if(BFS(adj,v,pred,dist,s,d)==false)
	{
		cout<<"the source and destination are not connected"<<endl;
	}
	vector<int> path;
	int kk=d;
	path.push_back(kk);
	while(pred[kk]!=-1)
	{
		path.push_back(pred[kk]);
		kk=pred[kk];
	}
	cout<<"the shortest distance is "<<dist[d]<<endl;
	cout<<"ans the path is "<<endl;
	for(int i=path.size()-1;i>=0;i--)
	{
		cout<<path[i]<<"->";
	}
}

int main()
{
	// no. of vertices
    int v = 8;
 
    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];
 
    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0, dest = 7;
    shortest_path(adj,v,source,dest);
    return 0;
    
}
