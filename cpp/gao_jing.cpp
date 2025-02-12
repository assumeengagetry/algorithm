#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    
    cin>>s1>>s2;
    int length1 =s1.size(),length2=s2.size() ,sumlength= length1< length2 ?length2 : length1;
    int a[100005],b[100005],c[100005] ={0};
    for(int i=0 ;i< s1.size(); i++){ 
        a[length1 -1 -i ] = s1[i] - '0';
    }
    for(int i=0; i< s2.size(); i++){
        b[length2 -1 -i] = s2[i] - '0';
    }
    for(int i=0; i< sumlength; i++){
        c[i+1] += (a[i] + b[i] + c[i])/10;
        c[i] = (a[i]+b[i]+c[i]) % 10;
        
    }
    if(c[sumlength]> 0) sumlength++;
    for(int i = sumlength-1 ; i>=0; i--){
        cout<< c[i];
    }
    return 0;

}