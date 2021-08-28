/*
    1197. Minimum Knight Moves
    Medium

    In an infinite chess board with coordinates from -infinity to +infinity, 
    you have a knight at square [0, 0].

    A knight has 8 possible moves it can make, as illustrated below. 
    Each move is two squares in a cardinal direction, then one square 
    in an orthogonal direction.


    Return the minimum number of steps needed to move the knight to the 
    square [x, y]. It is guaranteed the answer exists. 

    Example 1:

    Input: x = 2, y = 1
    Output: 1
    Explanation: [0, 0] → [2, 1]
    Example 2:

    Input: x = 5, y = 5
    Output: 4
    Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 */

#include <vector>
#include <queue>
#include <set>

using namespace std; 

class Solution {
public:
    int minKnightMoves(int x, int y) {
        
        int numSteps{0}; 
        
        pair<int, int> target(x, y);
        pair<int, int> initPos(0, 0);
        
        set<pair<int, int>> visited;
        visited.insert(initPos);
        
        queue<pair<int, int>> quePos; 
        quePos.push(initPos); 
        
        while (!quePos.empty()) {            
            int numPos = quePos.size();            
            for (int i = 0; i < numPos; ++i) {
                // check out a potential position from the queue
                pair<int, int> currPos = quePos.front();
                quePos.pop();
                if(currPos == target) {
                    return numSteps;
                }
                else {
                    _getNextPosition(currPos, visited, quePos);
                }
            }
            
            numSteps++; 
            
        }
        
        return -1;
        
    }
    
private:
    vector<int> xMotion{+2, +1, -1, -2, -2, -1, +1, +2};
    vector<int> yMotion{+1, +2, +2, +1, -1, -2, -2, -1};    
    
    void _getNextPosition(const pair<int, int>& currPos, set<pair<int, int>>& visited, queue<pair<int, int>>& quePos) {
        
        for (int i = 0; i < xMotion.size(); ++i) {
            pair<int, int> nextPos(currPos.first + xMotion[i], currPos.second + yMotion[i]);
            if (visited.find(nextPos) == visited.end()) {
                visited.insert(nextPos);
                quePos.push(nextPos);
            }
        }
        
    }
    
};


// a trickier solution 

class Solution2 {
public:
    int minKnightMoves(int x, int y) {
        
        int numSteps{0}; 
        
        // use symmetry, to convert the problem into first quadrant        
        target.first = abs(x);
        target.second = abs(y);
        pair<int, int> initPos(0, 0);
        
        set<pair<int, int>> visited;
        visited.insert(initPos);
        
        queue<pair<int, int>> quePos; 
        quePos.push(initPos); 
        
        while (!quePos.empty()) {            
            int numPos = quePos.size();            
            for (int i = 0; i < numPos; ++i) {
                // check out a potential position from the queue
                pair<int, int> currPos = quePos.front();
                quePos.pop();
                if(currPos == target) {
                    return numSteps;
                }
                else {
                    _getNextPosition(currPos, visited, quePos);
                }
            }
            
            numSteps++; 
            
        }
        
        return -1;
        
    }
    
private:
    pair<int, int> target; 
    vector<int> xMotion{+2, +1, -1, -2, -2, -1, +1, +2};
    vector<int> yMotion{+1, +2, +2, +1, -1, -2, -2, -1};    
    
    void _getNextPosition(const pair<int, int>& currPos, set<pair<int, int>>& visited, queue<pair<int, int>>& quePos) {
        
        for (int i = 0; i < xMotion.size(); ++i) {
            pair<int, int> nextPos(currPos.first + xMotion[i], currPos.second + yMotion[i]);            
            bool cond1 = visited.find(nextPos) != visited.end();
            bool cond2 = nextPos.first < -2 || nextPos.second < -2;
            bool cond3 = nextPos.first > target.first + 2 || nextPos.second > target.second + 2;
            
            if (cond1 || cond2 || cond3) { 
                continue;
            }
            else {
                visited.insert(nextPos);
                quePos.push(nextPos);
            }
        }
        
    }
    
};