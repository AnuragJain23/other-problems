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
bool search(Node* head,int x)
{
	Node* current=head;
	while(current!=NULL)
	{
		if(current->data==x)
		return true;
		current=current->next;
	}
	return false;
}
void deleteakey(Node **head_ref,int key)
{
	Node* temp=*head_ref,*prev;
	while(temp!=NULL&&temp->data==key)
	{
		*head_ref=temp->next;
		free(temp);
		temp=*head_ref;
	}
	while(temp!=NULL)
	{
		while(temp!=NULL&&temp->data!=key)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		return;
		prev->next=temp->next;
		free(temp);
		temp=prev->next;
	}
	
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
	cout<<"what u want to do in list"<<endl;
	cout<<"press 1 for adding value"<<endl;
	cout<<"press 2 for searching an element"<<endl;
	cout<<"press 3 for deleting an element"<<endl;
	cout<<"press 4 for exit the program"<<endl;
	int new_data,x;
	while(1)
	{
	int a;
	cout<<"what u want to do in list"<<endl;
	cin>>a;
	switch(a)
	  { 
		case 1: 
		    {
			    addattail(&head,new_data);
			    printlist(head);
			    cout<<endl;
		        break;
		    }
		    case 2:
		    	{   cout<<"enter value u want to search"<<endl;
		    	     int x;
		    	     cin>>x;
		    		search(head,x)?cout<<"yes":cout<<"no";
		    		cout<<endl;
		    		break;
				}
				case 3:
					{
						cout<<"enter value u want to delete"<<endl;
		    	         int key;
		    	        cin>>key;
					    deleteakey(&head,key);
						printlist(head);
			            cout<<endl;
		                break;
					}
				case 4:
				{
					exit(0);
					break;
			    }	
		default: 
		{
		cout<<"invalid input"<<endl;
		break;
	    }
	  } 
   }
	return 0;
	
}
