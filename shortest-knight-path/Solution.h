/*
    611. Knight Shortest Path    
    Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route.
    Return -1 if destination cannot be reached.

    Example
    Example 1:

    Input:
    [[0,0,0],
     [0,0,0],
     [0,0,0]]
    source = [2, 0] destination = [2, 2] 
    Output: 2
    Explanation:
    [2,0]->[0,1]->[2,2]
    Example 2:

    Input:
    [[0,1,0],
     [0,0,1],
     [0,0,0]]
    source = [2, 0] destination = [2, 2] 
    Output:-1
    Clarification
    If the knight is at (x, y), he can get to the following positions in one step:

    (x + 1, y + 2)
    (x + 1, y - 2)
    (x - 1, y + 2)
    (x - 1, y - 2)
    (x + 2, y + 1)
    (x + 2, y - 1)
    (x - 2, y + 1)
    (x - 2, y - 1)
    Notice
    source and destination must be empty.
    Knight can not enter the barrier.
    Path length refers to the number of steps the knight takes.
 */

#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {
    }
};

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        
        // write your code here
        this->rowNum = grid.size(); 
        this->colNum = grid[0].size(); 
        int stepNum{0};
        int dx[] = {+1, +1, -1, -1, +2, +2, -2, -2}; 
        int dy[] = {+2, -2, +2, -2, +1, -1, +1, -1}; 
        
        // the grid is not well defined
        if (rowNum == 0 || colNum == 0) {
            return -1; 
        }
        
        // the sourse just happen to be the target
        if (source.x == destination.x && source.y == destination.y) {
            return stepNum; 
        }
        
        // matrix to record if a node has been visited
        vector<vector<bool>> visitedMatrix(rowNum, vector<bool>(colNum, false)); 
        
        // establish the BFS
        queue<Point> quePoints; 
        quePoints.push(source);
        
        bool inGrid, visited; 
        
        while (!quePoints.empty()) {
            
            // num of the possible source points
            int n = quePoints.size(); 
            
            for (int i = 0; i < n; ++i) {
                // check out a node
                Point currPoint{quePoints.front()}; 
                quePoints.pop();
                
                for (int j = 0; j < 8; ++j) {
                    int x{currPoint.x + dx[j]};
                    int y{currPoint.y + dy[j]}; 
                    
                    // if the point in the boundary
                    inGrid = isInGrid(x, y); 
                    
                    // if the node has been visited
                    if (inGrid) {
                        visited = visitedMatrix[x][y];
                    }
                    
                    // the node is in the boundary and not visited
                    if (inGrid && !visited && !grid[x][y]) {
                        if (x == destination.x && y == destination.y) {
                            return stepNum + 1; 
                        } 
                        
                        quePoints.push(Point(x, y));
                        visitedMatrix[x][y] = true; 
                    }
                }
                
            }
            stepNum++; 
        }
        
        // run out of the option
        return -1;
    }
    
private:
    int rowNum{0}, colNum{0}; 
    
    bool isInGrid(int x, int y) {
        bool condx{0 <= x && x < rowNum}; 
        bool condy{0 <= y && y < colNum}; 
        return condx && condy; 
    }
    
};