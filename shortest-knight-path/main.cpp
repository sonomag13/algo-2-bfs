#include <iostream>
#include <vector>
#include <stack>
#include "Solution.h"

using namespace std;

int main() {

    int nx = 3, ny = 3;
    Point source(2, 0), destination(2, 2);
    int x = destination.x, y = destination.y;
    int x2, y2;
    vector<vector<bool>> grid(nx, vector<bool>(ny, false));
    vector<vector<int>> action;
    stack<pair<int, int>> stackPath;
    pair<int, int> currentPair;
    Solution shortestKnightPath;
    int numStepShortestPath = shortestKnightPath.shortestPath(grid, source, destination);
    cout << "number of steps in the shortest path = " << numStepShortestPath << endl;

    if(numStepShortestPath != -1) {
        action = shortestKnightPath.getShortestPath(grid, source, destination);
        stackPath.push(make_pair(x, y));
        while(x != source.x || y != source.y) {
            x2 = x - dx[action[x][y]];
            y2 = y - dy[action[x][y]];
            stackPath.push(make_pair(x2, y2));
            x = x2;
            y = y2;
        }
        cout << "A shortest path is " << endl;
        while(!stackPath.empty()) {
            currentPair = stackPath.top();
            stackPath.pop();
            cout << "x = " <<  currentPair.first << " and y = " <<  currentPair.second << " --> " << endl;
        }
    }

    return 0;

}
