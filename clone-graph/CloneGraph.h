/*
    137. Clone Graph    
    Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. Nodes are labeled uniquely.
    You need to return a deep copied graph, which has the same structure as the original graph, and any changes to the new graph will not have any effect on the original graph.

    Example
    Example1

    Input:
    {1,2,4#2,1,4#4,1,2}
    Output: 
    {1,2,4#2,1,4#4,1,2}
    Explanation:
    1------2  
     \     |  
      \    |  
       \   |  
        \  |  
          4   
    Clarification
    How we serialize an undirected graph: http://www.lintcode.com/help/graph/

    Notice
    You need return the node with the same label as the input node.
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        
        if (node == NULL) {
            return node; 
        }
        
        /**
         * hash map
         * - key: pointer to the given node
         * - val: pointer to the new node
         */ 
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapOldNewNode; 
        auto newEntryNode = new UndirectedGraphNode(node->label); 
        mapOldNewNode[node] = newEntryNode; 
        
        // initiaize the queue for BFS
        queue<UndirectedGraphNode*> queNodePtr; 
        queNodePtr.push(node); 
        
        // BFS
        while (!queNodePtr.empty()) {
            
            /**
             * fetch a node from the queue
             * Notice that at this point, the old node has the information of the neighbors, 
             * but the new node has only the label.
             * Therefore we need to iterate the neighors of the old node:
             * - if the neighor already is already cloned, then append that cloned copy to the new oldNodePtr
             * - otherwise, create a clone of the old pointer
             */ 
            UndirectedGraphNode* oldNodePtr = queNodePtr.front(); 
            queNodePtr.pop(); 
            UndirectedGraphNode* newNodePtr = mapOldNewNode[oldNodePtr];
            
            // clone the neighors
            for (auto neighbor : oldNodePtr->neighbors) {
                if (mapOldNewNode.find(neighbor) != mapOldNewNode.end()) {
                    // the neighbor is aleardy cloned, just append it
                    newNodePtr->neighbors.push_back(mapOldNewNode[neighbor]);
                }
                else {
                    /**
                     * the neighbor has not been cloned yet
                     * - create the new node
                     * - update the map
                     * - link the node to the current node as a neighbor
                     * - push the old node into the queue
                     */
                    auto newNeighbor = new UndirectedGraphNode(neighbor->label);
                    mapOldNewNode[neighbor] = newNeighbor; 
                    newNodePtr->neighbors.push_back(newNeighbor); 
                    queNodePtr.push(neighbor); 
                }
            }
            
        }
        
        return newEntryNode; 
        
    }
    
};