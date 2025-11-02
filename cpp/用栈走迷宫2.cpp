#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> Point;

bool solveMaze(vector<vector<int>>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();
    
    stack<Point> path;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    path.push(start);
    visited[start.first][start.second] = true;
    
    while (!path.empty()) {
        Point curr = path.top();
        
        // 到达终点
        if (curr == end) {
            // 打印路径
            cout << "找到路径: ";
            stack<Point> temp;
            while (!path.empty()) {
                temp.push(path.top());
                path.pop();
            }
            while (!temp.empty()) {
                cout << "(" << temp.top().first << "," << temp.top().second << ") ";
                temp.pop();
            }
            cout << endl;
            return true;
        }
        
        // 尝试四个方向
        bool found = false;
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                
                path.push({nx, ny});
                visited[nx][ny] = true;
                found = true;
                break;
            }
        }
        
        // 回溯
        if (!found) {
            path.pop();
        }
    }
    
    cout << "无解！" << endl;
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    solveMaze(maze, {0, 0}, {4, 4});
    
    return 0;
}