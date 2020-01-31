#include <iostream>
#include <vector>
#include <unordered_map>
#include "TopoSorting.h"

using namespace std;

int main() {
    /*
    char arr1[] = {'A', 'B', 'B', 'C', 'E'};
    char arr2[] = {'B', 'C', 'D', 'D', 'F'};
    auto vptr = new vector<pair<char, char>>;
    */
    int arr1[] = {0, 1, 1, 2, 3};
    int arr2[] = {1, 2, 3, 4, 4};
    int N = sizeof(arr1) / sizeof(arr1[0]);

    auto vptr = new vector<pair<int, int>>;
    auto umapptr = new unordered_map<int, int>;

    TPSorting::arr2vec(arr1, arr2, N, vptr);
    TPSorting::print_vec(vptr);
    TPSorting::vec2umap(vptr, umapptr);

    delete vptr, umapptr;

    return 0;
}
