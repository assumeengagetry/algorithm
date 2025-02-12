#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int N; cin>>N;
    int book[N];
    int t,i,j;
    for( i=0;i<N;i++)
    {
    	book[i]=0;
	}
    for( i=0;i<N;i++)
    {
        cin>>t;
        book[t]++;
    }
    for( i=0;i<N ;i++)

    {
        for( j=1; j<=book[i];j++)
        {
            cout<<i<<" ";
        }
        
    }
    return 0;
}