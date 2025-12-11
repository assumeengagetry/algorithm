#include <vector>
#include <algorithm>
using namespace  std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracing(vector<int>& candidates, int target, int sum, int start_index, vector<bool>& used){
        if(sum== target){
            result.push_back(path);
            return ;
        }
        for(int i= start_index; i< candidates.size() && sum + candidates[i] <= target; i++){
            if(i>0 && candidates[i] ==candidates[i-1] && used[i-1] == false){
                continue;
            }
            sum+= candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracing(candidates, target, sum , i+ 1, used);
            used[i] = false;
            sum-= candidates[i];
            path.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        result.clear();
        path.clear();
        sort(candidates.begin() , candidates.end());
        backtracing(candidates , target, 0 ,0  , used);
        return result;
    }
};