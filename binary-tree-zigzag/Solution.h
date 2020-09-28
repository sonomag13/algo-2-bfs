/*
    71. Binary Tree Zigzag Level Order Traversal

    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

    Example
    Example 1:

    Input:{1,2,3}
    Output:[[1],[3,2]]
    Explanation:
        1
    / \
    2   3
    it will be serialized {1,2,3}
    Example 2:

    Input:{3,9,20,#,#,15,7}
    Output:[[3],[20,9],[15,7]]
    Explanation:
        3
    / \
    9  20
        /  \
    15   7
    it will be serialized {3,9,20,#,#,15,7}
 */

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        
        // BFS is used 
        vector<vector<int>> result; 
        
        if (!root) {
            return result; 
        }
        
        // initialize the queue
        queue<TreeNode*> queNode; 
        queNode.push(root); 
        
        // to control the order of zigzag
        int order = -1; 
        
        while (!queNode.empty()) {
            vector<int> row; 
            size_t nodeNum = queNode.size(); 
            for (size_t nodeIdx = 0; nodeIdx < nodeNum; ++nodeIdx) {
                TreeNode* currentNode = queNode.front(); 
                queNode.pop(); 
                row.push_back(currentNode->val); 
                if (currentNode->left) {
                    queNode.push(currentNode->left); 
                }
                if (currentNode->right) {
                    queNode.push(currentNode->right); 
                }
            }
            if (order == 1) {
                reverse(row.begin(), row.end()); 
            }
            order = order * -1; 
            result.push_back(row); 
        }
        return result; 
    }
};