/*
    133. Clone Graph
    Given a reference of a node in a connected undirected graph.

    Return a deep copy (clone) of the graph.

    Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

    class Node {
        public int val;
        public List<Node> neighbors;
    }
    

    Test case format:
    - For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.
    - Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
    - The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (!node) {
            return nullptr; 
        }

        // the entrance is the equivalent of the input node, and will be returned
        Node* entrance = new Node (node->val); 
        
        // hash map between old nodes and new (or cloned) nodes
        unordered_map<Node*, Node*> mapOldNewNode;
        mapOldNewNode.insert(make_pair(node, entrance)); 
        
        /**
         * BFS is used and we push the old nodes into the queue
         * 
         * But why old node instead of new node? 
         * Because the old nod has neighbors~!
         **/ 
        queue<Node*> queNode; 
        queNode.push(node);
        
        while (!queNode.empty()) {
            
            // check out the old node on the top
            Node* currNode{queNode.front()}; 
            queNode.pop();             
            
            // traverse the neighbors of a old node
            for (auto neighbor : currNode->neighbors) {                
                if (mapOldNewNode.find(neighbor) == mapOldNewNode.end()) {
                    /**
                     * the neighbor (an old node) has not been cloned yet
                     * 1. clone the node
                     * 2. update the hash map
                     * 3. push the neighor into the queue since we still 
                     *    need to append the neigbhor to the new node
                     *    i.e. in this step, a new node is only created and
                     *    its neighor vector is still empty
                     * 4. append the new node to the node corresponded with
                     *    the current node
                     **/ 
                    auto newNode = new Node(neighbor->val); 
                    mapOldNewNode.insert(make_pair(neighbor, newNode));
                    queNode.push(neighbor);                    
                    mapOldNewNode[currNode]->neighbors.push_back(newNode);
                }
                else {
                    /**
                     * the neighbor has already been copied, then simply append
                     * it to the node pointed corresponded by the current node
                     **/ 
                    mapOldNewNode[currNode]->neighbors.push_back(mapOldNewNode[neighbor]);                    
                }
            }            
        }        
        
        return entrance; 
        
    }
};