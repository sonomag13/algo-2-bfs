//
// Created by lu.gao on 12/14/19.
//

#ifndef NUMBER_OF_ISLANDS_SOLUTION_H
#define NUMBER_OF_ISLANDS_SOLUTION_H

#include <vector>
#include "String2Vector.h"

using namespace std;

class Solution {

public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size();
        int N = grid[0].size();
        int counter = 0;
        cout << "M = " << M << " and N = " << N << endl;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j]) {
                    counter += 1;
                    cout << "\ncounter = " << counter << " @ i = " << i << " and j = " << j << endl;
                    islandBFS(i, j, grid);
                }
            }
        }
        return counter;
    }

private:

    void islandBFS(int i, int j, vector<vector<bool>> &grid) {
        int M = grid.size();
        int N = grid[0].size();
        if(!isIngrid(i, M) || !isIngrid(j, N)) {
            return;
        }
        if(!grid[i][j]) {
            return;
        }
        grid[i][j] = false;
        islandBFS(i + 1, j, grid);
        islandBFS(i - 1, j, grid);
        islandBFS(i, j + 1, grid);
        islandBFS(i, j - 1, grid);
    }

    bool isIngrid(int idx, int boundary) {
        if (idx >= 0 && idx < boundary) {
            return true;
        }
        else {
            return false;
        }
    }

};


#endif //NUMBER_OF_ISLANDS_SOLUTION_H
