#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
vector<int> guibingpaixu(vector<int>& a, vector<int>& b){
	vector<int> res;
    int i = 0, j = 0;
    while(i< a.size()&& j< b.size()){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }
    if(i< a.size()){
        for(; i< a.size(); i++){
            res.push_back(a[i]);
        }
    }
    if(j< b.size()){
        for(; j< b.size(); j++){
            res.push_back(b[j]);
        }
    }
    return res;

}
int main(){
    int a,b;
    cin>>a>>b;
    vector<int> nums1;
    vector<int> nums2;
    for(int i = 0; i< a; i++){
        int num;
        cin>>num;
        nums1.push_back(num);
    }
    for(int i = 0; i< b; i++){
        int num;
        cin>>num;
        nums2.push_back(num);
    }
    vector<int> res = guibingpaixu(nums1,nums2);
    for(int i = 0; i< res.size(); i++){
        cout<<res[i]<<" ";
    }
}