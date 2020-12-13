#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    /**
     * [0,0,1,0,0]
     * [0,0,0,0,0]
     * [0,0,0,1,0]
     * [1,1,0,1,1]
     * [0,0,0,0,0]
     **/

    vector<vector<int>> maze{vector<int>{0, 0, 1, 0, 0},
                             vector<int>{0, 0, 0, 0, 0},
                             vector<int>{0, 0, 0, 1, 0},
                             vector<int>{1, 1, 0, 1, 1},
                             vector<int>{0, 0, 0, 0, 0}};

    vector<int> start{0, 4};
    // vector<int> end{4, 4}; // steps = 12
    vector<int> end{3, 2}; // steps = -1

    for (auto & row : maze) {
        for (auto val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    Solution solution;
    int numSteps{solution.shortestDistance(maze, start, end)};

    cout << "numSteps = " << numSteps << endl;
}