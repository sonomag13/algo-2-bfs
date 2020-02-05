#include <iostream>
#include "Solution.h"
#include <vector>

using namespace std;

int main() {

    int nx = 3, ny = 3;
    Point source(2, 0), destination(2, 2);
    vector<vector<bool>> grid(nx, vector<bool>(ny, false));
    Solution shortestKnightPath;
    int numStepShortestPath = shortestKnightPath.shortestPath(grid, source, destination);

    cout << "number of steps in the shortest path = " << numStepShortestPath << endl;

    return 0;
}
