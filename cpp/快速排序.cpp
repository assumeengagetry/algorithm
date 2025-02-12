#include<iostream>
using namespace std;
int i,j,N,a[1000],temp;
void quicksort(int left, int right)
{
    if (left>=right) return;
    i=left;
    j=right;
    temp=a[left];
    while(i!=j){
    
    while(i<j&&temp<=a[j]) j--;
    while(i<j&&temp>=a[i])i++;
    if(i<j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    }
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}
int main()
{

cin>>N;
for( i=0;i<N;i++)
{
    cin>>a[i];
}
quicksort(0 ,N-1);
for (j=0;j<N;j++)
{
    cout<<a[j];
}
return 0;
}
