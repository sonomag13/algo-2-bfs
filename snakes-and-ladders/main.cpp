#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    
    int start = 1; 
    int end = 100; 
    
    vector<bool> visited(end + 1, false); 
    visited[0] = true; 
    
    vector<int> clumbUp(end + 1, -1); 
    for (auto & ladder : ladders) {
        clumbUp[ladder[0]] = ladder[1]; 
    }
    
    vector<int> clumbDown(end + 1, -1); 
    for (auto & snake : snakes) {
        clumbDown[snake[0]] = snake[1]; 
    }
    
    queue<pair<int, int>> que; 
    que.push(make_pair(start, 0));
    visited[start] = true; 
    
    while (!que.empty()) {    
        auto ele = que.front();
        que.pop();
        int cur = ele.first; 
        int steps = ele.second;  
        
        if (cur == end) {
            return steps; 
        }
        
        for (int i = 1; i <= 6; ++i) {
            int next = cur + i; 
            if (visited[next]) {
                continue; 
            }
            visited[next] = true; 
            
            if (clumbUp[next] != -1) {
                int next2 = clumbUp[next];
                if (visited[next2]) {
                    continue; 
                }
                next = next2;  
            }
                
            if (clumbDown[next] != -1) {
                int next2 = clumbDown[next];
                if (visited[next2]) {
                    continue; 
                }
                next = next2; 
            }    
            
            que.push(make_pair(next, steps + 1));
            visited[next] = true; 
            continue; 
        }
    }

    return -1; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

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
