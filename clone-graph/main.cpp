
// LintCode 137 Clone Graph
/* ref.:
 * https://www.youtube.com/watch?v=vma9tCQUXk8
 * https://www.techiedelight.com/graph-implementation-using-stl/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "DataStructure.h"

using namespace std;

int main() {


    char nodeChar[] = {'A', 'B', 'C', 'D', 'E'};
    int nNode = sizeof(nodeChar) / sizeof(char);
    vector<vector<char>> neighborVect {{'B', 'C'}, {'A', 'D', 'E'}, {'A', 'D'}, {'B', 'C', 'E'}, {'B', 'D'}};
    unordered_map<char, UndirectedGraphNode<char>*> labelNodePtrMap;

    /*
     create a hash table (i.e. an unordered_map) with two purposes:
     1. for each node, initialize a node struct; the label of the node is the also valued
     2. using hash table enables efficient searching when adding edges into the nodes
     Notice that, at this point, the label of each node is valued; but neighbor is not
    */

    /*
    // this section is functional
    for(int i = 0; i < nNode; i++) {
        auto currentNodePtr = new UndirectedGraphNode<char>(nodeChar[i]);
        currentNodePtr->label = nodeChar[i];
        labelNodePtrMap.insert(make_pair(nodeChar[i], currentNodePtr));
    }
    */

    for(int i = 0; i < nNode; i++) {
        UndirectedGraphNode<char> currentNode(nodeChar[i]);
        labelNodePtrMap.insert(make_pair(nodeChar[i], &currentNode));
    }
//
    UndirectedGraphNode<char>* topNodePtr = labelNodePtrMap['A'];

    char nodeKey, neighborKey;
    vector<char> currentNeighbhor;
    for(int i = 0; i < nNode; i++) {
        nodeKey = nodeChar[i];
        currentNeighbhor = neighborVect[i];
        for(int j = 0; j < currentNeighbhor.size(); j++) {
            neighborKey = currentNeighbhor[j];
            labelNodePtrMap[nodeKey]->neighbors.push_back(labelNodePtrMap[neighborKey]);
        }
    }

    vector<UndirectedGraphNode<char> *> currentNeighbhorPtrVect;

    for(int i = 0; i < nNode; i++) {
        nodeKey = nodeChar[i];
        cout << "Node = " << labelNodePtrMap[nodeKey]->label << endl;
        currentNeighbhorPtrVect = labelNodePtrMap[nodeKey]->neighbors;
        for(int j = 0; j < currentNeighbhorPtrVect.size(); j++) {
            cout << "\tneighbor " << j << " = "<<currentNeighbhorPtrVect[j]->label << endl;
        }
    }

    return 0;

}
