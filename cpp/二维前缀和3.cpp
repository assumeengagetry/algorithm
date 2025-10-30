#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0,f[205][205],x;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            f[i][j]=f[i][j-1]+f[i-1][j]-f[i-1][j-1]+x;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<m;j++)
        {
            int l=0,r = min(m,n);
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(i+mid>n||j+mid>m||f[i+mid][j+mid]-f[i][j+mid]-f[i+mid][j]+f[i][j]<mid*mid) {
                    r = mid-1;
                }
                else l= mid + 1;
            }
            if(f[i+r][j+r]-f[i+r][j]-f[i][j+r]+f[i][j]==r*r) ans= max(r,ans);
        }
    }
    cout<<ans;
    return 0;
}