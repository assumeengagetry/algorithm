#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<long int> r(n+1 , 0);
    for(int i=1; i<=n; i++)
    {
        cin>> r[i];
    }
    vector<long int> remaining( n+1 , 0);
    for(int j=1 ; j<=n ; j++)
    {
        remaining[j] = r[j]; 
    }
    bool canfullfillall = true;
    int x=1;
    for(int i=0; i< m;i++)
    {
        int d, s, t;
        bool canfullfill = true;
        cin>> d>> s>>t;
        for(int j=s; j<=t && canfullfill ; j++)
        {
            if(remaining[j] < d)
            {
                canfullfill = false;
                break;
            }
            remaining[j] -=d;
        }
        if(!canfullfill)
        {
            cout<<"-1"<<endl<<x<<endl;
            canfullfillall = false;
            break;
        }
        x++;
    }
    if(canfullfillall)
    {
        cout<<0;
    }
    return 0;
}