// LeetCode 130 Surrounded Regions

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // if a section is connected to an 'O' on the border, the section will not be marked to 'X'

        numRow = board.size();
        if (numRow == 0) {
            return; 
        }

        numCol = board[0].size();
        if (numCol == 0) {
            return; 
        }

        visited = vector<vector<bool>>(numRow, vector<bool>(numCol, false));
        
        for (int colIdx = 0; colIdx < numCol; ++colIdx) {
            // top row
            int topRow = 0; 
            if (board[topRow][colIdx] == 'O' && visited[topRow][colIdx] == false) {
                bfs(topRow, colIdx, board, false);
            }
            // bottom row
            int bottomRow = numRow - 1;
            if (board[bottomRow][colIdx] == 'O' && visited[bottomRow][colIdx] == false) {
                bfs(bottomRow, colIdx, board, false);
            }
        }

        for (int rowIdx = 1; rowIdx < numRow - 1; ++rowIdx) {
            // left column
            int leftCol = 0; 
            if (board[rowIdx][leftCol] == 'O' && visited[rowIdx][leftCol] == false) {
                bfs(rowIdx, leftCol, board, false);
            }
            // right column
            int rightCol = numCol - 1; 
            if (board[rowIdx][rightCol] == 'O' && visited[rowIdx][rightCol] == false) {
                bfs(rowIdx, rightCol, board, false);
            }
        }

        for (int rowIdx = 1; rowIdx < numRow - 1; ++ rowIdx) {
            for (int colIdx = 1; colIdx < numCol - 1; ++colIdx) {
                if (board[rowIdx][colIdx] == 'O' && visited[rowIdx][colIdx] == false) {
                    bfs(rowIdx, colIdx, board, true); 
                }
            }
        }

    }

private:
    int numRow;
    int numCol; 
    vector<int> dr = {-1, +1, 0, 0};
    vector<int> dc = {0, 0, +1, -1};
    int numDelta = 4; 
    vector<vector<bool>> visited; 

    bool onBoard(int rowIdx, int colIdx) {

        bool cond1 = 0 <= rowIdx && rowIdx < numRow;
        bool cond2 = 0 <= colIdx && colIdx < numCol; 
        return cond1 && cond2; 
    }

    void bfs(int rowIdx, int colIdx, vector<vector<char>> & board, bool flagMark) {

        queue<pair<int, int>> qCoord; 
        qCoord.push(make_pair(rowIdx, colIdx));
        if (flagMark) {
            board[rowIdx][colIdx] = 'X'; 
        }
        
        visited[rowIdx][colIdx] = true; 

        while (!qCoord.empty()) {
            auto coord = qCoord.front();
            qCoord.pop();

            int rowIdx1 = coord.first;
            int colIdx1 = coord.second; 

            for (int i = 0; i < numDelta; ++i) {
                int rowIdx2 = rowIdx1 + dr[i];
                int colIdx2 = colIdx1 + dc[i]; 

                if (!onBoard(rowIdx2, colIdx2)) {
                    continue; 
                }

                if (visited[rowIdx2][colIdx2]) {
                    continue; 
                }

                if (board[rowIdx2][colIdx2] == 'O') {
                    qCoord.push(make_pair(rowIdx2, colIdx2));
                    if (flagMark) {
                        board[rowIdx2][colIdx2] = 'X';
                    }
                    visited[rowIdx2][colIdx2] = true; 
                }
            }
        }
    }

};