/*
    199. Binary Tree Right Side View
    Medium

    Given the root of a binary tree, imagine yourself 
    standing on the right side of it, return the values 
    of the nodes you can see ordered from top to bottom.
*/

#include <vector>
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

/**
 *  The most confusion part of the problem is that it is possible for the 
 *  left node to provide a value. 
 * 
 *  A right view does not mean that it is always provided by a right child
 **/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result; 
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> queNode;
        queNode.push(root); 
        
        while (!queNode.empty()) {
            
            int numNode = queNode.size();
            
            for (int i = 0; i < numNode; ++i) {
                TreeNode* currNode{queNode.front()};
                queNode.pop();
                
                if (i == 0) {
                    result.push_back(currNode->val);
                }
                
                if (currNode->right) {
                    queNode.push(currNode->right);
                }
                
                if (currNode->left) {
                    queNode.push(currNode->left);
                }                
            }                        
            
        }
        
        return result; 
        
    }
};