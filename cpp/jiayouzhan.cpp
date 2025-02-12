class Solution {
public:
    int cancompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int totalsum = 0;
        int start = 0;
        for(int i=0 ; i< cost.size() ; i++){
            cursum += gas[i] - cost[i];
            totalsum += gas[i] - cost[i];
            if(cursum < 0){
                start = i+ 1;
                 cursum = 0;
            }
            return totalsum < 0? -1 : start;
        }
    }
};