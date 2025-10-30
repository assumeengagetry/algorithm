#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
bool  canJump(vector<int>& nums){
   int cover =0 ;
   for(int i=0; i<= cover ; i++){
    cover= max(cover , nums[i]+ i);
    if(cover >= nums.size()-1) return true;
   }
   return false;
}