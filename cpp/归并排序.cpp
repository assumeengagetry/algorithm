#include<iostream>
using namespace std;
void merge(int* a,int L,int M,int R)
{
    int leftsize=M - L;
    int rightsize= R -M + 1;
    int* L_a=new int[leftsize];
    int* R_a=new int[rightsize];
    for(int i=L;i<M;i++)
    {
        L_a[i-L]=a[i];
    }
    for(int i=M;i<=R;i++)
    {
        R_a[i-M]=a[i];
    }
    int i=0,j=0,k=L;
    while (i<leftsize&&j<rightsize)
    {
        if(L_a[i]<R_a[j])
        {
            a[k++]=L_a[i++];
        }
        else{
            a[k++]=R_a[j++];
        }
    }
    while (i<leftsize)
    {
        a[k++]=L_a[i++];
    }
    while (j<rightsize)
    {
        a[k++]=R_a[j++];
    }
}
void merge_sort(int* a,int left,int right)
{
    if(left==right) return;
    else{
        int medium=(left+right)/2;
        merge_sort(a,left,medium);
        merge_sort(a,medium+1,right);
        merge(a,left,medium+1,right);
    }
}
void print(int* a ,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int a[]={3,6,23,99,56,56,2,2};
    merge_sort(a, 0, 7);
    print(a, 8);
    return 0;
}