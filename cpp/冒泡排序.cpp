#include<iostream>
using namespace std;
int main()
{
    int N;cin>>N;int a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i< N-1;i++)
    {
        for(int j=0; j< N-1;j++)
        {
            if(a[j]>a[j+1])
            {
               int t=a[j+1];
               a[j]=a[j+1];
               a[j+1]=t;     
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<"  ";
    }
    return 0;
}