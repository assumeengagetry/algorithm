#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n[2006], m[2006];
    int z,a[2006],b[2006],c[2006]={0};
    cin>>z>>n>>m;
    int length1= strlen(n), length2= strlen(m), sumlength= length1< length2 ? length2 : length1;
    for(int i=0; i< length1; i++){
        if(z> 10 &&  n[i] >= 'A') a[length1 -1 -i]= n[i] - 'A' + 10;
        else a[length1-1-i]= n[i]- '0';
    }
    for(int i=0; i< length2; i++){
        if(z>10 && m[i]>='A') b[length2 -1 -i]=m[i] -'A' +10;
        else b[length2-1-i]= m[i]- '0';
    }
    int x=0, y=0;
    while (sumlength--)
    {
        c[x+1] += (y + a[x]+ b[x])/z;
        c[x] =(y+ a[x]+b[x])%z;
        y=c[x+1];
        x++;
    }
    if(c[x]>0) x++;
    for(int i= x-1; i>=0 ;i--){
        if(c[i]< 10) cout<<c[i];
        else cout<< (char)(c[i] -'A' + 10);
       
    }
     return 0; 
}
