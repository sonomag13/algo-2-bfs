// LeetCode 515. Find Largest Value in Each Tree Row
// Medium

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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> result; 
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> queNode; 
        queNode.push(root); 
        
        while (!queNode.empty()) {
            
            int n = queNode.size();
            
            int maxVal = INT_MIN; 
            
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = queNode.front();
                queNode.pop();
                maxVal = max(maxVal, curr->val);
                if (curr->left) {
                    queNode.push(curr->left);
                }
                if (curr->right) {
                    queNode.push(curr->right);
                }                
            }
            
            result.push_back(maxVal);
            
        }
        
        return result; 
        
    }
};