#include"stdio.h"

int main()
{
    int n,m,A;
    long long int a[100001]={0}; //直接全部都给变成0就行
    long long int s[100001]={0};
    int i=1;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
         {scanf("%d",&A);
        a[i]=A;
        s[i]=a[i]+s[i-1];
        }    
    scanf("\n%d",&m);
    for(i=1;i<=m;i++)
        {int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);//缺少换行，导致结果不对，但是加上换行之后有溢出，所以a s 数组更改大小
        }
    return 0;
}