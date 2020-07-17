#include<bits/stdc++.h>
using namespace std;
string minwindowsubarray(string str,string pat)
{
   int len1=str.size();
   int len2=pat.size();
   int hash_str[256]={0};
   int hash_pat[256]={0};
   if(len1<len2)
   return "No window";
   for(int i=0;i<len2;i++)
   hash_pat[pat[i]]+=1;
   int start=0,start_index=-1,minlen=INT_MAX,count=0;
   for(int j=0;j<len1;j++)
   {
       hash_str[str[j]]+=1;
       if(hash_pat[str[j]]!=0 and hash_str[str[j]]<=hash_pat[str[j]])
       count+=1;
       if(count==len2)
       {
           while(hash_str[str[start]]>hash_pat[str[start]] or hash_pat[str[start]]==0)
           {
               if(hash_str[str[start]]>hash_pat[str[start]])
              { 
                  hash_str[str[start]]-=1;
              }
               start+=1;
           }
           int len_window=j-start+1;
           if(minlen>len_window)
           {
               minlen=len_window;
               start_index=start;
           }
       }
   }
   if(start_index==-1)
   return "No window";
   
   return str.substr(start_index,minlen);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<minwindowsubarray(s1,s2)<<endl;
    return 0;
}
