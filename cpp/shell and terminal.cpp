#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;string s;cin>>s;cin>>n;int lens=s.size();
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
    cout<<s<<endl;
}