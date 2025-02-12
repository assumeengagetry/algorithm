#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long  M;cin>>M;
    vector<pair<int , int>> tem;
    vector<long long> prefixsum(2000001, 0);
    for(int i=1; i<=2000000;i++){
        prefixsum[i]=prefixsum[i-1]+i;
    }
    for(int j=2; j*(j+1) <= 2* M; j++){
        long long left=1 , right= 2000000;
        while(left<= right){
            long long mid= left +(right- left)/2;
            long long sum= prefixsum[mid +j-1] - prefixsum[mid -1];
            if(sum==M){
                tem.emplace_back(mid , mid+ j-1);
                left = mid +1;
            }
            else if (sum < M){
                left = mid +1;
            }
            else{
                right = mid -1;
            }
        }
    }
    reverse(tem.begin() , tem.end());
    for(const auto&[start, end] : tem){
        cout<<start<<  " "<< end<<endl;
    }
    return 0;
}
