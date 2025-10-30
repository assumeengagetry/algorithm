#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1000005];
int main(){

    int T ;cin>> T;
    while(T--){
        int n ,ans=0;
        cin>> n;
        for(int i=1 ;i<=n; i++){
            cin>> a[i];
        }
        int i=1;
        while(i<= n){
            if(a[i]==i) i++;
            else{
                int b=a[i], j=i+1;
                b= max(b ,a[j]);
                while (b> j)
                {
                    j++;b= max(b, a[j]);                    
                }
                ans += j-i +1;
                i= j+1;
            }
        }
         cout<<ans<<endl;
    }
   
}