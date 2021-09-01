
/*
	127. Topological Sorting
	中文English
	Given an directed graph, a topological order of the graph nodes is defined as follow:

	For each directed edge A -> B in graph, A must before B in the order list.
	The first node in the order can be any node in the graph with no nodes direct to it.
	Find any topological order for the given graph.

	Example
	For graph as follow:

	图片

	The topological order can be:

	[0, 1, 2, 3, 4, 5]
	[0, 2, 3, 1, 5, 4]
	...
	Challenge
	Can you do it in both BFS and DFS?

	Clarification
	Learn more about representation of graphs

	Notice
	You can assume that there is at least one topological order in the graph.
 */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std; 

// Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
 };


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        
        vector<DirectedGraphNode*> vecNode; 
        
        // calcuate the in degree
        unordered_map<DirectedGraphNode*, int> mapNodeInDegree; 
        
        for (auto ptrNode : graph) {
            for (auto neighbor : ptrNode->neighbors) {
                if (mapNodeInDegree.find(neighbor) != mapNodeInDegree.end()) {
                    mapNodeInDegree[neighbor]++; 
                }
                else {
                    mapNodeInDegree[neighbor] = 1; 
                }
            }
        }
        
        // queue for BSD
        queue<DirectedGraphNode*> queNode; 
        for (auto ptrNode : graph) {
            if (mapNodeInDegree.find(ptrNode) == mapNodeInDegree.end()) {
                queNode.push(ptrNode); 
            }
        }
        
        // BFS
        while (!queNode.empty()) {
            
            DirectedGraphNode* currPtrNode = queNode.front();
            queNode.pop(); 
            
            vecNode.push_back(currPtrNode); 
            
            // update the in-degree hash map
            for (auto neighbor : currPtrNode->neighbors) {
                mapNodeInDegree[neighbor]--; 
                if (mapNodeInDegree[neighbor] == 0) {
                    queNode.push(neighbor); 
                }
            }
            
        }
        
        return vecNode; 
        
    }
};
