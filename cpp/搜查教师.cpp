#include<bits/stdc++.h>
using namespace std;
 const int MAX=10000000;
 long long r[MAX], d[MAX], s[MAX], t[MAX], cha_fen[MAX], need[MAX];
 int m,n;
 bool check(int x)
 
 {
    memset(cha_fen, 0, sizeof(cha_fen));
    for(int i=0; i< x; i++){
        cha_fen[s[i]]+= d[i];
        cha_fen[t[i]+1] -=d[i];
    }
    need[0]=0;
    for(int i=1; i<=n; i++){
        need[i]= need[i-1]+ cha_fen[i];
        if(need[i]> r[i]) return false;

    }
    return true;
 }
 int main()
 {
    cin>>n>>m;
    for(int i=0 ;i< n; i++){
        cin>>r[i];
    }
    for(int i=0; i< m;i++){
        cin>> d[i]>>s[i]>>t[i];
    }
    if(check(m)){
        cout<<"0";
        return 0;
    }
    int left=1 , right = m;
    while(left < right){
        int mid= left+ (right- left)/2;
        if(check(mid)) left= mid+1;
        else right = mid;

    }
    cout<<"-1"<<endl;
    cout<<left;
    return 0;
 }