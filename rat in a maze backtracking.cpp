#include<iostream>
using namespace std;
#define N 4

void printsol(int sol[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<sol[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool isSafe(int maze[N][N],int x,int y,int sol[N][N])
{
	if(x>=0&&x<N&&y>=0&&y<N&&maze[x][y]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool solveRMutil(int maze[N][N],int x,int y,int sol[N][N])
{
	if(x==N-1&&y==N-1)
	{
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y,sol)==true)
	{
		sol[x][y]=1;
		if(solveRMutil(maze,x+1,y,sol)==true)
		{
			return true;
		}
		if(solveRMutil(maze,x,y+1,sol)==true)
		{
			return true;
		}
		sol[x][y]=0;
		return false;
	}
	return false;
}

int solveMaze(int maze[N][N])
{
	int sol[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			sol[i][j]=0;
		}
	}
	if(solveRMutil(maze,0,0,sol)==false)
	{
		cout<<"no solution exits"<<endl;
		return 0;
	}
	else
	{
		printsol(sol);
	}
	return 0;
} 

int main() 
{ 
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                    { 1, 1, 0, 1 }, 
                    { 0, 1, 0, 0 }, 
                    { 1, 1, 1, 1 } }; 
 
    solveMaze(maze); 
    return 0; 
} 
