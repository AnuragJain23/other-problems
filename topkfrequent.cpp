/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first==p2.first)
    return p1.second<p2.second;
    else
    {
        return p1.first>p2.first;
    }
}
int main()
{
    int a[200]={0};
    int n;
    cin>>n;
    int arr[n];
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        a[arr[i]]++;
    }
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            v.push_back(make_pair(a[i],i));
        }
    }
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i].second<<","<<v[i].first<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].second<<","<<v[i].first<<endl;
    }
    return 0;
}
