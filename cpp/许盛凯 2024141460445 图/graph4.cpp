#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    queue<tuple<int, int, int>> q;//cur, mask,dist;
    vector<vector<bool>> visited(n, vector<bool>(1 << n));
    for(int i = 0; i< n ; i++){
        q.push({i, 1<<i, 0});
        visited[i][1<<i] = true;
    }   
    while(!q.empty()){
        auto [cur, mask, dist] = q.front();
        q.pop();
        if(mask == (1<< n) - 1 ) return dist;
        for(int x : graph[cur] ){
            int nextmask = mask | (1 << x);
            if(!visited[x][nextmask]){
                q.push({x,nextmask,dist+1});
                visited[x][nextmask] = true;
            }
        }
    }
    return 0;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        graph[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }

    Solution sol;
    cout << sol.shortestPathLength(graph) << '\n';
    return 0;
}
