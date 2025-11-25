#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

// 递归先序遍历
void preorderRecursive(TreeNode* root) {
if(root == nullptr) {
    return;
}
cout<< root -> val << " ";
preorderRecursive(root -> left);
preorderRecursive(root -> right);
}

// 递归中序遍历
void inorderRecursive(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    inorderRecursive(root -> left);
    cout<< root -> val << " ";
    inorderRecursive(root -> right);
}

// 递归后序遍历
void postorderRecursive(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    postorderRecursive(root -> left);
    postorderRecursive(root -> right);
    cout<< root -> val << " ";
}

// 非递归先序遍历
void preorderIterative(TreeNode* root) {
    vector<char> result;
    if(root == nullptr) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        result.push_back(node -> val);
        if(node -> right) stk.push(node -> right);
        if(node -> left) stk.push(node -> left);
    }
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
}

// 非递归中序遍历
void inorderIterative(TreeNode* root) {
    TreeNode* cur = root;
    vector<char> result;
    stack<TreeNode*> stk;
    while(cur != nullptr ||!stk.empty()){
        if(cur != nullptr) {
            stk.push(cur);
            cur = cur -> left;
        }
        else{
            cur = stk.top();
            stk.pop();
            result.push_back(cur -> val);
            cur = cur -> right;
        }
    }
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
}

// 非递归后序遍历
void postorderIterative(TreeNode* root) {
    vector<char> result;
    if(root == nullptr) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        result.push_back(node -> val);
        if(node -> left) stk.push(node -> left);
        if(node -> right) stk.push(node -> right);
    }
    reverse(result.begin(), result.end());
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
}

// 构造示例二叉树
TreeNode* buildSampleTree() {
    // 构造如下结构：
    //     A
    //    / \
    //   B   C
    //  / \   \
    // D   E   F
    TreeNode* A = new TreeNode('A');
    TreeNode* B = new TreeNode('B');
    TreeNode* C = new TreeNode('C');
    TreeNode* D = new TreeNode('D');
    TreeNode* E = new TreeNode('E');
    TreeNode* F = new TreeNode('F');
    A->left = B; A->right = C;
    B->left = D; B->right = E;
    C->right = F;
    return A;
}

int main() {
    TreeNode* root = buildSampleTree();
    cout << "递归先序遍历: "; preorderRecursive(root); cout << endl;
    cout << "递归中序遍历: "; inorderRecursive(root); cout << endl;
    cout << "递归后序遍历: "; postorderRecursive(root); cout << endl;
    cout << "非递归先序遍历: "; preorderIterative(root); cout << endl;
    cout << "非递归中序遍历: "; inorderIterative(root); cout << endl;
    cout << "非递归后序遍历: "; postorderIterative(root); cout << endl;
    return 0;
}
