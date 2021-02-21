/* C++ code to tell wether there a path exists or not for the rat to travel to the end of the maze */

#include<bits/stdc++.h>
using namespace std;

# define N 4

void display(int soln[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int maze[N][N],int x,int y)
{
    return (x>=0 and y>=0 and x<N and y<N and maze[x][y]==1);
}

bool helper(int maze[N][N],int x,int y,int soln[N][N])
{
    if(x==N-1 and y==N-1 and maze[x][y]==1)
    {
        soln[x][y]=1;
        return true;
    }

    if(isSafe(maze,x,y))
    {

        if(soln[x][y]==1)
        {
            return false;
        }

        soln[x][y]=1;

        if(helper(maze,x+1,y,soln))
            return true;

        if (helper(maze, x, y+1, soln))
            return true;

        if (helper(maze, x - 1, y, soln))
            return true;

        if (helper(maze, x, y-1, soln))
            return true;
        
        soln[x][y]=0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N])
{
    int soln[N][N]={0};


    if(helper(maze,0,0,soln))
    {
        display(soln);
        return true;
    }
    else
    {
        cout<<"No ways possible!"<<endl;
        return false;
    }
}

int main()
{
    int maze[N][N]={{1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 1, 1}};

    solveMaze(maze);
    return 0;
}
