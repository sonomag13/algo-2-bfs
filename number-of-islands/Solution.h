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

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    
    int numIslands(vector<vector<bool>> &grid) {
        
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0; 
        }
        
        // write your code here
        int counterIsland{0}; 
        this->rowNum = grid.size();
        this->colNum = grid[0].size(); 
        
        // loop through the grid
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (grid[i][j]) {
                    counterIsland++; 
                    updateVisitedMatrix(i, j, grid);
                }
            }
        }
        return counterIsland; 
    }
    
private:

    int rowNum{0}, colNum{0}; 

    void updateVisitedMatrix(int i, int j, vector<vector<bool>>& grid) {
        // check if out of the boundary
        // cout << "err: i = " << i << " and j = " << j << endl; 
        if (i < 0 || i >= rowNum || j < 0 || j >= colNum) {
            return; 
        }
        if (!grid[i][j]) {
            return; 
        }
        grid[i][j] = false; 
        updateVisitedMatrix(i+1, j, grid);
        updateVisitedMatrix(i, j+1, grid);
        updateVisitedMatrix(i-1, j, grid);
        updateVisitedMatrix(i, j-1, grid);
    }
    
    
};