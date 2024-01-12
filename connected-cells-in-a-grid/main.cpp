#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

vector<int> dx = {+1, +1, 0, -1, -1, -1, 0, +1};
vector<int> dy = {0, -1, -1, -1, 0, +1, +1, +1};
const int numDelta = dx.size(); 

bool inBoundary(int numRow, int numCol, int rowIdx, int colIdx) {
    
    bool cond1 = 0 <= rowIdx && rowIdx < numRow; 
    bool cond2 = 0 <= colIdx && colIdx < numCol; 
    
    if (cond1 && cond2) {
        return true; 
    }
    
    return false; 
}

int bfs(const vector<vector<int>> & matrix, vector<vector<bool>> & visited, int numRow, int numCol, int rowIdx, int colIdx) {
    
    int area = 0; 
    
    queue<pair<int, int>> queIdx; 
    queIdx.push(make_pair(rowIdx, colIdx));
    visited[rowIdx][colIdx] = true;  
    ++area; 
    
    while (!queIdx.empty()) {
        
        pair<int, int> idx = queIdx.front();
        queIdx.pop();
        int rowIdx1 = idx.first; 
        int colIdx1 = idx.second; 
        
        for (int i = 0; i < numDelta; ++i) {
            int rowIdx2 = rowIdx1 + dy[i];
            int colIdx2 = colIdx1 + dx[i];
            
            if (!inBoundary(numRow, numCol, rowIdx2, colIdx2) || visited[rowIdx2][colIdx2] || matrix[rowIdx2][colIdx2] == 0) {
                continue; 
            }
            
            queIdx.push(make_pair(rowIdx2, colIdx2));
            visited[rowIdx2][colIdx2] = true;  
            ++area; 
        }
        
    }
    
    return area; 
}

int connectedCell(vector<vector<int>> matrix) {
    
    int largestArea{0}; 
    int numRow = matrix.size(); 
    int numCol = matrix[0].size(); 
    
    vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
    
    for (int rowIdx = 0; rowIdx < numRow; ++rowIdx) {
        for (int colIdx = 0; colIdx < numCol; ++colIdx) {
            
            if (!visited[rowIdx][colIdx] && matrix[rowIdx][colIdx] == 1) {
                int area = bfs(matrix, visited, numRow, numCol, rowIdx, colIdx); 
                largestArea = max(largestArea, area); 
            }
        }
    } 
    
    return largestArea; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
