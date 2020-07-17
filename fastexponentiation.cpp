#include<bitS/stdc++.h>
using namespace std;
int power(int a,int b)
{
    if(b==0)
    return 1;

    int halfpower=power(a,b/2);
    halfpower*=halfpower;
    if(b&1)
    halfpower*=a;

    return halfpower;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}