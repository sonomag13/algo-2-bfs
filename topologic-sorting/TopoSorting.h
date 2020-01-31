//
// Created by lu.gao on 12/21/19.
//

#ifndef TOPOLOGIC_SORTING_TOPOSORTING_H
#define TOPOLOGIC_SORTING_TOPOSORTING_H

using namespace std;

namespace TPSorting{

    template <typename  T>
    void arr2vec(T* arr1, T* arr2, int n, vector<pair<T, T>>* vptr) {
        for(int i = 0; i < n; i++) {
            vptr->push_back(make_pair(arr1[i], arr2[i]));
        }
    }

    template <typename T>
    void print_vec(vector<pair<T, T>>* vptr) {
        int cnt = 0;
        pair<T, T> p = vptr->at(0);
        for(auto itr = vptr->begin(); itr < vptr->end(); itr++) {
            cout << "\ncounter = " << cnt << endl;
            cnt++;
            cout << "\tfirst = " << (*itr).first << " and second = " << (*itr).second << endl;
        }
    }

    template <typename T>
    void vec2umap(vector<pair<T, T>>* vptr, unordered_map<T, T>* umapptr) {
        for(auto itr = vptr->begin(); itr < vptr->end(); itr++) {
            umapptr->insert(*itr);
        }
    }

}

#endif //TOPOLOGIC_SORTING_TOPOSORTING_H
