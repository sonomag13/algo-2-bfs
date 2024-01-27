// 45. Jump Game II

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int size = nums.size(); 
        vector<bool> visited(size, false); 
        vector<int> jumps(size, 0); 
        queue<int> queIdx; 
        queIdx.push(0);  // at position 0 there is 0 steps
        visited[0] = true; 

        while (!queIdx.empty()) {
            int idx = queIdx.front();
            queIdx.pop();
            if (idx == size - 1) {
                return jumps[idx]; 
            }

            int curJumps = jumps[idx]; 

            for (int i = 1; i <= nums[idx]; ++i) {
                int nextIdx = idx + i; 
                if (nextIdx >= size || visited[nextIdx]) {
                    continue; 
                }
                queIdx.push(nextIdx);
                jumps[nextIdx] = curJumps + 1; 
                visited[nextIdx] = true; 
            }
        }

        return -1; 
    }
};