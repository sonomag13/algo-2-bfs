// LeetCode 207 Course Schedule

#include <queue>
#include <unordered_set>
#include <vector>

using namespace std; 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // degree of course i need to be zero. the tricky part is, a course 
        // may have many prerequisites, and all the prerequisites need to 
        // be take before taking course i.
        vector<int> inDegree(numCourses, 0); 

        vector<vector<int>> graphPrereq(numCourses, vector<int>()); 

        for (auto & courses : prerequisites) {
            int courseToTake = courses[0];
            int courseToBlock = courses[1]; 
            ++inDegree[courseToTake];  // a courseToBlock has blocked courseToTake
            graphPrereq[courseToBlock].push_back(courseToTake);
        }

        queue<int> qPrereq;  // course in this queue has no prerequisite
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                qPrereq.push(i);  // no prerequisite means 0 in-degree
            }
        }

        int numTaken = 0; 

        while (!qPrereq.empty()) {
            int curCourse = qPrereq.front();
            qPrereq.pop();
            ++numTaken;
            for (auto nextCourse : graphPrereq[curCourse]) {
                // since the current course is taken, the in degree of the next course 
                // (which is previous blocked by the current course decrease by 1 
                --inDegree[nextCourse]; 
                if (inDegree[nextCourse] == 0) {
                    // all the prerequisite of the next course have been taken
                    qPrereq.push(nextCourse); 
                }
            }
        }

        return numTaken == numCourses ? true : false; 
    }
};