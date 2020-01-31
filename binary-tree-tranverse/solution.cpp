
// LintCode 69

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> vout;
        if(root == NULL) {
            return vout; 
        }
        int i, n; 
        queue<TreeNode *> q;
        vector<int> row;
        q.push(root); 
        TreeNode* nodeptr; 
        while(!q.empty()) {
            n = q.size(); 
            for(i = 0; i < n; i++) {
                nodeptr = q.front();
                q.pop();
                row.push_back(nodeptr->val); 
                if(nodeptr->left != NULL) {
                    q.push(nodeptr->left);
                }
                if(nodeptr->right != NULL) {
                    q.push(nodeptr->right);    
                }
            }
            vout.push_back(row);
            row.clear();
        }
        return vout; 
    }
};