#include<iostream>
#include<string>
using namespace std;
int main()
{
string s;
while (cin>>s)
{
int count=0;
int oldidnex=s.size() - 1;
for(int i=0 ; i<s.size() ; i++)
{
    if(s[i]>='0' && s[i]<='9')
    {
        count++;
    }
}
cout<<count<<endl;
s.resize(s.size()+count*5);
int newindex=s.size()-1;
while(oldidnex>=0)
{
    if(s[oldidnex]>='0'&&s[oldidnex]<='9')
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
}