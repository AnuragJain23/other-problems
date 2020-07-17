#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
node* buildtree(){
	int d;
	cin>>d;
	node*root=new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
	node*f=q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;
	if(c1!=-1){
	f->left=new node(c1);
	q.push(f->left);
	}
	if(c2!=-1){
	f->right=new node(c2);
	q.push(f->right);
	}
	}
	return root;
}
node*build(int a[],int i,int n)
{
    if(a[i]==-1)
    return NULL;
    node*root=new node(a[i]);
    if(2*i+1<n)
    root->left=build(a,2*i+1,n);
    if(2*i+2<n)
    root->right=build(a,2*i+2,n);
    return root;
}
void leftviewfunc(node*root,int level,int*maxlevel)
{
    if(root==NULL)
    return;
    if(*maxlevel<level)
    {
        cout<<root->data<<" ";
        *maxlevel=level;
    }
    leftviewfunc(root->left,level+1,maxlevel);
    leftviewfunc(root->right,level+1,maxlevel);
}
void leftview(node*root)
{
    int maxlevel=0;
    leftviewfunc(root,1,&maxlevel);
}
int main() {
    node*root=buildtree();
    leftview(root);
	return 0;
}
