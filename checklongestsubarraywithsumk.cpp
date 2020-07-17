#include<bits/stdc++.h>
using namespace std;
int checklongestsubarraywithsumk(int *a,int n,int k)
{
    unordered_map<int,int> s;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(pre==k)
        len=max(len,i+1);
        if(s.find(pre-k)!=s.end())
        len=max(len,i-s[pre-k]);
        else
        s[pre]=i;
    }
    return len;
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
    int k;
    cin>>k;
    int b=checklongestsubarraywithsumk(a,n,k);
    cout<<b<<endl;
}
