/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  char data;
  bool isterminal;
  unordered_map<char,node*> children;
  node(char data){
      this->data=data;
      this->isterminal=false;
  }
};
class trie{
  public:
  node*root;
  int count;
  trie(){
      this->root=new node('\0');
      this->count=0;
  }
  
  void addword(string str)
  {
      node*temp=root;
      for(int i=0;i<str.size();i++)
      {
          char ch=str[i];
          if(temp->children.count(ch))
          {
              temp=temp->children[ch];
          }
          else
          {
              node*n = new node(ch);
              temp->children[ch]=n;
              temp=n;
          }
      }
      temp->isterminal=true;
  }
  bool getword(string str)
  {
      node*temp=root;
      for(int i=0;i<str.size();i++)
      {
          char ch=str[i];
          if(temp->children.count(ch))
          {
              temp=temp->children[ch];
          }
          else
          {
             return false;
          }
      }
      return temp->isterminal;
  }
};
int main()
{
    trie t;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        t.addword(s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<t.getword(s)<<endl;
        
    }

    return 0;
}

