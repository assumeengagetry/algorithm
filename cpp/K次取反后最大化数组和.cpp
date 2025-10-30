#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    static bool cmp(vector<int> a,vector<int> b){
        return abs(a)< abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 && k>0){
                nums[i]*=-1;
                k--;
            }
        }
        if(k % 2 == 1) nums[nums.size()-1]*=-1;
        int result=0;
        for(int a:nums) result+=a;
        return result;
    }
};
int main(){
    Solution s;

}