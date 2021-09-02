// LeetCode 286. Walls and Gates
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        for (int row = 0; row < rooms.size(); ++row) {
            for (int col = 0; col < rooms[0].size(); ++col) {
                if (rooms[row][col] == GATE) {
                    dfs(rooms, row, col, 0);
                }
            }
        }
        
    }
    
private:
    
    int WALL = -1; 
    int GATE = 0; 
    int ROOM = INT_MAX; 
    
    void dfs(vector<vector<int>>& rooms, int row, int col, int dist) {
        
        // out of the boundary
        if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size()) {
            return;
        }
        
        // obstacle
        if (rooms[row][col] == WALL) {
            return;
        }
        
        if (rooms[row][col] < dist) {
            return;            
        }
        
        rooms[row][col] = dist; 
        
        dist++; 
        
        dfs(rooms, row + 1, col, dist);
        dfs(rooms, row - 1, col, dist);
        dfs(rooms, row, col + 1, dist);
        dfs(rooms, row, col - 1, dist);
                
    }
    
};