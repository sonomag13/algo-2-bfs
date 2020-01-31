//
// Created by lu.gao on 12/14/19.
//

#ifndef NUMBER_OF_ISLANDS_STRING2VECTOR_H
#define NUMBER_OF_ISLANDS_STRING2VECTOR_H

#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <boost/algorithm/string.hpp>

namespace VecOpt {

    using namespace std;

    vector<bool> cleanToken(const string &strIn);

    vector<vector<bool>> generateRandomGrid(const int N) {
        vector<vector<bool>> boolVec;
        vector<bool> row;
        int rand_val;
        srand(time(NULL));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                rand_val = rand() % 2;
                row.push_back(rand_val);
            }
            boolVec.push_back(row);
            row.clear();
        }
        return boolVec;
    }

    void generateRandomGrid_ptr(vector<vector<bool>> *ptr, vector<vector<bool>> &vectorIn) {
        // vector<vector<bool>> *Gridptr = new vector<vector<bool>>;
        vector<bool> row;
        vector<vector<bool>>::iterator itrRow;
        vector<bool>::iterator itrCol;
        for(itrRow = vectorIn.begin(); itrRow < vectorIn.end(); itrRow++) {
            for(itrCol = itrRow->begin(); itrCol < itrRow->end(); itrCol++) {
                row.push_back(*itrCol);
            }
            ptr->push_back(row);
            row.clear();
        }
    }

    void printVec(vector<vector<bool>> &grid) {
        vector<vector<bool>>::iterator itrRow;
        vector<bool>::iterator itrCol;
        cout << "\ntransverse with iterator" << endl;
        for(itrRow = grid.begin(); itrRow != grid.end(); itrRow++) {
            for(itrCol = itrRow->begin(); itrCol != itrRow->end(); itrCol++) {
                (itrCol + 1 == itrRow->end()) ? cout << *itrCol : cout << *itrCol << " -> ";
            }
            cout << endl;
        }
    }

    void printVec_ptr(vector<vector<bool>> *ptr) {
        vector<vector<bool>>::iterator itrRow;
        vector<bool>::iterator itrCol;
        cout << "\npassing by pointer; iterate with iterator" << endl;
        for(itrRow = ptr->begin(); itrRow < ptr->end(); itrRow++) {
            for(itrCol = itrRow->begin(); itrCol < itrRow->end(); itrCol++) {
                (itrCol + 1 == itrRow->end()) ? cout << *itrCol : cout << *itrCol << " -> ";
            }
            cout << endl;
        }
    }

    void convertStr2Vec(vector<vector<bool>> *GridPtr, string &strIn, const string dilm) {
        size_t pos = 0;
        string token;
        while ((pos = strIn.find(dilm)) != string::npos) {
            token = strIn.substr(0, pos);
            GridPtr->push_back(cleanToken(token));
            strIn.erase(0, pos + dilm.length());
        }
        GridPtr->push_back(cleanToken(strIn));
    }

    vector<bool> cleanToken(const string &strIn) {
        vector<bool> vec;
        for(int i = 0; i < strIn.length(); i++) {
            if(isdigit(strIn[i])) {
                (strIn[i] == '1') ? vec.push_back(true) : vec.push_back(false);
            }
        }
        return vec;
    }

}

#endif //NUMBER_OF_ISLANDS_STRING2VECTOR_H
