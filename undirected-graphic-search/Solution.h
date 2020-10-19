/*
    618. Search Graph Nodes
    Given a undirected graph, a node and a target, return the nearest node to given node which value of it is target, return NULL if you can't find.

    There is a mapping store the nodes' values in the given parameters.

    Example
    Example 1:

    Input:
    {1,2,3,4#2,1,3#3,1,2#4,1,5#5,4}
    [3,4,5,50,50]
    1
    50
    Output:
    4
    Explanation:
    2------3  5
    \     |  | 
    \    |  |
    \   |  |
        \  |  |
        1 --4
    Give a node 1, target is 50

    there a hash named values which is [3,4,10,50,50], represent:
    Value of node 1 is 3
    Value of node 2 is 4
    Value of node 3 is 10
    Value of node 4 is 50
    Value of node 5 is 50

    Return node 4
    Example 2:

    Input:
    {1,2#2,1}
    [0,1]
    1
    1
    Output:
    2
    Notice
    It's guaranteed there is only one available solution 
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
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // write your code here
        
        if (!graph.size() || !values.size() || !node) {
            return NULL; 
        }
        
        /**
         * - queue for bfs - initialized with the input node
         * - set to record if a node has been visited
         */
        queue<UndirectedGraphNode*> queNode; 
        queNode.push(node); 
        set<UndirectedGraphNode*> checkedNode; 
        checkedNode.insert(node); 
        
        while (!queNode.empty()) {
            
            UndirectedGraphNode* currentNode = queNode.front(); 
            queNode.pop();
            
            /**
             * check if the current node matches the target:
             * - if so, return the current node 
             * - if not, push the neighbors into the queue
             */ 
            if (values[currentNode] == target) {
                return currentNode; 
            }
            
            for (auto neighbor : currentNode->neighbors) {
                if (checkedNode.find(neighbor) == checkedNode.end()) {
                    checkedNode.insert(currentNode); 
                    queNode.push(neighbor); 
                }
            }
            
        }
        
        return NULL; 
        
    }
};