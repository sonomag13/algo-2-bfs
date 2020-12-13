/*
    787. The Maze
    There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

    Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

    The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

    Example
    Example 1:

    Input:
    map =
    [
    [0,0,1,0,0],
    [0,0,0,0,0],
    [0,0,0,1,0],
    [1,1,0,1,1],
    [0,0,0,0,0]
    ]
    start = [0,4]
    end = [3,2]
    Output:
    false
    Example 2:

    Input:
    map =
    [[0,0,1,0,0],
    [0,0,0,0,0],
    [0,0,0,1,0],
    [1,1,0,1,1],
    [0,0,0,0,0]
    ]
    start = [0,4]
    end = [4,4]
    Output:
    true
    Notice
    1.There is only one ball and one destination in the maze.
    2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

 */

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // initialization
        _rowNum = maze.size();
        _colNum = maze.at(0).size();
        if (!_rowNum || !_colNum) {
            // empty maze
            return false;
        }

        // start BFS
        return _hasPath(maze, start, destination);
    }

private:
    // size of the maze
    int _rowNum{0}, _colNum{0};

    // a set to record the visited points
    set<vector<int>> _visited;

    // 4 possible directions to move: up, down, left and right
    vector<vector<int>> _directions{vector<int>{+1, 0}, vector<int>{-1, 0}, vector<int>{0, +1}, vector<int>{0, -1}};

    /**
     * if the current point has already been visited previously, then return false
     **/
    bool _hasPath(const vector<vector<int>>& maze, const vector<int>& current, const vector<int>& dest) {

        if (_visited.find(current) != _visited.end()) {
            // the current point has already been visited previous, and does not match the dest
            return false;
        }
        else {
            // insert the point into the set as it has been visited
            _visited.insert(current);
        }

        // BFS across 4 moving directions
        for (auto & direction : _directions) {
            vector<int> endpoint = toEnd(maze, current, direction);
            // here we recursively check if there is an endpoint that matches the destination
            if (endpoint == dest || _hasPath(maze, endpoint, dest)) {
                return true;
            }
        }

        return false;
    }

    // this function moves the ball from the current point to the end along the given direction
    vector<int> toEnd(const vector<vector<int>>& maze, vector<int> current, const vector<int>& direction) {

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

        // move the current point along the given direction
        while(true) {
            vector<int> endpoint{add_vectors(current, direction)};
            if (inMaze(endpoint) && isValid(maze, endpoint)) {
                current = endpoint;
            }
            else{
                return current;
            }
        }
    }

};