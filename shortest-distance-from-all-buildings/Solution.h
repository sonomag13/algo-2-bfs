// LeetCode 317. Shortest Distance from All Buildings
// Hard

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        // empty grid
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1; 
        }
        
        // set up the rows and columns
        numRow = grid.size();
        numCol = grid[0].size();
        
        int numBuildings = 0; // number of buildings
        
        // total distance of 0 to all the buildings
        dist2Buildings = vector<vector<int>>(numRow, vector<int>(numCol, 0));

        // the number of the buildings 
        numBuildingReached = vector<vector<int>>(numRow, vector<int>(numCol, 0));
        
        for (int r = 0; r < numRow; r++) {
            for (int c = 0; c < numCol; c++) {
                if (grid[r][c] == 1) { 
                    numBuildings++; 
                    if (!bfs(grid, r, c)) {
                        // if currently at a building, now calculate two things:
                        // - distance between this build and all the empty space, 
                        //   i.e. 0 where we can build a building) 
                        // - if this build can be connected with all the other 
                        //   buildings
                        return -1; 
                    }
                }
            }
        }

        // at this point, at a grid[r][c] == 0, dist2Buildings[r][c] has the value 
        // of an accumulative sum of the distances between [r][c] and all the buildings
        
        for (int r = 0; r < numRow; ++r) {
            for (int c = 0; c < numCol; ++c) {
                /**
                 * check all the zero values in the grid, and if it can reach all
                 * the buildings, then compare its distance with the min distance
                 **/
                bool cond0 = grid[r][c] == 0; 
                bool cond1 = numBuildingReached[r][c] == numBuildings;
                bool cond2 = dist2Buildings[r][c] < minDist;                 
                if (cond0 && cond1 && cond2) {
                    minDist = dist2Buildings[r][c]; 
                }
            }
        }
        
        return minDist == INT_MAX? -1 : minDist; 
        
    }
    
private:    
    int numRow, numCol; 
    vector<vector<int>> dist2Buildings;   // accumulative dist between 0 and buildings
    vector<vector<int>> numBuildingReached; // number of the buildings can be reached out by a 0
    int minDist = INT_MAX; 
    
    // motions
    vector<int> dr = {-1, +1,  0,  0};
    vector<int> dc = { 0,  0, +1, -1}; 
    
    bool bfs(const vector<vector<int>>& grid, int r, int c) {
        
        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false)); 

        /**
         * interestingly, the [r, c] inserted here is a building, but
         * in the loop below, the [r, c] is 0
         **/        
        queue<pair<int, int>> queCoord; 
        queCoord.push(make_pair(r, c));
        visited[r][c] = true; 
        
        int dist = 0; 
        
        while (!queCoord.empty()) {
            int n = queCoord.size(); 
            dist++; // since we use Manhattan distance, each step the distance insreases by 1
            
            for (int i = 0; i < n; ++i) {
                
                pair<int, int> curr = queCoord.front();
                queCoord.pop();
                int r1 = curr.first; 
                int c1 = curr.second; 
                
                for (int k = 0; k < 4; k++) {
                    // traverse the neighbors of [r, c]                    
                    int r2 = r1 + dr[k];
                    int c2 = c1 + dc[k]; 
                    
                    if (!isValid(grid, r2, c2, visited)) {                        
                        continue;  // if invalid, continue
                    }
                                        
                    visited[r2][c2] = true;  // [r2, c2] is set to be reached
                                        
                    if (grid[r2][c2] == 0) {
                        /**
                         * if [r2, c2] is a zero, accumulate the dist with the current distance
                         * Notice that the current distance is resulted from the building at [r, c]
                         **/
                        dist2Buildings[r2][c2] += dist; 
                        numBuildingReached[r2][c2]++;                        
                        queCoord.push(make_pair(r2, c2));  // push 0 into the queue for further search
                    }                                                            
                }                
            }
        }
        
        for (int r = 0; r < numRow; ++r) {
            for (int c = 0; c < numCol; ++c) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    return false;  // a building must be visited
                }
            }
        }
        
        return true; 
        
    }
    
    bool isValid(const vector<vector<int>>& grid, int r, int c, const vector<vector<bool>>& visited) {        
        // return false if:
        // - [r, c] is 2
        // - [r, c] is out of the boundary
        // - [r, c] has been visited
        // otherwise return true

        if (r < 0 || r >= numRow || c < 0 || c >= numCol) {
            return false; 
        }
        
        if (grid[r][c] == 2) {
            return false; 
        }
        
        if (visited[r][c]) {
            return false;
        }
        
        return true; 
         
    }
    
    
};