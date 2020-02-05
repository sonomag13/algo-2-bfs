//
// Created by lu.gao on 2/4/20.
//

#ifndef SHORTEST_KNIGHT_PATH_SOLUTION_H
#define SHORTEST_KNIGHT_PATH_SOLUTION_H
#include <vector>
#include <queue>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

using namespace std;

class Solution {

public:

    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here

        queue<Point> qPoint;
        int dx[] = {+1, +1, -1, -1, +2, +2, -2, -2};
        int dy[] = {+2, -2, +2, -2, +1, -1, +1, -1};
        int numStep = 0, x1, y1, x2, y2;
        Point currentPoint;

        if(grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        if(source.x == destination.x && source.y == destination.y) {
            return numStep;
        }

        qPoint.push(source);

        while(!qPoint.empty()) {
            numStep++;
            int qSize = qPoint.size();
            for(int i = 0; i < qSize; i++) {
                currentPoint = qPoint.front();
                qPoint.pop();
                x1 = currentPoint.x;
                y1 = currentPoint.y;
                for(int j = 0; j < 8; j++) {
                    x2 = x1 + dx[j];
                    y2 = y1 + dy[j];
                    if((0 <= x2 && x2 < m) && (0 <= y2 && y2 < n) && grid[x2][y2] == false && visited[x2][y2] == false) {
                        if(x2 == destination.x && y2 == destination.y) {
                            return numStep;
                        }
                        visited[x2][y2] = true;
                        qPoint.push(Point(x2, y2));
                    }
                }
            }
        }

        return -1;

    }
};



#endif //SHORTEST_KNIGHT_PATH_SOLUTION_H
