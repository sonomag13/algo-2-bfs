// LeetCode 117. Populating Next Right Pointers in Each Node II
// Medium

#include <queue>
#include <vector>

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
            
            int n = queNode.size();
            
            Node * prev = nullptr; 
            
            for (int i = 0; i < n; ++i) {
                Node * curr = queNode.front();
                queNode.pop(); 
                if (prev) {
                    prev->next = curr;                 
                }
                
                prev = curr; 
                
                if (curr->left) {
                    queNode.push(curr->left);
                }
                
                if (curr->right) {
                    queNode.push(curr->right);
                }
                
            }
            
        }
                        
        return root; 
    }
};