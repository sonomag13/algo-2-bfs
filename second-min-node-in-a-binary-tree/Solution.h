// LeetCode 671. Second Minimum Node In a Binary Tree

#include <queue>

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
    int findSecondMinimumValue(TreeNode* root) {
        
        if(!root) {
            return -1; 
        }
        
        int s1 = root->val; // smallest value      
        
        int s2 = -1; // sencond smallest value; do not use INT_MAX since it is a corner case : )
                     // we use -1 to represent +inf
        
        bool found{false};
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // keep updating second smallest value
            bool cond1{node->val > s1}; 
            bool cond2; 
            if (s2 == -1) {
                cond2 = true;
            }
            else {
                cond2 = node->val < s2;
            }
            if (cond1 && cond2) {
                // either the current node is the answer, or it will be replaced by the value
                // on the "equal branch"
                s2 = node->val;
                found = true;
                // no need to add it's children into queue since all this 
                // children is equal or greater than the node value
                continue; 
            }
            
            if(!node->left) {
                // a node either has both children or no child
                continue;   
            }
            
            q.push(node->left);
            q.push(node->right);
        }
        
        return found ? s2 : -1;
        
    }

};