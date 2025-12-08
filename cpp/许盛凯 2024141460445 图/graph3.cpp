#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> result;
vector<int> path;
vector<bool> visited;

void dfs(const vector<vector<int>>& graph ,int cur, int final){
    if(cur == final){
        result.push_back(path);
        return ;
    }
    for(int to : graph[cur]){
        if(!visited[to]){
            visited[to] = true;
            path.push_back(to);
            dfs(graph, to, final);
            path.pop_back();
            visited[to] = false;
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

   
    vector<vector<int>> graph(n + 1);

    int s, t;
    while (m--) {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    path.clear();
    path.push_back(1);

    visited.assign(n + 1, false);
    visited[1] = true;  
    
    dfs(graph, 1, n);
    
    if (result.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    for (const auto& r : result) {
        for (int i = 0; i < (int)r.size(); ++i) {
            cout << r[i];
            if (i + 1 < (int)r.size()) cout << ' ';
        }
        cout << '\n';
    }

    return 0;

}

