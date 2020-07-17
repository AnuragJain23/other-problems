#include<bits/stdc++.h>
using namespace std;
class node{
public:
     int data;
     node* next;
     
     node(int d)
     {
         data=d;
         next=NULL;
     }
};
void insertattail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
void print(node*head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	
}
void insert(node*&head,node*newnode)
{
    node*current;
    if(head==NULL||head->data >=newnode->data)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        current=head;
        while(current->next!=NULL || current->next->data < newnode->data)
        {
            current =current->next;
        }
        newnode->next=current->next;
        current->next=newnode;        
    }
}
void insertionsort(node*&head)
{
    node*sorted=NULL;
    node*current=head;
    while(current!=NULL)
    {
        node*next=current->next;
        insert(head,current);
        current=next;
    }
    head=sorted;
}
int main() {
    node*head=NULL;
	int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insertattail(head,data);
    }
   insertionsort(head);
   print(head);
}
