#include<bits/stdc++.h>
using namespace std;
struct Queue
{
	stack<int> s1,s2;
	void enqueue(int x)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue()
	{
		if(s1.empty())
		{
		cout<<"q is empty"<<endl;
		exit(1);
	    }
	    int front=s1.top();
	    s1.pop();
	    return front;
	}
	int tope()
	{
	   if(s1.empty())
		{
		cout<<"q is empty"<<endl;
		exit(1);
	    }
		return s1.top();
	}
	void display()
	{
		stack<int> s3=s1;
		while(!s3.empty())
		{
		cout<<s3.top()<<" ";
		s3.pop();
	    }
	    cout<<endl;
	}
};
int main()
{
	Queue q;
   int choice, value;
    cout<<"press 1 for enqueue data"<<endl;
   cout<<"press 2 for dequeue data"<<endl;
 cout<<"press 3 for top element"<<endl;
 cout<<"press 4 for exit"<<endl;
   while(1){
      printf("what do u want to do:\n");
      scanf("%d",&choice);
      switch(choice){
	  case 1:
	        {
	         printf("Enter the value to be insert: ");
		      scanf("%d", &value);
		       q.enqueue(value);
		       q.display();
		     break;
		    }
	  case 2: 
	           {
			   cout<<q.dequeue()<<" is dequeued from queue"<<endl;
			   q.display();
	        break;
	          }
	  case 3: {
	          cout<<q.tope()<<" is the top element of queue"<<endl;
	          break;
	         }
	  case 4: {
	          exit(0);
	         }
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
   return 0;
}
