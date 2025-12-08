#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Collects every directed path discovered from start node 1 to sink node n.
vector<vector<int>> result;
// Records the current DFS traversal path.
vector<int> path;

// Depth-first search on adjacency lists to enumerate all paths from x to n.
void dfs(const vector<list<int>>& graph, int x, int n){
    if(x==n){
        // Reached the destination; store a copy of the current path.
        result.push_back(path);
        return ;
    }
    for(int next: graph[x]){
        // Explore next neighbor and backtrack afterward.
        path.push_back(next);
        dfs(graph, next, n);
        path.pop_back();
    }
}

int main(){
    int n , m , s, t;
    cin>> n>>m;
    vector<list<int>> graph(n+1);
    // Build adjacency lists for directed edges.
    while(m --){
        cin>> s >>t;
        graph[s].push_back(t);
    }
    // Start DFS from node 1 and gather all reachable paths ending at n.
    path.push_back(1);
    dfs(graph, 1, n);
    if(result.size() == 0){
        cout<< -1 << endl;
    }
    for(const vector<int> &r: result){
        for(int j =0 ; j< r.size() ; j++){
            cout<<r[j]<<" ";
        }
    }


}
