#include<iostream>
#include<stack>
#include<vector>

using namespace std;
typedef pair<int, int> Point;

bool SolvePuzzle(vector<vector<int>>& puzzle, Point start, Point end){
    int rows = puzzle.size();
    int cols = puzzle[0].size();
    stack<Point> path;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int dx[] = {-1, 0 , 1 , 0};
    int dy[] = {0, -1, 0, 1};
    path.push(start);
    visited[start.first][start.second]  = true;
    while(!path.empty())
    {
        Point cur = path.top();
        if(cur == end){
            cout<< "find the path";
            stack<Point> temp;
            while(!path.empty()){
                temp.push(path.top());
                path.pop();
            }
            while(!temp.empty()){
                cout<< "(" << temp.top().first << "," << temp.top().second << ")";
                temp.pop(); 
            }
            cout << endl;
            return true;
        }
    bool found = false;
    for(int i = 0;i < 4; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx >= 0 && ny >= 0&& nx < rows && ny < cols && puzzle[nx][ny] == 0&& !visited[nx][ny] ){
            path.push({nx,ny});
            visited[nx][ny] = true;
            found = true ; 
            break;

            
        }
        
    }
    if(!found){
            path.pop();
        }    
    }
    cout  << "I can't find a path" <<endl;
    return false;

}


int main(){
    vector<vector<int>> puzzle = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    SolvePuzzle(puzzle, {0,0} , {4,4});
    return 0;
}