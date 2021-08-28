// LintCode 615 and 616

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>

#include "Solution.h"

using namespace std;

int main() {
    int numCourse = 5;
    int toTake[] = {1, 2, 3, 4};
    int preReq[] = {0, 0, 1, 3};
    vector<pair<int, int>> vectPrereq;
    vector<int>* courseOrdervectorPtr = new vector<int>;    
    for(int i = 0; i < sizeof(toTake)/sizeof(int); i++) {
        vectPrereq.push_back(make_pair(toTake[i], preReq[i]));
    };
    
    bool flagFinish = Solution::canFinish(numCourse, vectPrereq);
    printf("\n\nCan we finish all the %d courses? %s\n\n", numCourse, flagFinish ? "true" : "false");

    return 0;
}