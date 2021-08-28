/*
    210. Course Schedule II
    Medium

    There are a total of numCourses courses you have to take, 
    labeled from 0 to numCourses - 1. You are given an array prerequisites 
    where prerequisites[i] = [ai, bi] indicates that you must take course bi 
    first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have 
    to first take course 1.
    
    Return the ordering of courses you should take to finish all courses. 
    
    If there are many valid answers, return any of them. 
    
    If it is impossible to finish all courses, return an empty array.

    Example 1:

    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 
    1 you should have finished course 0. So the correct course order is [0,1].
    
    Example 2:

    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 
    you should have finished both courses 1 and 2. Both courses 1 and 2 should 
    be taken after you finished course 0.
    
    So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
    
    Example 3:

    Input: numCourses = 1, prerequisites = []
    Output: [0]

 */

#include <queue>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> result; 
        
        vector<int> inDegree(numCourses, 0);        
        vector<vector<int>> blockedCourse(numCourses); 
        
        for (auto & course : prerequisites) {
            int courseToTake{course[0]};
            int coursePrereq{course[1]};
            // increase the in degree by 1 for every course to take
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
                
                result.push_back(currCourse); 
                
                vector<int> currBlockedCourse = blockedCourse[currCourse];                
                for (auto course : currBlockedCourse) {
                    inDegree[course]--; 
                    if (!inDegree[course]) {
                        queCourseCanTake.push(course);
                    }
                }
            }            
        }
        
        // return the result only if the course can be taken
        return result.size() == numCourses ? result : vector<int>{};
            
    }
};