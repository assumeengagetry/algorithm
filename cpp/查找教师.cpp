#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn = 1000005;
int n, m, ans = 20021228;
int r[maxn], c[maxn], now;
int d[maxn], s[maxn], t[maxn];
bool check(int mid)  //判断当前的二分值是否可行  
{
    int i, sum = 0;
    if(now > mid) 
      for(i = mid + 1; i <= now; i++) {
          c[s[i]] -= d[i];
          c[t[i] + 1] += d[i];
      }
    else
      for(i = now + 1; i <= mid; i++) {  //注意这里是将以前操作的恢复原样，操作相反
          c[s[i]] += d[i];
          c[t[i] + 1] -= d[i];
      }
    now = mid;
    for(i = 1; i <= n; i++) {
      sum += c[i];
      if(sum > r[i]) return true;
    }
    return false;
}
int main()
{
    //freopen("classroom.in", "r", stdin);
    //freopen("classroom.out", "w", stdout);
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
      scanf("%d", &r[i]);
    for(i = 1; i <= m; i++) {
      scanf("%d%d%d", &d[i], &s[i], &t[i]);
    }
    int l = 1, r = m, mid;
    while(l <= r) {  //二分答案
      mid = (l + r) / 2;
      if(check(mid)) ans = min(ans, mid), r = mid -1;
      else l = mid + 1;
    }
    if(ans != 20021228) 
      printf("-1\n%d", ans);
     else printf("0"); 
    return 0;
}