#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void enqueue(int);
void dequeue();
void display();

int main()
{
   int choice, value;
    cout<<"press 1 for enqueue data"<<endl;
   cout<<"press 2 for dequeue data"<<endl;
 cout<<"press 3 for exit"<<endl;
   while(1){
      printf("what do u want to do: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1:
	        {
	         printf("Enter the value to be insert: ");
		      scanf("%d", &value);
		       enqueue(value);
		      display();
		     break;
		    }
	 case 2: 
	           {
			   dequeue();
	         display();
	        break;
	          }
	 case 3: {
	          exit(0);
	         }
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
   return 0;
}
void enqueue(int value)
{
   struct Node* newNode=new Node();
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
}
void dequeue()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
