#pragma once

#include <vector>

using namespace std; 

class UnionFind {
public:
UnionFind(const vector<vector<char>>& grid) {
    int numRow = grid.size(), numCol = grid[0].size();    
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numCol; ++j) {
            if (grid[i][j] == '1') {
                // the 2D index of the grid is serialized as an 1d array
                parent.push_back(i * numCol + j); 
                // if there is 1, it might be an isolated island
                cnt++; 
            }
            else {
                parent.push_back(-1); 
            }
            rank.push_back(0); 
        }
    }
}

~UnionFind() = default; 

int find(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p]; 
    }
    return p;
}
    
void unionize(int p, int q) {
    
    int p_root = find(p);
    int q_root = find(q);
    
    if (p_root == q_root) {
        return; 
    }
    
    if (rank[p_root] < q_root) {
        parent[q_root] = p_root; 
    }
    else if (rank[p_root] > q_root) {
        parent[p_root] = q_root;
    }
    else {
        parent[p_root] = q_root;
        rank[p_root]++; 
    }
    
    // p and q have been unized, such that the island increase by 1
    cnt--; 
}

int getCounter() const {
    return cnt; 
}
    
private:    
vector<int> parent; 
vector<int> rank; 
int cnt = 0; 

};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        numRow = grid.size();
        if (!numRow) {
            return 0; 
        }        
        numCol = grid[0].size();    
        
        UnionFind uf(grid); 
        
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {                
                int idx1 = calcIdx(i, j);
                if (grid[i][j] == '1') {                    
                    grid[i][j] = '0';
                    
                    for (int k = 0; k < 4; ++k) {
                        int i2 = i + dx[k], j2 = j + dy[k];
                        if (inGrid(i2, j2) && grid[i2][j2] == '1') {
                            int idx2 = calcIdx(i2, j2);
                            uf.unionize(idx1, idx2);
                        }
                    }
                    
                }
            }
        }
        
        return uf.getCounter();
        
    }

private:
int numRow;
int numCol;
    
vector<int> dx{-1, +1,  0,  0};
vector<int> dy{ 0,  0, -1, +1};
    
bool inGrid(int rowIdx, int colIdx) {    
    return 0<= rowIdx && rowIdx < numRow && 0 <= colIdx && colIdx < numCol;
}

int calcIdx(int rowIdx, int colIdx) {            
    return rowIdx * numCol + colIdx; 
}

};