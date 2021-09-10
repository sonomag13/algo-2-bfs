// LeetCode 116. Populating Next Right Pointers in Each Node
// Medium

#include <vector>

using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root) {
            return root; 
        }
        
        queue<Node*> queNode; 
        queNode.push(root);
        
        while (!queNode.empty()) {            
            Node* pre = nullptr;            
            int n = queNode.size();
            for (int i = 0; i < n; ++i) {
                auto curr = queNode.front();
                queNode.pop(); 
                if (pre) {
                    // we need this to deal with the first node in the level
                    pre->next = curr;
                }
                if (curr->left) {
                    // well, this is a perfect binary tree
                    queNode.push(curr->left);
                    queNode.push(curr->right);
                }
                // current node becomes the pre node for the next iteration
                pre = curr; 
            }
                        
        }                
        
        return root; 
        
    }
};