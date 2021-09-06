// LeetCode 118. Pascal's Triangle
// Easy

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result; 
        
        result.push_back(vector<int>{1}); 
        
        for (int i = 1; i < numRows; ++i) {
            
            vector<int> preRow{result[i - 1]}; 
            
            vector<int> curRow{1};             
            for (int j = 1; j < i + 1; ++j) {
                if (j >= preRow.size()) {
                    break; 
                }
                else {
                    curRow.push_back(preRow[j - 1] + preRow[j]);
                }
            }            
            curRow.push_back(1);
            
            result.push_back(curRow); 
        }
                        
        return result;         
        
    }
};