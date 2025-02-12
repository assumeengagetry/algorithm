#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int jump(vector<int>& nums){
    if(nums.size()== 1) return 0;
    int cur= 0;
    int next = 0;
    int res = 0;
    for(int i=0; i< nums.size(); i++){
        next = max( next, nums[i]+i);
        if(i == cur){
            res++;
            cur = next;
            if(next >= nums.size()-1) break;
        }
    }
    return res;
}