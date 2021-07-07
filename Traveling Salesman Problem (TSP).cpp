#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V],int s)
{
	vector<int> vertex;
	for(int i=0;i<V;i++)
	{
		if(i!=s)
		{
			vertex.push_back(i);
		}
	}
	int min_path=INT_MAX;
	do
	{
		int k=s;
		int currentpath_cost=0;
		for(int i=0;i<vertex.size();i++)
		{
			currentpath_cost+=graph[k][vertex[i]];
			k=vertex[i];
		}
		currentpath_cost+=graph[k][s];
		min_path=min(min_path,currentpath_cost);
	}while(next_permutation(vertex.begin(),vertex.end()));
	
	return min_path;
}

int main()
{
	// matrix representation of graph weights
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
