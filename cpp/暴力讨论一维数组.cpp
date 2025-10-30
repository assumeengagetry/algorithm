#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T,n,x;
    cin>>T;
    while(T--){
    cin>> n >>x;
    vector<int> vec(n);
    vector<int> p(n);
    int presum = 0 , sum=0;
    for(int i=0;i < n;i++)
    {
        presum *=2;
    }
    int a1 = (x + presum -1)/ presum;
    for(int i=0;i< n; i++)
    {
        sum += a1;
        a1= sum;
    }
    cout<< a1<<endl;
    }
} 
