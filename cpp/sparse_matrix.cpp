#include <iostream>
#include <iomanip>
using namespace std;

// ==================== 三元组顺序表实现 ====================
#define MAXSIZE 100

// 三元组结构
struct Triple {
    int row;    // 行下标
    int col;    // 列下标
    int value;  // 元素值
};

// 三元组顺序表（数组实现）
class TripleMatrix {
public:
    Triple data[MAXSIZE];  // 非零元素数组
    int rows;              // 矩阵行数
    int cols;              // 矩阵列数
    int nums;              // 非零元素个数

    TripleMatrix() : rows(0), cols(0), nums(0) {}

    // 创建稀疏矩阵
    void createMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        nums = 0;
        
        cout << "请输入 " << n << " 个非零元素（行 列 值）：\n";
        for (int i = 0; i < n; i++) {
            int row, col, value;
            cin >> row >> col >> value;
            if (value != 0) {
                data[nums].row = row;
                data[nums].col = col;
                data[nums].value = value;
                nums++;
            }
        }
    }

    // 打印三元组表
    void printTriple() {
        cout << "\n三元组顺序表：\n";
        cout << "行\t列\t值\n";
        for (int i = 0; i < nums; i++) {
            cout << data[i].row << "\t" 
                 << data[i].col << "\t" 
                 << data[i].value << "\n";
        }
    }

    // 打印完整矩阵
    void printMatrix() {
        cout << "\n完整矩阵表示：\n";
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (idx < nums && data[idx].row == i && data[idx].col == j) {
                    cout << setw(4) << data[idx].value;
                    idx++;
                } else {
                    cout << setw(4) << 0;
                }
            }
            cout << "\n";
        }
    }

    // 快速转置算法
    TripleMatrix fastTranspose() {
        TripleMatrix T;
        T.rows = cols;
        T.cols = rows;
        T.nums = nums;

        if (nums == 0) return T;

        // num[col]：第col列非零元素个数
        int num[MAXSIZE] = {0};
        // cpot[col]：第col列第一个非零元素在转置矩阵中的位置
        int cpot[MAXSIZE] = {0};

        // 统计每列非零元素个数
        for (int i = 0; i < nums; i++) {
            num[data[i].col]++;
        }

        // 计算每列第一个非零元素在转置矩阵中的位置
        cpot[0] = 0;
        for (int col = 1; col < cols; col++) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }

        // 转置
        for (int i = 0; i < nums; i++) {
            int col = data[i].col;
            int pos = cpot[col];
            T.data[pos].row = data[i].col;
            T.data[pos].col = data[i].row;
            T.data[pos].value = data[i].value;
            cpot[col]++;  // 该列下一个元素的位置
        }

        return T;
    }

    // 普通转置算法（用于对比）
    TripleMatrix simpleTranspose() {
        TripleMatrix T;
        T.rows = cols;
        T.cols = rows;
        T.nums = nums;

        if (nums == 0) return T;

        int idx = 0;
        // 按列序遍历原矩阵
        for (int col = 0; col < cols; col++) {
            for (int i = 0; i < nums; i++) {
                if (data[i].col == col) {
                    T.data[idx].row = data[i].col;
                    T.data[idx].col = data[i].row;
                    T.data[idx].value = data[i].value;
                    idx++;
                }
            }
        }

        return T;
    }
};

// ==================== 十字链表实现 ====================

// 十字链表节点
struct CrossNode {
    int row, col;           // 行号、列号
    int value;              // 元素值
    CrossNode *right, *down; // 右指针、下指针

    CrossNode(int r = 0, int c = 0, int v = 0) 
        : row(r), col(c), value(v), right(nullptr), down(nullptr) {}
};

// 十字链表稀疏矩阵
class CrossListMatrix {
public:
    CrossNode **rowHead;  // 行头指针数组
    CrossNode **colHead;  // 列头指针数组
    int rows, cols, nums; // 行数、列数、非零元素个数

    CrossListMatrix(int r = 0, int c = 0) : rows(r), cols(c), nums(0) {
        if (r > 0 && c > 0) {
            rowHead = new CrossNode*[r];
            colHead = new CrossNode*[c];
            for (int i = 0; i < r; i++) rowHead[i] = nullptr;
            for (int i = 0; i < c; i++) colHead[i] = nullptr;
        } else {
            rowHead = colHead = nullptr;
        }
    }

    ~CrossListMatrix() {
        // 释放所有节点
        for (int i = 0; i < rows; i++) {
            CrossNode *p = rowHead[i];
            while (p) {
                CrossNode *temp = p;
                p = p->right;
                delete temp;
            }
        }
        delete[] rowHead;
        delete[] colHead;
    }

    // 插入元素
    void insertElement(int r, int c, int v) {
        if (v == 0) return;  // 零元素不插入

        CrossNode *newNode = new CrossNode(r, c, v);
        
        // 插入到行链表
        if (rowHead[r] == nullptr || rowHead[r]->col > c) {
            newNode->right = rowHead[r];
            rowHead[r] = newNode;
        } else {
            CrossNode *p = rowHead[r];
            while (p->right && p->right->col < c) {
                p = p->right;
            }
            newNode->right = p->right;
            p->right = newNode;
        }

        // 插入到列链表
        if (colHead[c] == nullptr || colHead[c]->row > r) {
            newNode->down = colHead[c];
            colHead[c] = newNode;
        } else {
            CrossNode *p = colHead[c];
            while (p->down && p->down->row < r) {
                p = p->down;
            }
            newNode->down = p->down;
            p->down = newNode;
        }

        nums++;
    }

    // 创建稀疏矩阵
    void createMatrix(int n) {
        cout << "请输入 " << n << " 个非零元素（行 列 值）：\n";
        for (int i = 0; i < n; i++) {
            int row, col, value;
            cin >> row >> col >> value;
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                insertElement(row, col, value);
            }
        }
    }

    // 打印十字链表结构
    void printCrossList() {
        cout << "\n十字链表结构：\n";
        cout << "按行遍历：\n";
        for (int i = 0; i < rows; i++) {
            cout << "第 " << i << " 行: ";
            CrossNode *p = rowHead[i];
            while (p) {
                cout << "(" << p->row << "," << p->col << "," << p->value << ") ";
                p = p->right;
            }
            cout << "\n";
        }

        cout << "\n按列遍历：\n";
        for (int j = 0; j < cols; j++) {
            cout << "第 " << j << " 列: ";
            CrossNode *p = colHead[j];
            while (p) {
                cout << "(" << p->row << "," << p->col << "," << p->value << ") ";
                p = p->down;
            }
            cout << "\n";
        }
    }

    // 打印完整矩阵
    void printMatrix() {
        cout << "\n完整矩阵表示：\n";
        for (int i = 0; i < rows; i++) {
            CrossNode *p = rowHead[i];
            for (int j = 0; j < cols; j++) {
                if (p && p->col == j) {
                    cout << setw(4) << p->value;
                    p = p->right;
                } else {
                    cout << setw(4) << 0;
                }
            }
            cout << "\n";
        }
    }

    // 获取元素值
    int getValue(int r, int c) {
        CrossNode *p = rowHead[r];
        while (p && p->col < c) {
            p = p->right;
        }
        if (p && p->col == c) {
            return p->value;
        }
        return 0;
    }
};

// ==================== 测试函数 ====================

void testTripleMatrix() {
    cout << "========================================\n";
    cout << "测试三元组顺序表（数组实现）\n";
    cout << "========================================\n";
    
    TripleMatrix M;
    cout << "创建一个 5x6 的稀疏矩阵，包含 8 个非零元素\n";
    
    // 示例输入：
    // 0 1 2
    // 0 4 3
    // 1 2 4
    // 2 0 5
    // 2 3 6
    // 3 1 7
    // 3 5 8
    // 4 3 9
    
    M.createMatrix(5, 6, 8);
    
    M.printTriple();
    M.printMatrix();
    
    cout << "\n执行快速转置：\n";
    TripleMatrix T = M.fastTranspose();
    T.printTriple();
    T.printMatrix();
    
    cout << "\n执行普通转置（对比）：\n";
    TripleMatrix T2 = M.simpleTranspose();
    T2.printTriple();
}

void testCrossListMatrix() {
    cout << "\n========================================\n";
    cout << "测试十字链表法（广义表实现）\n";
    cout << "========================================\n";
    
    CrossListMatrix M(5, 6);
    cout << "创建一个 5x6 的稀疏矩阵，包含 8 个非零元素\n";
    
    // 示例输入：同上
    M.createMatrix(8);
    
    M.printCrossList();
    M.printMatrix();
    
    cout << "\n访问元素 M[2][3] = " << M.getValue(2, 3) << "\n";
    cout << "访问元素 M[0][0] = " << M.getValue(0, 0) << "\n";
}

int main() {
    cout << "稀疏矩阵的表示与转置\n\n";
    
    // 测试三元组顺序表
    testTripleMatrix();
    
    // 测试十字链表
    testCrossListMatrix();
    
    return 0;
}
