//
// Created by luther on 10/18/20.
//

# pragma once

/**
 * Definition for a point.
 */

#include <iostream>
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

        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        // get the size of the grid
        this->rowNum = grid.size();
        this->colNum = grid[0].size();
        this->target.x = destination.x;
        this->target.y = destination.y;

        // start BFS
        int steps = 0;

        queue<Point> quePoint;
        quePoint.push(source);

        // lambda function to check if the point is in the grid
        auto inGrid = [this](const Point& p) {
            bool xflag = (0 <= p.x) && (p.x < this->rowNum);
            bool yflag = (0 <= p.y) && (p.y < this->colNum);
            return xflag && yflag;
        };

        // lambda function to check if the point is at the target
        auto atTarget = [this](const Point& p) {
            return (p.x == this->target.x) && (p.y == this->target.y);
        };

        while (!quePoint.empty()) {

            int queSize = quePoint.size();

            for (int i = 0; i < queSize; ++i) {
                // fetch a point from the queue
                Point currentPoint = quePoint.front();
                quePoint.pop();

                if (atTarget(currentPoint)) {
                    return steps;
                }

                // all the points in this for loop shares the same step numbers
                for (int j = 0; j < 8; ++j) {
                    Point nextPoint(currentPoint.x + dx[j], currentPoint.y + dy[j]);
                    if (atTarget(nextPoint)) {
                        // the next point is the target
                        return steps + 1;
                    }
                    if (inGrid(nextPoint) && grid[nextPoint.x][nextPoint.y] == 0) {
                        /**
                         * set the original grid point to be 1 so it will not be visited again
                         * push the the next point in the queue
                         */
                        grid[nextPoint.x][nextPoint.y] = true;
                        quePoint.push(nextPoint);
                    }
                }
            }
            steps++;
        }

        // the queue is empty but cannot find a path
        return -1;
    }

private:
    int rowNum{0}, colNum{0};
    Point target;
    int dx[8] = {+1, +1, -1, -1, +2, +2, -2, -2};
    int dy[8] = {+2, -2, +2, -2, +1, -1, +1, -1};

};