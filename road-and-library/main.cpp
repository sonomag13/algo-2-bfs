#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

void insertCity(int city1, int city2, unordered_map<int, unordered_set <int>> & mapCities) {
    
        if (mapCities.find(city1) != mapCities.end()) {
            mapCities[city1].insert(city2);
        }
        else {
            mapCities.insert(make_pair(city1, unordered_set<int>{city2}));
        }
}

void printCityGroup(const vector<unordered_set<int>> & groupCities) {
    
    for (int i = 0; i < groupCities.size(); ++i) {
        cout << "group " << i << '\n';
        for (auto city : groupCities[i]) {
            cout << city << ' ';
        }    
        cout << '\n';
    }
    
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    long costLib = static_cast<long>(c_lib);
    long costRoad = static_cast<long>(c_road); 
    
    unordered_map<int, unordered_set<int>> mapCities; 
    
    for (auto & neighbor : cities) {
        int city1 = neighbor[0];
        int city2 = neighbor[1];
        insertCity(city1, city2, mapCities);
        insertCity(city2, city1, mapCities);
    }
    
    vector<bool> visited(n + 1, false); 
    visited[0] = true;  // just in case
    
    vector<unordered_set<int>> groupCities; 
    
    for (int city = 1; city < n + 1; ++city) {
        
        if (visited[city]) {
            continue;  // the city has been visited
        }
        
        queue<int> queCity;
        queCity.push(city);
        unordered_set<int> group = {city}; 
        
        while (!queCity.empty()) {
            int city = queCity.front();
            visited[city] = true; 
            queCity.pop();
            
            for (auto neighbor : mapCities[city]) {
                
                if (visited[neighbor]) {
                    continue; 
                }
                queCity.push(neighbor);
                group.insert(neighbor);
            }
        }
        
        groupCities.push_back(group);
    }
    
    long totalCost{0}; 
    
    for (auto group : groupCities) {
        
        long numCity = static_cast<long>(group.size()); 
        
        long cost1 = costLib + (numCity - 1) * costRoad;
        long cost2 = costLib * numCity;
        
        totalCost += min(cost1, cost2); 
    }

    return totalCost; 
}