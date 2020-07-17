/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int r;
int c;
void print(char mat[][50])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           cout<<mat[i][j];
        }
        cout<<endl;
    }
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void floodfill(char input[][50],int i,int j,char chtobechanged,char chchangedwith)
{
    if(i<0||j<0||i>=r||j>=c)
    return;
    
    if(input[i][j]!=chtobechanged)
    return;
    
    input[i][j]=chchangedwith;
    for(int k=0;k<4;k++)
    {
        floodfill(input,i+dx[k],j+dy[k],chtobechanged,chchangedwith);
    }
}
int main()
{
    cin>>r>>c;
    char mat[20][50];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
    print(mat);
    floodfill(mat,2,4,'.','r');
    print(mat);

    return 0;
}

