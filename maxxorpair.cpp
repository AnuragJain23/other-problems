/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode*left;
    trienode*right;
};
void insert(int n,trienode*head)
{
    trienode*curr=head;
    for(int j=31;j>=0;j--)
    {
        int bit=(n >> j) & 1;
        if(bit==0)
        {
            if(curr->left==NULL)
            {
                curr->left=new trienode();
            }
            curr=curr->left;
        }
        else
        {
            if(curr->right==NULL)
            {
                curr->right=new trienode();
            }
            curr=curr->right;
        }
    }
}
int findmaxxorpair(trienode*head,int *a,int n,int el)
{
    int max_xor=INT_MIN;
    trienode*curr=head;
    int value=el;
    int curr_xor=0;
    for(int j=31;j>=0;j--)
    {
        int b=(value >> j) & 1;
        if(b==0)
        {
            if(curr->right!=NULL)
            {
                curr=curr->right;
                curr_xor+=(int)pow(2,j);
            }
            else
            curr=curr->left;
        }
        else
        {
            if(curr->left!=NULL)
            {
                curr=curr->left;
                curr_xor+=(int)pow(2,j);
            }
            else
            curr=curr->right;
        }
    }
    if(max_xor<curr_xor)max_xor=curr_xor;
    return max_xor;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    trienode*head=new trienode();
    int result=INT_MIN;
    for(int i=0;i<n;i++)
    {
        insert(a[i],head);
        int x=findmaxxorpair(head,a,n,a[i]);
        result=(result<x)?x:result;
    }
    cout<<result<<endl;

    return 0;
}

