#include<bits/stdc++.h>
using namespace std;
class Stack
{
	queue<int> q1,q2;
	int curr_size;
	
	public:
		Stack()
		{
			curr_size=0;
		}
		void push(int x)
		{
			curr_size++;
			q2.push(x);
			while(!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
			queue<int> q=q1;
			q1=q2;
			q2=q;
		}
		int pop()
		{
			if(q1.empty())
			{
			cout<<"stack is empty"<<endl;
			exit(1);
		    }
			int front =q1.front();
             q1.pop();
			return front;
		}
		int top()
		{
			return q1.front();
		}
		int size()
		{
			return curr_size;
		}
		void display()
		{
			queue<int> q3=q1;
				if(q1.empty())
			{
			cout<<"stack is empty"<<endl;
			exit(1);
		    }
		    while(!q3.empty())
		    {
		    	cout<<q3.front()<<" ";
		    	q3.pop();
			}
			cout<<endl;
		}
};
int main()
{
	Stack s;
	     cout<<"press 1 for push data"<<endl;
   cout<<"press 2 for pop data"<<endl;
 cout<<"press 3 for top value"<<endl;
 cout<<"press 4 for exit"<<endl;
   while(1)
   {
     int x;
     cout<<"what do u want to do"<<endl;
     cin>>x;
     switch(x)
     {
       case 1:
       {
          int y;
         cout<<"enter data"<<endl;
         cin>>y;
         s.push(y);
         s.display();
         break;
       }
       case 2:
       {
       	  cout<<s.pop()<<" popped from stack"<<endl;
       	  s.display();
         break; 
       }
       case 3:
       {
        cout<<s.top()<<" is top element of stack"<<endl;;
        break;
       }
       case 4:
       {
         exit(0);
         break;
       }
     
     }
   }
    return 0; 
} 
