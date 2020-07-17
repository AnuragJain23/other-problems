#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};

void addattail(Node** head_ref, int new_data)
{
	Node* new_node=new Node();
	Node *last=*head_ref;
	cout<<"enter data"<<endl;
	cin>>new_data;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	return;
}
Node *reverse (Node *head, int k)  
{  
    Node* current = head;  
    Node* next = NULL;  
    Node* prev = NULL;
	cout<<"enter how many values u want to reverse"<<endl;
	cin>>k;  
    int count = 0;  
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    if (next != NULL)  
    head->next = next;
    return prev;  
}  
void printlist(Node *node)
{
	while(node!=NULL)
			{
				cout<<node->data<<" ";
				node=node->next;
			}
}

int main()
{
	Node* head=NULL;
	int new_data,k;
	cout<<"for adding elements press 1"<<endl;
    cout<<"for reversing elements press 2"<<endl;
	cout<<"for not adding more elements press 3"<<endl;
	while(1)
	{
		int x;
		cout<<"make a choice between 1 , 2 and 3"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
	           {
			   addattail(&head,new_data);
			   printlist(head);
			   cout<<endl;
			   break;
		       }
		     case 2:
			 {
			 	head=reverse(head,k);
			 	printlist(head);
			 	cout<<endl;
			 	break;
			 }  
		    case 3:
			  {
			  	exit(0);
			  	break;
		      }
	   }
    }
    return 0;
}
