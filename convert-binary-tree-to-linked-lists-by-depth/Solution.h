/*
    242. Convert Binary Tree to Linked Lists by Depth
    中文English
    Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

    Example
    Example 1:

    Input: {1,2,3,4}
    Output: [1->null,2->3->null,4->null]
    Explanation: 
            1
           / \
          2   3
         /
        4
    Example 2:

    Input: {1,#,2,3}
    Output: [1->null,2->null,3->null]
    Explanation: 
        1
         \
          2
         /
        3
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        vector<ListNode*> vectOut; 
        if (!root) {
            return vectOut; 
        }
        
        queue<TreeNode*> queNode; 
        queNode.push(root); 
        
        while (!queNode.empty()) {
            
            int queSize = queNode.size(); 
            
            ListNode* preNode{nullptr}; 
            
            for (int i = 0; i < queSize; ++i) {
                // fetch the node on the top of the queue, and push its childs into the queue
                TreeNode* currentNode = queNode.front(); 
                queNode.pop(); 
                if (currentNode->left) {
                    queNode.push(currentNode->left); 
                }
                if (currentNode->right) {
                    queNode.push(currentNode->right); 
                }
                
                // create a new list node
                auto newNode = new ListNode(currentNode->val); 
                if (i == 0) {
                    vectOut.push_back(newNode); 
                }
                else {
                    preNode->next = newNode; 
                }
                
                preNode = newNode; 
                
            }
            
        }
        
        return vectOut; 
        
    }
};