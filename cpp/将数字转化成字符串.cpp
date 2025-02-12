#include<iostream>
using namespace std;
int main()
{
string s;
cin>>s;
int count=0;
int oldidnex=s.size()-1;
for(int i=0;i<s.size();i++)
{
    if(s[i]>='0'&&s[i<='9'])
    {
        count++;
    }
}
s.resize(s.size()=s.size()+count*6);
int newindex=s.size()-1;
while(oldidnex>=0)
{
    if(s[oldidnex]>='0'&&s[newindex]<='9')
    {
        s[newindex--]='r';
        s[newindex--]='e';
        s[newindex--]='b';
        s[newindex--]='m';
        s[newindex--]='u';
        s[newindex--]='n';
    }
    else
    {
        s[newindex--]=s[oldidnex];
    }
    oldidnex--;
}
cout<<s<<endl;
}
