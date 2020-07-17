#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   struct Node* next;
};
struct Node* top;
void push(int data)
   {
   struct Node* temp= new Node();
   temp->data=data;
   temp->next=top;
   top=temp;
   }
int isempty()
  {
    return top==NULL;
  } 
int peek()
 {
   return top->data;
}
void pop()
{
  struct Node* temp;
  
  if(top==NULL)
  {
  cout<<"error"<<endl;
  exit(1);
  }
  else
  {
  temp=top;
  top=top->next;
  temp->next=NULL;
  free(temp);
  }
}
void display()
{
struct Node* temp;
/*if(top==NULL)
{
 cout<<"empty"<<endl;
 exit(1);
}*/
/*else
{*/
  temp=top;
  while(temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<endl;
// }
}

int main()
{

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
         push(y);
         display();
         break;
       }
       case 2:
       {
         pop();
         display();
         break; 
       }
       case 3:
       {
        peek();
        break;
       }
       case 4:
       {
         exit(0);
         break;
       }
     
     }
   }


}

