#include <bits/stdc++.h>
using namespace std;
int q[100];
int q1[100];
int q2[100];
int size(int a[]){
	int i=0;
	while(a[i]!=0){
		i++;
	}
	return i;
}
void print(int arr[]){
	int i=size(arr);
	if(i==0){
		cout<<"Empty Queue"<<endl;
		return;
	}
	cout<<"Queue: ";
	for(int j=0;j<i;j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
}
void enqueue(int arr[],int value){
	int i=size(arr);
	arr[i]=value;
}
int dequeue(int arr[]){
	int i=size(arr);
	
	int n=arr[0];
	int j;
	
	for (j=0;j<i;j++){
		arr[j]=arr[j+1];
	}
	arr[j]=0;
	return n;
}
void swap(int x,int y){
	int j=size(q);
	for (int i=0;i<y;i++){
		enqueue(q1,dequeue(q));	
	}
	for (int i=0;i<j-y;i++){
		enqueue(q2,dequeue(q));
	}
	for (int i=0;i<x;i++){
		enqueue(q,dequeue(q1));
	}
	enqueue(q,dequeue(q2));
	enqueue(q2,dequeue(q1));
	j=size(q1);
	for (int i=0;i<j;i++){
		enqueue(q,dequeue(q1));
	}
	j=size(q2);
	for (int i=0;i<j-1;i++){
		enqueue(q1,dequeue(q2));
	}
	enqueue(q,dequeue(q2));
	j=size(q1);
	for (int i=0;i<j;i++){
		enqueue(q,dequeue(q1));
	}
}
reverse(int x,int y){
	int a,b;
	int k = y-x+1;
	if(k%2!=0){
		b=x-1+k/2;
		a=b+2;
	}
	else{
		b=x-1+k/2;
		a=b+1;
	}
	
		for(int i=0;i<k/2;i++){
		swap(b,a);
		b--;
		a++;
		}
}
int main(){
	int n,x,y;
	cout<<"Enter size of queue: ";
	cin>>n;
	cout<<"Enter elements of queue: ";
	for (int i=0;i<n;i++){
		cin>>q[i];
	}
	print(q);
	cout<<"Enter indices of elements to be swapped (starting with zero): ";
	cin>>x>>y;
	reverse(x,y);
	print(q);
	return 0;	
}

