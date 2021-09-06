// LeetCode 102. Binary Tree Level Order Traversal
// Medium

#include <queue>
#include <vector>

using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {                
        
        vector<vector<int>> result; 
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode *> queNode; 
        queNode.push(root); 
        
        while (!queNode.empty()) {
            
            int n = queNode.size();
            
            vector<int> level; 
            
            for (int i = 0; i < n; ++i) {
                TreeNode * curr = queNode.front();                
                queNode.pop();
                level.push_back(curr->val);
                if (curr->left) {
                    queNode.push(curr->left);
                }
                if (curr->right) {
                    queNode.push(curr->right);
                }                
            }
            
            result.push_back(level);
            
        }                
        
        return result; 
    }
};