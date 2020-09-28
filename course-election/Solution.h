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
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    static bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /**
         * pair.first = course to take
         * pair.second = prerequisit course
         */ 
        
        int numTaken{0}; 
        
        queue<int> ready2take; 
        
        /**
         * in_degree
         * - index: id number of the course
         * - val: in-degree, i.e. this value increase by one for every 
         *   prerequisites as it has
         */
        vector<int> in_degree(numCourses, 0); 
        
        /**
         * edge of courses:
         * - index: id number of the course
         * - val: the course blocked by the course
         */
        vector<unordered_multiset<int>> edges(numCourses); 
        
        // initialize the in-degree and edge
        for (auto coursePair : prerequisites) {
            int id = coursePair.first;
            int pre = coursePair.second; 
            in_degree[id]++; 
            edges[pre].insert(id); 
        }
        
        // the course with 0 in degree are ready to take, and push them into the queue 
        for (int i = 0; i < in_degree.size(); ++i) {
            if (in_degree[i] == 0) {
                ready2take.push(i);
            }
        }
        
        while (!ready2take.empty()) {
            int course = ready2take.front();
            ready2take.pop();
            numTaken++; 
            /**
             * Since a course is taken, all the in-degree of the courses blocked by this 
             * course decreases by 1
             * Notice that all the courses bloked by the current course is stored in edges
             */ 
            unordered_multiset<int> edge = edges[course]; 
            for (auto val : edge) {
                in_degree[val]--;
                if (!in_degree[val]) {
                    ready2take.push(val); 
                }
            }
        }
        
        return numTaken == numCourses;
        
    }
};