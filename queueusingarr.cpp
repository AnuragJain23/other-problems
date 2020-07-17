#include<bits/stdc++.h>
using namespace std;
#define Max 50

void enqueue();
void dequeue();
int top();
void display();
int q[Max];
int front=-1;
int rear=-1;
int main()
{
	cout<<"press 1 for enqueue"<<endl;
	cout<<"press 2 for dequeue"<<endl;
	cout<<"press 3 for front"<<endl;
	cout<<"press 4 for exit"<<endl;
	while(1)
	{
		int x;
		cout<<"what u want to do:"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				{
					enqueue();
					display();
					break;	
				}
		    case 2:
				{
					dequeue();
					display();
					break;	
				}
				case 3:
				{
					cout<<top()<<endl;
					break;	
				}
				case 4:
				{
					exit(1);
					break;
				}
		}
	}
}
void enqueue()
{
	int data;
	if(rear==Max-1)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		if(front==-1)
		front=0;
		cout<<"enter data"<<endl;
		cin>>data;
		rear=rear+1;
		q[rear]=data;
	}
}
void dequeue()
{
	if(front==-1)
	cout<<"queue is empty"<<endl;
	else
	{
		front=front+1;
	}
}
int top()
{
	return q[front];
}
void display()
{
	if(front==-1)
	cout<<"queue is empty"<<endl;
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<q[i]<<" ";
		}
		cout<<endl;
	}
}
