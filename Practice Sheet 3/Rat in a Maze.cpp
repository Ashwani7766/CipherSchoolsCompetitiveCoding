//Ques.7) Rat in a Maze.
//Sol.
#include<bits/stdc++.h>
using namespace std;
void printSolution(int** solution,int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<solution[i][j] << " ";
    }
    cout<<endl;
  }
}
void MazeUtil(int maze[][20],int** solution,int x,int y,int n)
{
  if(x==n-1 && y == n-1)
  {
    solution[x][y] = 1;
    printSolution(solution,n);
    cout<<endl;
  }
  
  if(x >=n || y >= n || x < 0 || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
  {
    return;
  }
    solution[x][y] = 1;
  MazeUtil(maze,solution,x+1,y,n);
  MazeUtil(maze,solution,x,y+1,n);
  MazeUtil(maze,solution,x-1,y,n);
  MazeUtil(maze,solution,x,y-1,n);
  solution[x][y] = 0;
  }
void RatInAMaze(int maze[][20] , int n)
{
  int** solution = new int*[n];
  for(int i=0;i<n;i++)
  {
    solution[i] = new int[n]; 
  }
  int *flag = new int(9);
  MazeUtil(maze,solution,0,0,n);
  }
int main() {
  int maze[][20] = {{1,0,0,0},
                    {1,1,0,1},
                    {1,1,0,0},
                    {0,1,1,1}};
  RatInAMaze(maze,4);
    return 0;
}
