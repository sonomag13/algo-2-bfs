// LeetCode 314. Binary Tree Vertical Order Traversal
// Medium

#include <map>
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
                        
        vector<vector<int>> result; 
        
        if (!root) {
            return result;
        }
        
        map<int, vector<int>> mapColVal;  // map is used to maintain to order from left to right
        
        queue<pair<int, TreeNode*>> queColNode;
        queColNode.push(make_pair(0, root));
        
        while (!queColNode.empty()) {
            
            pair<int, TreeNode*> curr = queColNode.front();
            queColNode.pop(); 
            
            int col = curr.first; 
            TreeNode * node = curr.second;
            int val = node->val; 
            
            if (mapColVal.find(col) == mapColVal.end()) {
                // the column is not registered yet
                mapColVal.insert(make_pair(col, vector<int>{val}));
            }
            else {
                // the column is regiestered
                mapColVal[col].push_back(val);
            }
            
            // push left and right nodes into the queue with updated col 
            // left col = curr col - 1
            // right col = curr col + 1
            if (node->left) {
                queColNode.push(make_pair(col - 1, node->left));
            } 
            if (node->right) {
                queColNode.push(make_pair(col + 1, node->right));
            }
            
        }
        
        for (auto & ele : mapColVal) {
            result.push_back(ele.second);
        }
        
        return result; 
        
    }
};