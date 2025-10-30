#include <stdio.h>
#include <string.h>

// 定义max函数，返回两个整数中的最大值
int max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    int B;
    scanf("%d", &B);

    char a[2002], b[2002];
    int c[2019], d[2019], s[2020]= {0}, len1, len2;

    scanf("%s", a);
    scanf("%s", b);

    len1 = strlen(a);
    len2 = strlen(b);

    // 将字符串a和b中的字符转换为对应的数值
    for (int i = 1; i <= len1; i++) {
        if (B > 10 && a[i - 1] >= 'A') {
            c[i] = a[len1 - i] - 'A' + 10;
        } else {
            c[i] = a[len1 - i] - '0';
        }
    }

    for (int i = 1; i <= len2; i++) {
        if (B > 10 && b[i - 1] >= 'A') {
            d[i] = b[len2 - i] - 'A' + 10;
        } else {
            d[i] = b[len2 - i] - '0';
        }
    }

    int m = max(len1, len2);

    // 进行加法运算
    for (int i = 1; i <= m; i++) {
        s[i] += c[i] + d[i];
        if (s[i] >= B) {
            s[i + 1]++;
            s[i] %= B;
        }
    }

    // 如果最高位有进位，则增加长度m
    if (s[m + 1] > 0) {
        m++;
    }

    // 从最高位开始输出结果
    for (int i = m; i >= 1; i--) {
        if (s[i] < 10) {
            printf("%d", s[i]);
        } else {
            printf("%c", (char)(s[i] + 'A' - 10));
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n[2006], m[2006];
    int z,a[2006],b[2006],c[2006]={0};
    cin>>z>>n>>m;
    int length1= strlen(n), length2= strlen(m), sumlength= length1< length2 ? length2 : length1;
    for(int i=0; i< length1; i++){
        if(z> 10 &&  n[i] >= 'A') a[length1 -1 -i]= n[i] - 'A' + 10;
        else a[length1-1-i]= n[i]- '0';
    }
    for(int i=0; i< length2; i++){
        if(z>10&& m[i]>='A') b[length2 -1 -i]=m[i] -'A' +10;
        else b[length2-1-i]= m[i]- '0';
    }
    int x=0, y=0;
    while (sumlength--)
    {
        c[x+1] += (y + a[x]+ b[x])/z;
        c[x] =(y+ a[x]+b[x])%z;
        y=c[x+1];
        x++;
    }
    if(c[x]>0) x++;
    for(int i= x-1; i>=0 ;i--){
        if(c[i]< 10) cout<<c[i];
        else cout<< (char)(c[i] -'A' + 10);

    }
    return 0;
}
