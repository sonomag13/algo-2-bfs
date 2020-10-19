//
// Created by luther on 10/18/20.
//

#include <iostream>
#include <vector>

#include "Solution2.h"

using namespace std;

int main() {

    int rowNum = 3;
    int colNum = 3;

    vector<vector<bool>> grid(rowNum, vector<bool>(colNum, false));

    Point start(2, 0);
    Point destination(2, 2);

    Solution solution;
    int stepNum = solution.shortestPath(grid, start, destination);

    cout << "steps = " << stepNum << endl;

    return EXIT_SUCCESS;
}