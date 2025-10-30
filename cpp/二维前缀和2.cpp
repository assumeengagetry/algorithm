#include<bits/stdc++.h>
using namespace std;
bool f[202][202] ={0} ,p;
int n,m,i,j,k,x,y,ans=0;
int main()
{
    cin>>n>>m;
    for(int i=0;i< n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>f[i][j];
        }
    }
        for(int i=0;i< n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=min(n,m);k>ans ;k--)
            {
                p=1;
                for(int x=i; x<i+k;x++)
                {
                    for(int y=j;y< j+k;y++)
                    {
                        if(!f[x][y])
                        {
                            p=0;break;
                        }
                    }
                    if(!p) {
                        break;
                    }
                }
                if(p)
                {
                    ans = k;break;
                }
            }
        }
    }
    cout<< ans;
    return 0;
}