#include<bits/stdc++.h>
using namespace std;
int gmax(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	return max;
}
void countsort(int a[],int n,int pos)
{
	int b[n],i,count[10]={0};
	for(i=0;i<n;i++)
	count[(a[i]/pos)%10]++;
	for(i=1;i<10;i++)
	count[i]+=count[i-1];
	for(i=n-1;i>=0;i--)
	{
		b[count[(a[i]/pos)%10]-1]=a[i];
		count[(a[i]/pos)%10]--;
	}
	for(i=0;i<n;i++)
	a[i]=b[i];
}
void radixsort(int a[], int n)
{
	int pos, m;
	m = gmax(a, n);
	for (pos = 1; m/pos > 0; pos *= 10)
		countsort(a, n, pos);
}
int main()
{
	cout<<"Enter the number of elements you want to store: "<<endl;
 int n;
 cin>>n;
 int a[n]; 
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
 }
	radixsort(a,n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

