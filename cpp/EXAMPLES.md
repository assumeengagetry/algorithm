# 使用示例和扩展功能

## 快速开始

### 1. 编译程序
```bash
g++ -o sparse_matrix sparse_matrix.cpp -std=c++11
```

### 2. 运行程序
```bash
./sparse_matrix
```

### 3. 输入测试数据
按照提示输入非零元素：
```
0 1 2
0 4 3
1 2 4
2 0 5
2 3 6
3 1 7
3 5 8
4 3 9
```

---

## 代码使用示例

### 示例1：创建和打印三元组矩阵

```cpp
#include "sparse_matrix.cpp"

int main() {
    TripleMatrix M;
    
    // 创建 5x6 矩阵，8个非零元素
    M.rows = 5;
    M.cols = 6;
    M.nums = 8;
    
    // 手动添加元素
    M.data[0] = {0, 1, 2};
    M.data[1] = {0, 4, 3};
    M.data[2] = {1, 2, 4};
    M.data[3] = {2, 0, 5};
    M.data[4] = {2, 3, 6};
    M.data[5] = {3, 1, 7};
    M.data[6] = {3, 5, 8};
    M.data[7] = {4, 3, 9};
    
    // 打印
    M.printMatrix();
    
    return 0;
}
```

### 示例2：矩阵转置

```cpp
int main() {
    TripleMatrix M;
    M.createMatrix(5, 6, 8);
    
    // 快速转置
    TripleMatrix T1 = M.fastTranspose();
    cout << "快速转置结果：" << endl;
    T1.printMatrix();
    
    // 普通转置
    TripleMatrix T2 = M.simpleTranspose();
    cout << "普通转置结果：" << endl;
    T2.printMatrix();
    
    return 0;
}
```

### 示例3：使用十字链表

```cpp
int main() {
    CrossListMatrix M(5, 6);
    
    // 插入元素
    M.insertElement(0, 1, 2);
    M.insertElement(0, 4, 3);
    M.insertElement(1, 2, 4);
    M.insertElement(2, 0, 5);
    M.insertElement(2, 3, 6);
    
    // 访问元素
    cout << "M[2][3] = " << M.getValue(2, 3) << endl;
    
    // 打印矩阵
    M.printMatrix();
    
    return 0;
}
```

---

## 扩展功能实现

### 功能1：矩阵加法（三元组）

```cpp
TripleMatrix add(const TripleMatrix& A, const TripleMatrix& B) {
    TripleMatrix C;
    if (A.rows != B.rows || A.cols != B.cols) {
        cout << "矩阵维度不匹配！" << endl;
        return C;
    }
    
    C.rows = A.rows;
    C.cols = A.cols;
    C.nums = 0;
    
    int i = 0, j = 0;
    while (i < A.nums && j < B.nums) {
        int rowA = A.data[i].row;
        int colA = A.data[i].col;
        int rowB = B.data[j].row;
        int colB = B.data[j].col;
        
        if (rowA < rowB || (rowA == rowB && colA < colB)) {
            C.data[C.nums++] = A.data[i++];
        } else if (rowA > rowB || (rowA == rowB && colA > colB)) {
            C.data[C.nums++] = B.data[j++];
        } else {
            int sum = A.data[i].value + B.data[j].value;
            if (sum != 0) {
                C.data[C.nums].row = rowA;
                C.data[C.nums].col = colA;
                C.data[C.nums].value = sum;
                C.nums++;
            }
            i++; j++;
        }
    }
    
    while (i < A.nums) C.data[C.nums++] = A.data[i++];
    while (j < B.nums) C.data[C.nums++] = B.data[j++];
    
    return C;
}
```

### 功能2：矩阵乘法（十字链表）

```cpp
CrossListMatrix multiply(const CrossListMatrix& A, const CrossListMatrix& B) {
    if (A.cols != B.rows) {
        cout << "矩阵维度不匹配！" << endl;
        return CrossListMatrix();
    }
    
    CrossListMatrix C(A.rows, B.cols);
    
    // 遍历A的每一行
    for (int i = 0; i < A.rows; i++) {
        CrossNode* pA = A.rowHead[i];
        
        // 遍历B的每一列
        for (int j = 0; j < B.cols; j++) {
            int sum = 0;
            CrossNode* tempA = pA;
            
            // 计算 C[i][j]
            while (tempA) {
                int k = tempA->col;
                CrossNode* pB = B.colHead[j];
                
                while (pB && pB->row < k) {
                    pB = pB->down;
                }
                
                if (pB && pB->row == k) {
                    sum += tempA->value * pB->value;
                }
                
                tempA = tempA->right;
            }
            
            if (sum != 0) {
                C.insertElement(i, j, sum);
            }
        }
    }
    
    return C;
}
```

### 功能3：文件读写

```cpp
// 保存矩阵到文件
void TripleMatrix::saveToFile(const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "无法打开文件！" << endl;
        return;
    }
    
    fout << rows << " " << cols << " " << nums << endl;
    for (int i = 0; i < nums; i++) {
        fout << data[i].row << " " 
             << data[i].col << " " 
             << data[i].value << endl;
    }
    
    fout.close();
    cout << "矩阵已保存到 " << filename << endl;
}

// 从文件读取矩阵
void TripleMatrix::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "无法打开文件！" << endl;
        return;
    }
    
    fin >> rows >> cols >> nums;
    for (int i = 0; i < nums; i++) {
        fin >> data[i].row >> data[i].col >> data[i].value;
    }
    
    fin.close();
    cout << "已从 " << filename << " 加载矩阵" << endl;
}
```

### 功能4：性能测试

```cpp
#include <chrono>

void performanceTest() {
    const int SIZE = 1000;
    const int NON_ZERO = 1000;
    
    TripleMatrix M;
    M.rows = SIZE;
    M.cols = SIZE;
    M.nums = NON_ZERO;
    
    // 随机生成稀疏矩阵
    srand(time(0));
    for (int i = 0; i < NON_ZERO; i++) {
        M.data[i].row = rand() % SIZE;
        M.data[i].col = rand() % SIZE;
        M.data[i].value = rand() % 100 + 1;
    }
    
    // 测试快速转置
    auto start = chrono::high_resolution_clock::now();
    TripleMatrix T1 = M.fastTranspose();
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "快速转置耗时: " << duration1.count() << " 微秒" << endl;
    
    // 测试普通转置
    start = chrono::high_resolution_clock::now();
    TripleMatrix T2 = M.simpleTranspose();
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "普通转置耗时: " << duration2.count() << " 微秒" << endl;
    cout << "加速比: " << (double)duration2.count() / duration1.count() << "x" << endl;
}
```

---

## 实际应用案例

### 案例1：图像边缘检测

```cpp
// 使用稀疏矩阵表示图像梯度
void edgeDetection() {
    const int WIDTH = 512;
    const int HEIGHT = 512;
    
    CrossListMatrix gradient(HEIGHT, WIDTH);
    
    // 假设已经计算出梯度值
    // 只存储梯度较大的像素（边缘点）
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            int grad = calculateGradient(i, j);
            if (grad > THRESHOLD) {
                gradient.insertElement(i, j, grad);
            }
        }
    }
    
    cout << "边缘点数量: " << gradient.nums << endl;
    cout << "压缩率: " << (1.0 - (double)gradient.nums / (WIDTH * HEIGHT)) * 100 << "%" << endl;
}
```

### 案例2：社交网络分析

```cpp
// 使用十字链表表示社交网络图
void socialNetworkAnalysis() {
    const int USERS = 10000;
    CrossListMatrix network(USERS, USERS);
    
    // 添加好友关系（对称矩阵）
    // 如果用户i和用户j是好友，则 network[i][j] = network[j][i] = 1
    
    // 计算每个用户的好友数量
    for (int i = 0; i < USERS; i++) {
        int friendCount = 0;
        CrossNode* p = network.rowHead[i];
        while (p) {
            friendCount++;
            p = p->right;
        }
        cout << "用户 " << i << " 有 " << friendCount << " 个好友" << endl;
    }
}
```

### 案例3：推荐系统

```cpp
// 用户-商品评分矩阵
void recommendationSystem() {
    const int USERS = 1000;
    const int ITEMS = 5000;
    
    TripleMatrix ratings;
    ratings.rows = USERS;
    ratings.cols = ITEMS;
    
    // 加载评分数据（大部分用户只评分了少数商品）
    // 计算物品相似度矩阵
    
    TripleMatrix similarity;
    // 使用转置矩阵快速计算列之间的相似度
    TripleMatrix ratingsT = ratings.fastTranspose();
    
    // 基于相似度进行推荐
    // ...
}
```

---

## 调试技巧

### 1. 检查三元组顺序
```cpp
void checkTripleOrder(const TripleMatrix& M) {
    for (int i = 0; i < M.nums - 1; i++) {
        if (M.data[i].row > M.data[i+1].row ||
            (M.data[i].row == M.data[i+1].row && 
             M.data[i].col >= M.data[i+1].col)) {
            cout << "警告：三元组顺序错误在索引 " << i << endl;
        }
    }
}
```

### 2. 检查十字链表完整性
```cpp
void checkCrossListIntegrity(const CrossListMatrix& M) {
    int rowCount = 0, colCount = 0;
    
    // 统计行链表中的节点数
    for (int i = 0; i < M.rows; i++) {
        CrossNode* p = M.rowHead[i];
        while (p) {
            rowCount++;
            p = p->right;
        }
    }
    
    // 统计列链表中的节点数
    for (int j = 0; j < M.cols; j++) {
        CrossNode* p = M.colHead[j];
        while (p) {
            colCount++;
            p = p->down;
        }
    }
    
    cout << "行链表节点数: " << rowCount << endl;
    cout << "列链表节点数: " << colCount << endl;
    cout << "记录的总节点数: " << M.nums << endl;
    
    if (rowCount == colCount && rowCount == M.nums) {
        cout << "十字链表结构正确！" << endl;
    } else {
        cout << "警告：十字链表结构不一致！" << endl;
    }
}
```

---

## 常见问题解答

### Q1: 为什么快速转置比普通转置快？
A: 快速转置预先计算每列的位置，直接将元素放到正确位置，时间复杂度O(m+n)。普通转置需要多次遍历查找，时间复杂度O(m×n)。

### Q2: 什么时候使用十字链表而不是三元组？
A: 当需要频繁插入删除元素，或需要进行矩阵运算（加法、乘法）时，使用十字链表更合适。

### Q3: 如何处理非常大的稀疏矩阵？
A: 考虑使用分块存储，或使用外存数据结构（如B树）。对于超大规模矩阵，可以考虑分布式存储。

### Q4: 稀疏矩阵的压缩率如何计算？
A: 压缩率 = 1 - (非零元素数 × 存储单元大小) / (总元素数 × 存储单元大小)

### Q5: 如何选择三元组还是十字链表？
A: 
- 静态矩阵、频繁转置 → 三元组
- 动态矩阵、矩阵运算 → 十字链表
- 内存受限 → 三元组（空间更小）

---

希望这些示例和扩展功能对你有帮助！
