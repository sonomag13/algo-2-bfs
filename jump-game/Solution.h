// 55. Jump Game

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.empty()) {
            return false; 
        }

        int size = nums.size(); 

        int finalPosition = size - 1; 

        queue<int> queCandidate; 
        queCandidate.push(0); 

        vector<bool> visited(size, false); 
        visited[0] = false; 

        while(!queCandidate.empty()) {

            int curPosition = queCandidate.front();
            queCandidate.pop(); 

            // the current position is the final position 
            if (curPosition == finalPosition) {
                return true; 
            }

            int maxSteps = nums[curPosition];
            for(int step = 1; step <= maxSteps; ++step) {
                int nextPosition = curPosition + step; 

                // the next position is out of the boundary
                if (nextPosition > finalPosition) {
                    break;
                }

                // the position has already been visited
                if (visited[nextPosition]) {
                    continue; 
                }

                queCandidate.push(nextPosition); 
                visited[nextPosition] = true; 
            }
        } 

        return false; 
    }
};