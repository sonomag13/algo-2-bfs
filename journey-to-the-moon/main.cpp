#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
 
void printNeighbors(const unordered_map<int, unordered_set<int>> & m) {
    
    for (auto & ele : m) {
        cout << ele.first << ": ";
        
        for (auto val : ele.second) {
            cout << val << ' ';
        }
        cout << '\n'; 
    }
}

void printGroup(const unordered_set<int> & group) {
    
    for (auto ele : group) {
        cout << ele << ' ';
    }
    
    cout << '\n';
}

void buildMap(int a1, int a2, unordered_map<int, unordered_set<int>> & mapNeighbors) {
    
    if (mapNeighbors.find(a1) == mapNeighbors.end()) {
        mapNeighbors.insert(make_pair(a1, unordered_set<int>{a2}));
    }
    else {
        mapNeighbors[a1].insert(a2); 
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    unordered_map<int, unordered_set<int>> mapNeighbors; 
    
    for (auto astro : astronaut) {
        int a1 = astro[0];
        int a2 = astro[1]; 
        buildMap(a1, a2, mapNeighbors);
        buildMap(a2, a1, mapNeighbors);
    }
    
    vector<bool> visited(n, false);
    vector<int> groupSizes; 
    
    for (int i = 0; i < n; ++i) {
        
        if (visited[i]) {
            continue; 
        }
        
        unordered_set<int> group = {i}; 
        queue<int> queNeighbor; 
        queNeighbor.push(i);
        
        while (!queNeighbor.empty()) {
            int val = queNeighbor.front();
            queNeighbor.pop();
            visited[val] = true; 
            
            for (auto neighbor : mapNeighbors[val]) {
                if (visited[neighbor]) {
                    continue; 
                }
                queNeighbor.push(neighbor);
                group.insert(neighbor);
            }
        } 
        
        groupSizes.push_back(group.size()); 
    }
    
    int num = 0; 
    int numGroup = groupSizes.size(); 
    
    for (int i = 0; i < numGroup; ++i) {
        for (int j = i + 1; j < numGroup; ++j) {
            num += groupSizes[i] * groupSizes[j];
        }
    }
    
    return num; 
}