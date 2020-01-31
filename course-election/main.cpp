// LintCode 615 and 616

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool canFinish(int, vector<pair<int, int>>&);
void getCrouseOrder(int, vector<pair<int, int>>&, vector<int>*);

int main() {
    int numCourse = 5;
    int toTake[] = {1, 2, 3, 4};
    int preReq[] = {0, 0, 1, 3};
    vector<pair<int, int>> vectPrereq;
    vector<int>* courseOrdervectorPtr = new vector<int>;
    for(int i = 0; i < sizeof(toTake)/sizeof(int); i++) {
      vectPrereq.push_back(make_pair(toTake[i], preReq[i]));
    };

    bool flagFinish = canFinish(numCourse, vectPrereq);
    printf("\n\nCan we finish all the %d courses? %s\n\n", numCourse, flagFinish ? "true" : "false");

    getCrouseOrder(numCourse, vectPrereq, courseOrdervectorPtr);
    cout << "\nOrder of the class: " << endl;
    for(auto itr = courseOrdervectorPtr->begin(); itr != courseOrdervectorPtr->end(); itr++) {
        cout << *itr << " -> " << endl;
    }

    return 0;
}

bool canFinish(int numCourse, vector<pair<int, int>>& vectPrereq) {
    int numTaken = 0;
    vector<int> inDegree(numCourse, 0);
    vector<unordered_multiset<int>> courseEdges(numCourse);
    pair<int, int> currentPair;
    unordered_multiset<int> currentSet;
    queue<int> qRead2Take;
    int coursePrereq, course2Take;
    int courrentCourse, followingCourse;
    for(auto itr = vectPrereq.begin(); itr != vectPrereq.end(); itr++) {
        currentPair = *itr;
        course2Take = currentPair.first;
        coursePrereq = currentPair.second;
        inDegree[course2Take]++;
        courseEdges[coursePrereq].insert(course2Take);
    }
    for(int i = 0; i < inDegree.size(); i++) {
        if(inDegree[i] == 0) {
            qRead2Take.push(i);
        }
    }
    while(!qRead2Take.empty()) {
        courrentCourse = qRead2Take.front();
        qRead2Take.pop();
        numTaken++;
        currentSet = courseEdges[courrentCourse];
        for(auto itr = currentSet.begin(); itr != currentSet.end(); itr++) {
            followingCourse = *itr;
            inDegree[followingCourse]--;
            if(inDegree[followingCourse] == 0) {
                qRead2Take.push(followingCourse);
            }
        }
    }
    return numTaken == numCourse;
}

void getCrouseOrder(int numCourse, vector<pair<int, int>>& vectPrereq, vector<int>* courseOrdervectorPtr) {
    int numCourseTaken = 0;
    int course2Take, coursePre, courseCurrent, courseFollowing;
    queue<int> qRead2Take;
    pair<int, int> coursePair;
    vector<unordered_multiset<int>> courseBranch(numCourse);
    unordered_multiset<int> currentBranch;
    vector<int> inDegree(numCourse, 0);
    for(auto itr = vectPrereq.begin(); itr != vectPrereq.end(); itr++) {
        coursePair = *itr;
        course2Take = coursePair.first;
        coursePre = coursePair.second;
        inDegree[course2Take]++;
        courseBranch[coursePre].insert(course2Take);
    }
    for(auto itr = inDegree.begin(); itr != inDegree.end(); itr++) {
        if(*itr == 0) {
            qRead2Take.push(*itr);
        }
    }
    while(!qRead2Take.empty()) {
        courseCurrent = qRead2Take.front();
        qRead2Take.pop();
        numCourseTaken++;
        courseOrdervectorPtr->push_back(courseCurrent);
        currentBranch = courseBranch[courseCurrent];
        for(auto itr = currentBranch.begin(); itr != currentBranch.end(); itr++) {
            inDegree[*itr]--;
            if(inDegree[*itr] == 0) {
                qRead2Take.push(*itr);
            }
        }
    }
    printf("\n\nCan we finish all the %d courses? %s\n\n", numCourse, numCourseTaken == numCourseTaken ? "true" : "false");
}