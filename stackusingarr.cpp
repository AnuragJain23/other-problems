#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
    void display();
}; 
  
void Stack::display()
  {
  	for(int i=top;i>=0;i--)
  	{
	cout<<a[i]<<" ";
    }
    cout<<endl;
  }
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout<< "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
     cout<<"press 1 for push data"<<endl;
   cout<<"press 2 for pop data"<<endl;
 cout<<"press 3 for peek value"<<endl;
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
         cout<< s.pop() << " popped from stack" <<endl;
         s.display();
         break; 
       }
       case 3:
       {
        cout<<s.peek()<<endl;
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
