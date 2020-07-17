#include <bits/stdc++.h>
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
int length(node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len+=1;
    }
    return len;
}
void insertathead(node*&head,int data)
{
	node*n =new node(data);
	n->next=head;
	head=n;
}
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
void insertinmiddle(node*&head,int data,int pos)
{
    if(head==NULL||pos==0)
    {
        insertathead(head,data);
    }
    else if(pos>length(head))
    {
        insertattail(head,data);
    }
    else
    {
        int jump=1;
        node*tail=head;
        while(jump<=pos-1){
            tail=tail->next;
            jump+=1;
        }
        node*n=new node(data);
        n->next=tail->next;
        tail->next=n;
    }
}
void deleteathead(node*&head)
{
    node*temp=head;
    head=head->next;
    delete temp;
}
void deleteattail(node*&head)
{
    node*prev=NULL;
    node*temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;
}
void deleteatmiddle(node*&head,int pos)
{
    if(pos>length(head))
    {
        deleteattail(head);
    }
    else if(head==NULL)
    return;
    else if(pos==1)
    deleteathead(head);
    else
    {
    int jump=1;
     node*prev=NULL;
    node*temp=head;
    while(jump<=pos-1)
    {
        prev=temp;
        temp=temp->next;
        jump+=1;
    }
    prev->next=temp->next;
    delete temp;
    }
}
node*buildlist(node*&head)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertattail(head,data);
        cin>>data;
    }
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
istream& operator>>(istream &is,node*&head)
{
    buildlist(head);
    return is;
}
ostream& operator<<(ostream &os,node*&head)
{
    print(head);
    return os;
}
void reverse(node*&head)
{
    node*P=NULL;
    node*C=head;
    node*N;
    while(C!=NULL)
    {
        N=C->next;
        C->next=P;
        P=C;
        C=N;
    }
    head=P;
}
int middleelement(node*&head)
{
    if(head==NULL||head->next==NULL)
    {
        return head->data;
    }
    node*fast=head->next;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int findknode(node*&head,int k)
{
    if(head==NULL||head->next==NULL)
    return head->data;
    node*fast=head;
    node*slow=head;
    int t=k;
    while(t--)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
node* merge(node*a,node*b)
{
    if(a==NULL)
    return b;
    else if(b==NULL)
    return a;
    
    node*c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

int main()
{
    node* head=NULL;
    node*head2=NULL;
    cin>>head>>head2;
    cout<<head<<endl<<head2<<endl;
    head =merge(head,head2);
    cout<<head;
    /*insertathead(head,5);
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,19);
    insertattail(head,8);
    insertattail(head,10);
    insertinmiddle(head,2,3);
    //deleteatmiddle(head,1);
    //deleteattail(head);
    print(head);
    cout<<endl;
    /*reverse(head);
    print(head);
    cout<<endl;
    cout<<middleelement(head);
    cout<<endl;
    cout<<findknode(head,3);*/
    //head=merge
    return 0;
}

