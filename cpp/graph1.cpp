#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void dfs(const vector<list<int>>& graph, int x, int n){
    if(x==n){
        result.push_back(path);
        return ;
    }
    for(int next: graph[x]){
        path.push_back(next);
        dfs(graph, next, n);
        path.pop_back();
    }
}
int main(){
    int n , m , s, t;
    vector<list<int>> graph(n+1);
    cin>> n>>m;
    while(m --){
        cin>> s >>t;
        graph[s].push_back(t);
    }
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