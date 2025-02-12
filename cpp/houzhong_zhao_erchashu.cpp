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
private:
    TreeNode* traversal(vector<int>& inorder , vector<int>& postorder){
        if(postorder.size() == 0) return NULL;//第一步
        int rootValue = postorder[postorder.size() -1];//找中节点，作为开头的切割点
        TreeNode* node= new TreeNode(rootValue);
        if(postorder.size() == 1) return node;// 叶子
        int delimiterindex;//切割点 找切割点
        for(delimiterindex = 0; delimiterindex < inorder.size(); delimiterindex++){
            if(inorder[delimiterindex] == rootValue) break;
        }//找到分个点
        vector<int> leftinorder(inorder.begin() , inorder.begin() + delimiterindex);//切割中序数组 ?? 
        vector<int> rightinorder(inorder.begin() + delimiterindex + 1 , inorder.end() );//切割后序数组 ??
        
        postorder.resize(postorder.size() -1);//在此
        
        vector<int> leftpostorder(postorder.begin() , postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size() , postorder.end());
        // 找到钟旭和后续的左右分割点，之后，将逐步打印出每一次的分割组，也就是保持一个左闭右开的区间
        cout<<"---------"<<endl;
        cout<< "leftinorder:";
        for(int i : leftinorder) cout<<i<< " ";
        cout<<endl;
        cout<<"---------"<<endl;
        cout<< "rightinorder:";
        for(int i : rightinorder) cout<<i<< " ";
        cout<<endl;
        cout<<"---------"<<endl;
        cout<< "leftpostorder:";
        for(int i : leftpostorder) cout<<i<< " ";
        cout<<endl;
        cout<<"---------"<<endl;
        cout<< "rightpostorder:";
        for(int i : rightpostorder) cout<<i<< " ";
        cout<<endl;
        
        node-> left = traversal(leftinorder,leftpostorder);
        node-> right = traversal(rightinorder,rightpostorder);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder , postorder);
    }
};
