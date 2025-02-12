#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int wiggleMaxLength(vector<int>& nums){
    if(nums.size()<=1) return nums.size();
    int curdiff = 0, prediff = 0, result =1 ;
    for(int i=1; i< nums.size(); i++){
        curdiff = nums[i+1] - nums[i];
        if(prediff<=0 && curdiff >0 ||prediff >= 0 && curdiff < 0){
            result++;
            prediff = curdiff;
        }
    }
    return result;
}
