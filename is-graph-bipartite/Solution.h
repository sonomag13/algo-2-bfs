// LeetCode 785. Is Graph Bipartite?
// Medium

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
     
        int numNode = graph.size(); 
        
        // 3 labels:
        //      0: the node is not labeled yet
        //      1: label 1
        //      2: label 2
        // A node cannot have the same label to its neighbor        
        vector<int> label(numNode, 0); 
        
        for (int i = 0; i < numNode; ++i) {
            
            if (label[i]) {
                continue; 
            }
            
            queue<int> queNode; 
            
            queNode.push(i);             
            label[i] = 1;   // label the current node 1
            
            while (!queNode.empty()) {                
                int currNode = queNode.front();
                queNode.pop();                
                int currLabel = label[currNode];
                
                // the neighbor label needs to be different from 
                // the label of the node
                int neighborLabel = currLabel == 1 ? 2 : 1;
                
                for (auto & neighbor : graph[currNode]) {
                    if (label[neighbor] == 0) {
                        queNode.push(neighbor);
                        label[neighbor] = neighborLabel; 
                    }
                    else {
                        if (label[neighbor] != neighborLabel) {
                            return false; 
                        }
                    }
                }
            }
        }
                
        return true; 
        
    }
};