/*
    431. Connected Component in Undirected Graph
    中文English
    Find connected component in undirected graph.

    Each node in the graph contains a label and a list of its neighbors.

    (A connected component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

    You need return a list of label set.

    Example
    Example 1:

    Input: {1,2,4#2,1,4#3,5#4,1,2#5,3}
    Output: [[1,2,4],[3,5]]
    Explanation:

    1------2  3
    \     |  | 
        \    |  |
        \   |  |
        \  |  |
            4   5
    Example 2:

    Input: {1,2#2,1}
    Output: [[1,2]]
    Explanation:

    1--2

    Clarification
    Learn more about representation of graphs

    Notice
    Nodes in a connected component should sort by label in ascending order. Different connected components can be in any order.
 */


#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std; 


// Definition for Undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here
        
        vector<vector<int>> solution;         
        set<UndirectedGraphNode*> visitedNodes; 
        
        for (auto node : nodes) {
            if (visitedNodes.find(node) == visitedNodes.end()) {
                /**
                 * The node is not visited previous, such that it is in a new connected area
                 * 
                 * As a side note, moving sematics is used in the line below
                 */ 
                solution.push_back(bfs(node, nodes, visitedNodes));
            }
        }
        
        return solution; 
        
    }
    
private: 
    vector<int> bfs(UndirectedGraphNode* node, const vector<UndirectedGraphNode*>& nodes, set<UndirectedGraphNode*>& visitedNodes) {
        
        vector<int> newConnectedSet; 
        queue<UndirectedGraphNode*> queNode; 
        queNode.push(node); 
        
        while (!queNode.empty()) {
            
            UndirectedGraphNode* currentNode = queNode.front(); 
            queNode.pop(); 
            
            newConnectedSet.push_back(currentNode->label); 
            visitedNodes.insert(currentNode); 
            
            for (auto neighbor : currentNode->neighbors) {
                if (visitedNodes.find(neighbor) == visitedNodes.end()) {
                    visitedNodes.insert(neighbor); 
                    queNode.push(neighbor); 
                }
            }
            
        }
        
        sort(newConnectedSet.begin(), newConnectedSet.end());         
        return newConnectedSet; 
                
    }

};