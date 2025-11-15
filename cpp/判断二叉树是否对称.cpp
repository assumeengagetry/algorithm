#include <iostream>
using namespace std;

/*======================
 * 部分一：十字链表表示稀疏矩阵
 *======================*/

struct OLNode {          // Orthogonal List Node
    int i, j;            // 行下标、列下标（从 1 开始）
    int v;               // 元素值
    OLNode *right;       // 同一行的下一个非零元素
    OLNode *down;        // 同一列的下一个非零元素
};

struct CrossList {
    int mu, nu;          // 行数、列数
    int tu;              // 非零元个数
    OLNode **rhead;      // 行头指针数组，下标 1..mu
    OLNode **chead;      // 列头指针数组，下标 1..nu

    CrossList(int m, int n) {
        mu = m;
        nu = n;
        tu = 0;
        rhead = new OLNode*[mu + 1];
        chead = new OLNode*[nu + 1];
        for (int i = 1; i <= mu; ++i) rhead[i] = nullptr;
        for (int j = 1; j <= nu; ++j) chead[j] = nullptr;
    }

    // 在 (i, j) 位置插入一个非零元素 v（假设原来此位置为 0）
    void insert(int i, int j, int v) {
        if (v == 0) return;
        OLNode *p = new OLNode;
        p->i = i;
        p->j = j;
        p->v = v;
        p->right = nullptr;
        p->down  = nullptr;

        // 按列号有序插入到第 i 行的链表中
        if (!rhead[i] || rhead[i]->j > j) {
            p->right = rhead[i];
            rhead[i] = p;
        } else {
            OLNode *pre = rhead[i];
            while (pre->right && pre->right->j < j)
                pre = pre->right;
            p->right = pre->right;
            pre->right = p;
        }

        // 按行号有序插入到第 j 列的链表中
        if (!chead[j] || chead[j]->i > i) {
            p->down = chead[j];
            chead[j] = p;
        } else {
            OLNode *pre = chead[j];
            while (pre->down && pre->down->i < i)
                pre = pre->down;
            p->down = pre->down;
            pre->down = p;
        }

        ++tu;
    }

    // 输出为普通矩阵形式
    void printAsMatrix() {
        for (int i = 1; i <= mu; ++i) {
            OLNode *p = rhead[i];
            int currentCol = 1;
            while (currentCol <= nu) {
                if (p && p->j == currentCol) {
                    cout << p->v << " ";
                    p = p->right;
                } else {
                    cout << 0 << " ";
                }
                ++currentCol;
            }
            cout << "\n";
        }
    }

    ~CrossList() {
        // 释放所有结点
        for (int i = 1; i <= mu; ++i) {
            OLNode *p = rhead[i];
            while (p) {
                OLNode *q = p->right;
                delete p;
                p = q;
            }
        }
        delete[] rhead;
        delete[] chead;
    }
};

/*======================
 * 部分二：三元组顺序表 + 稀疏矩阵转置
 *======================*/

const int MAXSIZE = 100; // 最大非零元个数

struct Triple {
    int i, j;   // 行、列
    int v;      // 值
};

struct TSMatrix {
    Triple data[MAXSIZE + 1]; // data[1..tu] 存放非零元（1 号位置开始）
    int mu, nu;               // 行数、列数
    int tu;                   // 非零元个数
};

// 简单构造一个矩阵的三元组表示
void createMatrixExample(TSMatrix &M) {
    // 示例：3x4 矩阵
    // 0 0 5 0
    // 8 0 0 0
    // 0 0 3 6
    M.mu = 3;
    M.nu = 4;
    M.tu = 4;

    M.data[1] = {1, 3, 5};
    M.data[2] = {2, 1, 8};
    M.data[3] = {3, 3, 3};
    M.data[4] = {3, 4, 6};
}

// 快速转置算法：从 A 得到 B = A^T
void fastTranspose(const TSMatrix &A, TSMatrix &B) {
    B.mu = A.nu;
    B.nu = A.mu;
    B.tu = A.tu;

    if (A.tu == 0) return;

    int *num = new int[A.nu + 1];   // num[col] 记录 A 中第 col 列非零元个数
    int *cpot = new int[A.nu + 1];  // cpot[col] 记录该列第一个非零元在 B.data 中的起始位置

    for (int col = 1; col <= A.nu; ++col)
        num[col] = 0;

    for (int k = 1; k <= A.tu; ++k)
        ++num[A.data[k].j];

    cpot[1] = 1;
    for (int col = 2; col <= A.nu; ++col)
        cpot[col] = cpot[col - 1] + num[col - 1];

    for (int p = 1; p <= A.tu; ++p) {
        int col = A.data[p].j;
        int q = cpot[col]++;        // 放置位置
        B.data[q].i = A.data[p].j;  // 行列互换
        B.data[q].j = A.data[p].i;
        B.data[q].v = A.data[p].v;
    }

    delete[] num;
    delete[] cpot;
}

// 打印三元组对应的完整矩阵
void printTSMatrixAsMatrix(const TSMatrix &M) {
    int k = 1;
    for (int i = 1; i <= M.mu; ++i) {
        for (int j = 1; j <= M.nu; ++j) {
            if (k <= M.tu && M.data[k].i == i && M.data[k].j == j) {
                cout << M.data[k].v << " ";
                ++k;
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    cout << "===== 部分一：十字链表表示稀疏矩阵 =====\n";
    CrossList cl(3, 4);
    cl.insert(1, 3, 5);
    cl.insert(2, 1, 8);
    cl.insert(3, 3, 3);
    cl.insert(3, 4, 6);
    cl.printAsMatrix();

    cout << "\n===== 部分二：三元组顺序表转置 =====\n";
    TSMatrix A, B;
    createMatrixExample(A);
    cout << "原矩阵 A:\n";
    printTSMatrixAsMatrix(A);

    fastTranspose(A, B);
    cout << "\n转置矩阵 B = A^T:\n";
    printTSMatrixAsMatrix(B);

    return 0;
}
