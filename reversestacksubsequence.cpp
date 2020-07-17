#include <bits/stdc++.h>
using namespace std;
int a[100];
int b[100];
int c[100];
int size(int arr[]){
	int i=0;
	while(arr[i]!=0){
		i++;
	}
	return i;
}
int top(int arr[]){
	int i=size(arr);
	return arr[i-1];
}

void push(int arr[],int value){
	int i=size(arr);
	arr[i]=value;
}
void pop(int arr[]){
	int i=size(arr);
	if(i==0){
		return;
	}
	arr[i-1]=0;
}
show(int s[]){
	if(!size(s))
		cout<<"Stack empty"<<endl;
	else{
		int i = size(s);
		cout<<"Stack: ";
		while(i){
		cout<<s[i-1]<<" ";
		i--;
		}
		cout<<endl;
	}
}
reverse(int x,int y){
	int j;
	j=size(a);
	for (int i=0;i<y+1;i++){
		push(b,top(a));
		pop(a);
		
		
	}
	
	for(int i=0;i<y-x+1;i++){
		push(c,top(b));
		pop(b);
		
	}
	
	j=size(c);
	for(int i=0;i<j;i++){
		push(a,top(c));
		pop(c);
	}
	
	j=size(b);
	for(int i=0;i<j;i++){
		push(a,top(b));
		pop(b);
	}
	show(a);
}


int main(){
	cout<<"Enter size of stack: ";
	int n,value;
	cin >>n;
	cout<<"Enter elements of stack: ";
	for (int i=0;i<n;i++){
		cin>>value;
		push(a,value);
	}
	show(a);
	cout<<"Enter index for reverse(starting from '0'): ";
	int x,y;
	cin>>x>>y;
	reverse(x,y);
}
