#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn= 100005;
int n,m,ans=20060801;
int remaining[maxn] , c[maxn] , now;
int d[maxn] , s[maxn] , t[maxn];
bool check(int mid)
{
    int i ,sum =0;
    if(now > mid)
    {
        for(int i= mid+1; i<=now ;i++)
        {
            c[s[i]] -= d[i];
            c[t[i] +1] += d[i];
        }
    }
    else
    {
        for(i = now +1; i<= mid; i++)
        {
            c[s[i]] += d[i];
            c[t[i] +1] -=d[i];
        }
    }
    now = mid;
    for(i =1; i<= n; i++)
    {
        sum += c[i];
        if(sum > remaining[i]) return true;
    }
    return false;
}
int main()
{
    int i;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>remaining[i];
    }
    for(int i=1 ; i<=m;i++)
    {
        cin>> d[i]>>s[i]>>t[i];
    }
    int l=1, r=m, mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)) {
            ans = min(mid, ans);
            r= mid-1;
        }
        else l= mid +1;
    }
    if(ans != 20060801)
    {
        cout<<"-1"<<endl<<ans;
    }
    else cout<<"0";
}