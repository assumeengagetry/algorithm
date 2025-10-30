/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<TreeNode.h>
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node= new TreeNode(0);
        if(nums.size()== 1) {
            node-> val = nums[0];
            return  node;
        }
        int mas_val=0, max_val_index=0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]> mas_val){ max_val_index =i;
            mas_val= nums[i];
            }
        }
            node-> val= mas_val;
            if(max_val_index> 0){
                vector<int> newtree(nums.begin(), nums.begin() + max_val_index);
                node-> left= constructMaximumBinaryTree(newtree);
            }
            if(max_val_index< (nums.size() -1) ){
                vector<int> newtree(nums.begin(), nums.begin() + max_val_index );
                node-> right= constructMaximumBinaryTree(newtree);
            }
           return node; 
    }
};