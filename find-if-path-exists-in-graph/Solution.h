// LeetCode 1971. Find if Path Exists in Graph
// Easy

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Implemented with BFS; can be done by Union Find as well
class Solution {    
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        if (n == 1) {
            return true; 
        }
        
        if (!edges.size() || !n) {
            return false; 
        }

        // using a lambda function to build up the graph                           
        auto buildGraph = [this](const int ver0, const int ver1) {
            // ver0: vertext
            // ver1: another vertex connected to ver0

            if (graph.find(ver0) == graph.end()) {
                // the vertex has not been registered yet
                graph.insert(make_pair(ver0, vector<int>{ver1}));
            }
            else {
                // the vertex been visited previously
                graph[ver0].push_back(ver1); 
            }        
        };
        
        for (auto & edge : edges) {            
            int ver0 = edge[0];
            int ver1 = edge[1];             
            buildGraph(ver0, ver1);
            buildGraph(ver1, ver0);            
        }
        
        // queue of vertices and the first number is the start
        queue<int> queVertex; 
        queVertex.push(start);
        
        // if a vertex has been visited
        vector<bool> visited(n, false);
        visited[start] = true;
        
        // BFS
        while (!queVertex.empty()) {
            
            // get a vertex from the queue, and check if it matches with the end
            int currVer = queVertex.front();
            queVertex.pop();
            
            if (currVer == end) {
                return true; 
            }
            
            for (auto neighborVer : graph[currVer]) {
                if (!visited[neighborVer]) {
                    queVertex.push(neighborVer); 
                    visited[neighborVer] = true;
                }
            }            
            
        }        
        
        // BFS is complete and start and end are not connected 
        return false; 
        
    }
    
private:
    unordered_map<int, vector<int>> graph; 
    
};