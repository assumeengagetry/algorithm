#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int maxSubArry(vector<int>& nums){
    int res = nums[0];
    int sum = 0;
    for(int i = 0; i< nums.size(); i++){
        sum = max(sum+nums[i],nums[i]);
        res = max(res,sum);
    }
    return res;
}