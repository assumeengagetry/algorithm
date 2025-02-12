#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,a,b;
    cin>> n;
    vector<int> vec(n);
    vector<int> p(n);
    int presum=0;
    for(int i=0 ; i< n; i++)
    {
        cin>> vec[i];
        presum += vec[i];
        p[i] = presum;
    }
    while(cin>>a >>b)
    {
        int sum ;
        if (a==1) sum= p[b-1];
        else sum = p[b-1]- p[a-2];
        cout<< sum<<endl;
    }
}
