#include<bits/stdc++.h>
using namespace std;

void bucketsort(float arr[],int n)
  {
  	vector<float> b[n];

	for(int i=0;i<n;i++)
	{
		int bi=n*arr[i];
		b[bi].push_back(arr[i]);
	}
	for(int i=0;i<n;i++)
	sort(b[i].begin(),b[i].end());
	
	int index=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
		 arr[index++]=b[i][j];
		}
	}
 }
 
 int main()
 {
 	cout<<"Enter the number of elements you want to store: "<<endl;
 int n;
 cin>>n;
 cout<<"Enter elements between 0 and 1: "<<endl;
 float a[n]; 
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
 }
 	bucketsort(a,n);
 	for(int i=0;i<n;i++)
 	{
 		cout<<a[i]<<" ";
	}
 }
