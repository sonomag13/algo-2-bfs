#include <iostream>
#include <vector>
#include "Solution.h"
#include "String2Vector.h"

using namespace std;

int main() {

    string strGrid = "[[1,1,0,0,0],[0,1,0,0,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,0,0,1]]";
    int N = 5;

    vector<vector<bool>> randomGrid;
    vector<vector<bool>> *GridPtr = new vector<vector<bool>>;
    vector<vector<bool>> *randomGridPtr = new vector<vector<bool>>;
    Solution Island_num;
    int Nisland = 0;

    /*
    // directly passing the vector
    randomGrid = VecOpt::generateRandomGrid(N);
    VecOpt::printVec(randomGrid);
    // generate vector by pointer
    VecOpt::generateRandomGrid_ptr(randomGridPtr, randomGrid);
    VecOpt::printVec_ptr(randomGridPtr);
    */

    // parse the string and convert it into vector
    VecOpt::convertStr2Vec(GridPtr, strGrid, "],[");
    VecOpt::printVec_ptr(GridPtr);
    // search for islands
    Nisland = Island_num.numIslands(*GridPtr);
    cout << "\n# of islands = " << Nisland << endl;

    delete randomGridPtr, GridPtr;

    return 0;

}
