/*
    433. Number of Islands
    中文English
    Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

    Find the number of islands.

    Example
    Example 1:

    Input:
    [
      [1,1,0,0,0],
      [0,1,0,0,1],
      [0,0,0,1,1],
      [0,0,0,0,0],
      [0,0,0,0,1]
    ]
    Output:
    3
    Example 2:

    Input:
    [
      [1,1]
    ]
    Output:
    1
 */

#include <vector>

using namespace std; 

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        _numRow = grid.size();
        if (!_numRow) {
            return 0; 
        }
        _numCol = grid[0].size();
        if (!_numCol) {
            return 0; 
        }
        
        int counter; 
        
        for (int i = 0; i < _numRow; ++i) {
            for (int j = 0; j < _numCol; ++j) {
                if (grid[i][j] == '1') {                    
                    counter++;
                    _resetGrid(grid, i, j);
                }                        
            }
        }
        
        return counter; 
        
    }
    
private: 
    int _numRow{0}; 
    int _numCol{0};
    
    void _resetGrid(vector<vector<char>>& grid, int i, int j) {
        
        if (!_inGrid(i, j) || grid[i][j] == '0') {
            return; 
        }
        
        // [i, j] in the grid and its value is 1
        grid[i][j] = '0'; 
        
        // explore the neighbors
        _resetGrid(grid, i + 1, j);
        _resetGrid(grid, i - 1, j);
        _resetGrid(grid, i, j + 1);
        _resetGrid(grid, i, j - 1);

    }
    
    bool _inGrid(int i, int j) {
        return 0 <= i && i < _numRow && 0 <= j && j < _numCol; 
    }
    s
};