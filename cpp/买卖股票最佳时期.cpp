#include<iostream>
#include<string>
#include<vector>   
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int maxProfit(vector<int>& prices){
    int res = 0;
    for(int i=1; i< prices.size(); i++){
        if(prices[i] > prices[i-1]){
            res += prices[i] - prices[i-1];
        }
    }
    return res;
}