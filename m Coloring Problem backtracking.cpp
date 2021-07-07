#include<iostream>
using namespace std;
#define V 4

void printsol(int color[V])
{
	
	for(int i=0;i<V;i++)
	{
		cout<<color[i]<<" ";
	}
}

bool isSafe(bool graph[][V],int color[V])
{
	for(int i=0;i<V;i++)
	{
		for(int j=i+1;j<V;j++)
		{
			if(graph[i][j]&&color[j]==color[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool graphColouring(bool graph[][V],int m,int i,int color[V])
{
	if(i==V)
	{
		if(isSafe(graph,color))
		{
			printsol(color);
			return true;
		}
		return false;
	}
	for(int k=1;k<=m;k++)
	{
		color[i]=k;
		if(graphColouring(graph,m,i+1,color))
		{
			return true;
		}
		color[i]=0;
	}
	return false;
}

int main()
{
	/* Create following graph and
    test whether it is 3 colorable
    (3)---(2)
    | / |
    | / |
    | / |
    (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors
 
    // Initialize all color values as 0.
    // This initialization is needed
    // correct functioning of isSafe()
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
    if (!graphColouring(graph, m, 0, color))
        cout << "Solution does not exist";
    return 0;
}
