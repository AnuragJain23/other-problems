#include<bits/stdc++.h>
using namespace std;
int checklongestsubarraywithsumzero(int *a,int n)
{
    unordered_map<int,int> s;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(a[i]==0 and len==0)
        len=1;
        if(pre==0)
        len=max(len,i+1);
        if(s.find(pre)!=s.end())
        len=max(len,i-s[pre]);
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
    int b=checklongestsubarraywithsumzero(a,n);
    cout<<b<<endl;
}
