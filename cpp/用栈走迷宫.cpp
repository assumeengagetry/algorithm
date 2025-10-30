#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 定义位置结构体
struct Position {
    int x, y;
    Position(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

class MazeSolver {
private:
    vector<vector<int>> maze;  // 迷宫地图
    vector<vector<bool>> visited;  // 访问标记
    int rows, cols;
    
    // 四个方向：右、下、左、上
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    // 检查位置是否合法
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols 
               && maze[x][y] == 0 && !visited[x][y];
    }
    
public:
    MazeSolver(vector<vector<int>>& m) : maze(m) {
        rows = maze.size();
        cols = maze[0].size();
        visited.resize(rows, vector<bool>(cols, false));
    }
    
    // 使用栈求解迷宫
    bool solve(Position start, Position end) {
        stack<Position> path;
        path.push(start);
        visited[start.x][start.y] = true;
        
        cout << "开始搜索路径...\n";
        
        while (!path.empty()) {
            Position current = path.top();
            
            // 到达终点
            if (current.x == end.x && current.y == end.y) {
                cout << "\n找到路径！\n";
                printPath(path);
                return true;
            }
            
            // 尝试四个方向
            bool found = false;
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                
                if (isValid(nx, ny)) {
                    path.push(Position(nx, ny));
                    visited[nx][ny] = true;
                    found = true;
                    break;
                }
            }
            
            // 如果四个方向都走不通，回溯
            if (!found) {
                path.pop();
            }
        }
        
        cout << "没有找到路径！\n";
        return false;
    }
    
    // 打印路径
    void printPath(stack<Position> path) {
        vector<Position> result;
        while (!path.empty()) {
            result.push_back(path.top());
            path.pop();
        }
        
        cout << "路径长度: " << result.size() << endl;
        cout << "路径坐标: ";
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << "(" << result[i].x << "," << result[i].y << ")";
            if (i > 0) cout << " -> ";
        }
        cout << endl;
        
        // 在地图上显示路径
        printMazeWithPath(result);
    }
    
    // 打印带路径的迷宫
    void printMazeWithPath(vector<Position>& path) {
        vector<vector<char>> display(rows, vector<char>(cols));
        
        // 初始化显示地图
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                display[i][j] = (maze[i][j] == 1) ? '#' : ' ';
            }
        }
        
        // 标记路径
        for (auto& pos : path) {
            display[pos.x][pos.y] = '*';
        }
        
        // 标记起点和终点
        display[path[0].x][path[0].y] = 'S';
        display[path.back().x][path.back().y] = 'E';
        
        // 打印
        cout << "\n迷宫路径图 (S=起点, E=终点, *=路径, #=墙):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << display[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // 打印原始迷宫
    void printMaze() {
        cout << "迷宫地图 (0=通路, 1=墙):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 定义迷宫 (0表示通路，1表示墙)
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    MazeSolver solver(maze);
    solver.printMaze();
    
    Position start(0, 0);  // 起点
    Position endPos(4, 4);    // 终点
    
    cout << "\n起点: (" << start.x << "," << start.y << ")\n";
    cout << "终点: (" << endPos.x << "," << endPos.y << ")\n\n";
    
    solver.solve(start, endPos);
    
    return 0;
}