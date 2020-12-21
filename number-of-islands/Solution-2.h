/**
 * in this case we have avoid modifying the given matrix 
 **/

#include <vector>

using namespace std; 

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int numIsland{0}; 
        
        if (grid.empty() || grid[0].empty()) {
            return numIsland; 
        }
        
        _rowNum = grid.size();
        _colNum = grid[0].size(); 
        
        vector<vector<bool>> visited(_rowNum, vector<bool>(_colNum, false)); 
        
        for (int rowIdx = 0; rowIdx < _rowNum; ++rowIdx) {
            
            for (int colIdx = 0; colIdx < _colNum; ++colIdx) {
            
                /**
                 * at the grid node [rowIdx][colIdx] check two things:
                 * - if the value is '1'
                 * - if the node has been visited
                 **/
                if (!visited[rowIdx][colIdx] && grid[rowIdx][colIdx] == '1') {                    
                    numIsland++;
                    _resetVisitedMatrix(grid, rowIdx, colIdx, visited); 
                }
                
            }
            
        }
            
        return numIsland; 
                
    }

private:
    int _rowNum{0}, _colNum{0}; 
    
    void _resetVisitedMatrix(const vector<vector<char>>& grid, int rowIdx, int colIdx, vector<vector<bool>>& visited) {
        
        visited[rowIdx][colIdx] = true; 
        
        // neighbor above
        if (rowIdx - 1 >= 0 && grid[rowIdx - 1][colIdx] == '1' && !visited[rowIdx - 1][colIdx]) {
            _resetVisitedMatrix(grid, rowIdx - 1, colIdx, visited);
        }
        
        // neighbor below
        if (rowIdx + 1 < _rowNum && grid[rowIdx + 1][colIdx] == '1' && !visited[rowIdx + 1][colIdx]) {
            _resetVisitedMatrix(grid, rowIdx + 1, colIdx, visited);
        }
        
        // left neighbor
        if (colIdx - 1 >= 0 && grid[rowIdx][colIdx - 1] == '1' && !visited[rowIdx][colIdx - 1]) {
            _resetVisitedMatrix(grid, rowIdx, colIdx - 1, visited);
        }
                
        // right neighbor
        if (colIdx + 1 < _colNum && grid[rowIdx][colIdx + 1] == '1' && !visited[rowIdx][colIdx + 1]) {
            _resetVisitedMatrix(grid, rowIdx, colIdx + 1, visited);
        }
        
    }
    
};