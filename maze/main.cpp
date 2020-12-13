

#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> maze{vector<int>{0, 0, 1, 0, 0},
                             vector<int>{0, 0, 0, 0, 0},
                             vector<int>{0, 0, 0, 1, 0},
                             vector<int>{1, 1, 0, 1, 1},
                             vector<int>{0, 0, 0, 0, 0}};
    vector<int> start{0, 4};
    vector<int> end{4, 4};

    for (auto & row : maze) {
        for (auto val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    Solution solution;
    bool hasPath{solution.hasPath(maze, start, end)};

    cout << "hasPath = " << hasPath << endl;
}