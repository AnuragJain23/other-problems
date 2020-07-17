/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool canplace(int sudoku[][9],int i,int j,int num,int n)
{
    for(int digit=0;digit<n;digit++)
    {
        if(sudoku[digit][j]==num || sudoku[i][digit]==num)
        return false;
    }
    
    int k=sqrt(n);
    int sx=(i/k)*k;
    int sy=(j/k)*k;
    
    for(int x=sx;x<sx+k;x++)
    {
        for(int y=sy;y<sy+k;y++)
        {
            if(sudoku[x][y]==num)
            return false;
        }
    }
    
    return true;
}

bool solvesudoku(int sudoku[][9],int i,int j,int n)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sudoku[i][j]<<", ";
            }
            cout<<endl;
        }
        
        return true;
    }
    if(j==n)
    return solvesudoku(sudoku,i+1,0,n);
    
    if(sudoku[i][j]!=0)
    return solvesudoku(sudoku,i,j+1,n);
    
    for(int num=1;num<=n;num++)
    {
        if(canplace(sudoku,i,j,num,n))
        {
            sudoku[i][j]=num;
            
            bool aagesolvehoga=solvesudoku(sudoku,i,j+1,n);
            if(aagesolvehoga==true)
            return true;
        }
    }
    sudoku[i][j]=0;
    return false;
}
int main()
{
    int sudoku[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };
    
    solvesudoku(sudoku,0,0,9);

    return 0;
}

