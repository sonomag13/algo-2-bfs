#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int>& start, vector<int>& destination) {
        // size of the maze
        _rowNum = maze.size();
        _colNum = maze.at(0).size();
        if (!_rowNum || !_colNum) {
            return -1;
        }

        // the element in the queue contains (x, y) and number of steps to get to (x, y)
        queue<vector<int>> queEndPoint;
        queEndPoint.push(vector<int>{start.at(0), start.at(1), 0});

        set<vector<int>> visited;

        // start BFS
        while(!queEndPoint.empty()) {

            // check out an end point from the queue
            vector<int> currPoint = queEndPoint.front();
            queEndPoint.pop();

            /**
             * notice that the currPoint has 3 elements:
             * - the first 2 represent (x, y) coordinate
             * - the third one represents the number of steps to get to (x, y)
             *
             * However, we only want to insert the coordinate into the set visited, so that we need to unpack the
             * current point
             **/
            vector<int> currCoord{currPoint.at(0), currPoint.at(1)};
            if (visited.find(currCoord) != visited.end()) {
                continue;
            }
            visited.insert(currCoord);

            // traverse the rolling directions of the ball and get the end point
            for (auto& dir : _directions) {
                vector<int> nextEndPoint{_move2EndPoint(maze, currPoint, dir)};
                if (_isDest(nextEndPoint, destination)) {
                    // the ball has arrived the destination
                    return nextEndPoint.at(2);
                }
                else {
                    // the ball has not arrived the destination yet
                    if (visited.find(nextEndPoint) == visited.end()) {
                        // the next point has not been, so that pushed the point into the queue
                        queEndPoint.push(nextEndPoint);
                    }
                }
            }
        }

        return -1;

    }

private:

    // size of the maze
    int _rowNum{0}, _colNum{0}, level{0};

    // a set to record the visited points
    set<vector<int>> _visited;

    // 4 possible directions to move: up, down, left and right
    vector<vector<int>> _directions{vector<int>{+1, 0}, vector<int>{-1, 0}, vector<int>{0, +1}, vector<int>{0, -1}};

    /**
     * check if the current point is the target
     * notice that the point has 3 elements, i.e. (x, y) and number of steps to get the (x, y)
     **/
    static bool _isDest(const vector<int>& point, const vector<int>& dest) {
        bool flag = true;
        for (int i = 0; i < dest.size(); ++i) {
            flag = flag && (dest.at(i) == point.at(i));
        }
        return flag;
    }

    // move the ball to the end point
    vector<int> _move2EndPoint(const vector<vector<int>>& maze, const vector<int>& currPoint, const vector<int>& direction) {

        // lambda function to add two vectors
        auto add_vectors = [] (const vector<int>& v1, const vector<int>& v2) {
            vector<int> v3(2, 0);
            for (int i = 0; i < v3.size(); ++i) {
                v3[i] = v1[i] + v2[i];
            }
            return v3;
        };

        // lambda function to check if the point is in the boundary
        auto inMaze = [this] (const vector<int>& point) {
            bool cond1{point[0] >= 0 && point[0] < this->_rowNum};
            bool cond2{point[1] >= 0 && point[1] < this->_colNum};
            return cond1 && cond2;
        };

        // lambda function to check if the point is available to travel
        auto isValid = [] (const vector<vector<int>>& maze, const vector<int>& point) {
            return !maze[point.at(0)][point.at(1)];
        };

        /**
         * check out:
         * - current position of the ball
         * - the number of steps that the ball has already experienced
         **/
        vector<int> rollingPoint{currPoint.at(0), currPoint.at(1)};
        int numStep{currPoint.at(2)};

        // move the current point along the given direction and count the steps
        while(true) {
            vector<int> nextPoint{add_vectors(rollingPoint, direction)};
            if (inMaze(nextPoint) && isValid(maze, nextPoint)) {
                // the rolling point is not an end point, i.e. the next point is not the wall
                rollingPoint = nextPoint;
                numStep++;
            }
            else{
                // the rolling point is an end point, i.e. the next point is the wall
                rollingPoint.push_back(numStep);
                return rollingPoint;
            }
        }
    }

};