#include<iostream>
#include<cmath>
using namespace std;
bool ji_zhi(int n){
    if(n<=1) return false;
    if(n<= 3) return true;
    if(n%2==0) return false;
    for(int i=3;  i<= sqrt(n); i+=2) {
        if(n % i==0) return false;
    }
    return true;
}
int main(){
    int n;cin>>n; 
    if(n<=6 || n%2!=0) cout<<"ERROR"<<endl;
    else{
        for(int i=3; i<=n/2; i+=2){
            if(ji_zhi(i)&&ji_zhi(n-i)) 
            {   if(i>n-i) {
                cout<<n-i<<" "<<i<<endl;
            }
            else{
                cout<< i<<" "<<n-i<<endl;
                }
            }
        }
        
    }
}