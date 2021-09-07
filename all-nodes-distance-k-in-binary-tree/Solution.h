// LeetCode 863. All Nodes Distance K in Binary Tree
// Medium

#include <set>
#include <unordered_map>
#include <vector>

using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;
        
        // this is a BSF starting from target instead of root
        this->graph.insert(make_pair(nullptr, vector<TreeNode *> {root}));
        
        _buildGraph(nullptr, root); 
        
        queue<TreeNode*> queNode; 
        queNode.push(target); 
        unordered_set<TreeNode*> visited;
        visited.insert(target); 
        
        int cnt = 0; 
        
        while (!queNode.empty() && cnt <= k) {
            
            int n = queNode.size(); 
            
            for (int i = 0; i < n; ++i) {
                
                TreeNode * curr = queNode.front();
                queNode.pop();                
                
                if (cnt == k) {
                    result.push_back(curr->val); 
                }
                
                for (auto node : this->graph[curr]) {
                    if (visited.find(node) == visited.end()) {
                        queNode.push(node); 
                        visited.insert(node); 
                    }
                }
                
            }
            cnt++;
        }
                
        return result;
        
    }
    
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
    
    void _buildGraph(TreeNode * parent, TreeNode * child) {
        
        if (parent) {
            this->graph[parent].push_back(child);
            this->graph[child].push_back(parent);
        }
        
        if (child->left) {
            _buildGraph(child, child->left);
        }
        
        if (child->right) {
            _buildGraph(child, child->right);
        }
        
    }
        
};