#include<bits/stdc++.h>
using namespace std;
int getmax(int arr[],int n)
{
  int max=arr[0];
  for(int b=1;b<=n-1;b++)
  {
  if(max<arr[b])
  max=arr[b];
  }
  return max;
}
int main()
{
 cout<<"Enter the number of elements you want to store: "<<endl;
 int n;
 cin>>n;
 int a[n],b[n]; 
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
 }
 int k=getmax(a,n);
 cout<<k<<endl;
 int count[k+1]={0};
 for(int i=0;i<n;i++)
 count[a[i]]++;
 for(int i=1;i<=k;i++)
 count[i]+=count[i-1];
 for(int i=n-1;i>=0;i--)
 {
  b[count[a[i]]-1]=a[i];
  count[a[i]]--;
 }
 cout<<"sorted array is: "<<endl;
 for(int i=0;i<n;i++)
 {
   cout<<b[i]<<" ";
 }
 cout<<endl;
}
