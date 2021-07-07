#include<iostream>
using namespace std;
#define N 8

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

int isSafe(int x,int y,int sol[N][N])
{
	if(x>=0&&x<N&&y>=0&&y<N&&sol[x][y]==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int solveKTutil(int x,int y,int imove,int xmove[8],int ymove[8],int sol[N][N])
{
	int x_move,y_move;
	if(imove==(N*N))
	{
		return 1;
	}
	for(int i=0;i<8;i++)
	{
		x_move=x+xmove[i];
		y_move=y+ymove[i];
		if(isSafe(x_move,y_move,sol))
		{
			sol[x_move][y_move]=imove;
			if(solveKTutil(x_move,y_move,imove+1,xmove,ymove,sol)==1)
			{
				return 1;
			}
			else
		    {
			    sol[x_move][y_move]=-1;
		    }
		}
	}
	return 0;
}

int solveKT()
{
	int sol[N][N];
    for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			sol[i][j]=-1;
		}
	}	
	sol[0][0]=0;
	int xmove[8]={2, 1, -1, -2, -2, -1, 1, 2};
	int ymove[8]={1, 2, 2, 1, -1, -2, -2, -1};
	if(solveKTutil(0,0,1,xmove,ymove,sol)==0)
	{
		cout<<"no solution exist";
		return 0;
	}
	else
	{
		printsol(sol);
	}
	return 1;
}

int main()
{
	solveKT();
	return 0;
}
