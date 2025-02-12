#include<iostream>
#define N 10
using namespace std;
void select_sort(int* a , int n)
{
    for(int i=0; i< n;i++)
    {
        int min = i;
        for(int j=i;j< n;j++)
        {
            if(a[min] > a[j])
            
            {
                min = j;
            }
        }
        if (min!=i)
        {
            swap(a[min] , a[i]);
        }
    }
    
}
int main()
{
    
    int a[N]={1,4,6,3,6,4,8,9,3,0};
    select_sort(a,N);
    for(int j=0;j<N;j++)
    {
        cout<<a[j]<<" ";
    }
return 0;
}