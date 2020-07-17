

#include <bits/stdc++.h>
using namespace std;
bool issafe(int board[][10],int i,int j,int n)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        return false;
        
        x--;
        y--;
    }
    x=i;
    y=j;

    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        return false;
        
        x--;
        y++;
    }
    
    return true;
}
bool solveratproblem(char maze[][10],int solution[][10],int i,int j,int m,int n)
{
    if(i==m && j==n)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return true;
    }
    
    if(i>m || j>n)
    return false;
    
    if(maze[i][j]=='X')
    return false;
    
    solution[i][j]=1;
    
    bool rightsol=solveratproblem(maze,solution,i,j+1,m,n);
    bool downsol=solveratproblem(maze,solution,i+1,j,m,n);
    
     solution[i][j]=0;
     
    if(rightsol||downsol)
    return true;
    
   return false;
    
}

int main()
{
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    
    int solution[10][10]={0};
    int m=4,n=4;
    bool ans=solveratproblem(maze,solution,0,0,m-1,n-1);
    if(ans==false)
    cout<<"Path does not exist"<<endl;
    return 0;
}

