/**
    615. Course Schedule

    There are a total of n courses you have to take, labeled from 0 to n - 1.

    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

    Example
    Example 1:

    Input: n = 2, prerequisites = [[1,0]] 
    Output: true
    Example 2:

    Input: n = 2, prerequisites = [[1,0],[0,1]] 
    Output: false
 */

#include <queue>
#include <unordered_set>
#include <vector>

using namespace std; 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int numTaken{0};
        
        // in-degree
        vector<int> inDegree(numCourses, 0);
        
        // courses blocked by course [i]
        vector<vector<int>> blockedCourse(numCourses); 
        
        // calculate in-degree and course that is blocked
        for (auto & course : prerequisites) {
            int courseToTake{course[0]};             
            int coursePrereq{course[1]};
            // update the in degree to take the course
            inDegree[courseToTake]++;                   
            // update the course that is blocked by the prerequisite
            blockedCourse[coursePrereq].push_back(courseToTake);                        
        }
        
        queue<int> queCourseCanTake;        
        for (int i = 0; i < inDegree.size(); ++i) {            
            if (!inDegree[i]) {
                queCourseCanTake.push(i);
            }            
        }
        
        while (!queCourseCanTake.empty()) {            
            int numCanTake = queCourseCanTake.size();            
            for (int i = 0; i < numCanTake; ++i) {                
                int currCourse = queCourseCanTake.front();
                queCourseCanTake.pop();                
                // a course is taken
                numTaken++; 
                // update the course that is blocked
                vector<int> currBlockedCourse = blockedCourse[currCourse];                
                for (auto course : currBlockedCourse) {
                    inDegree[course]--;
                    if (!inDegree[course]) {
                        queCourseCanTake.push(course);
                    }
                }                                
            }                        
        }                
        
        return numTaken == numCourses; 
        
    }
};
