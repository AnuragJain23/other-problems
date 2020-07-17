/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool issafe(int board[][10],int i,int k,int n)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][k]==1)
        {
            return false;
        }
    }
    int x=i;
    int y=k;
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=k;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solvenqueen(int board[][10],int i,int n)
{
    if(i==n)
    {
        for(int p=0;p<n;p++)
        {
            for(int k=0;k<n;k++)
            {
                if(board[p][k]==1)
                {
                    cout<<"Q ";
                }
                else
                cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    
    for(int k=0;k<n;k++)
    {
       if(issafe(board,i,k,n))
       {
           board[i][k]=1;
           bool nextqueen=solvenqueen(board,i+1,n);
           if(nextqueen)
           {
               return true;
           }
           board[i][k]=0;
       }
    }
    return false;
}

using namespace std;

int main()
{
   int n;
   cin>>n;
   int board[10][10]={0};
  solvenqueen(board,0,n);

    return 0;
}

