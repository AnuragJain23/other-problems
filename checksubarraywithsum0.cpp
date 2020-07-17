#include<bits/stdc++.h>
using namespace std;
bool checksubarraywithsumzero(int *a,int n)
{
    unordered_set<int> s;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(pre==0 or s.find(pre)!=s.end())
        {
            return true;
        }
        s.insert(pre);
    }
    return false;
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
    bool b=checksubarraywithsumzero(a,n);
    if(b==0)
    cout<<"NO";
    else
    cout<<"YES";
}
