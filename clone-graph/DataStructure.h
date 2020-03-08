//
// Created by lu.gao on 2/9/20.
//

#ifndef CLONE_GRAPH_DATASTRUCTURE_H
#define CLONE_GRAPH_DATASTRUCTURE_H

#include <vector>

using namespace std;

// Definition for undirected graph.
template <typename T>
struct UndirectedGraphNode {
    T label;
    vector<UndirectedGraphNode<T> *> neighbors;
    UndirectedGraphNode(T x) : label(x) {};
};

#endif //CLONE_GRAPH_DATASTRUCTURE_H
