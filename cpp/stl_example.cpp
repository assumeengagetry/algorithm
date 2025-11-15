#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <iterator>
#include <memory>

using namespace std;

// 1. Vector 容器示例
void vectorExample() {
    cout << "\n=== Vector 容器示例 ===" << endl;
    
    vector<int> vec = {3, 1, 4, 1, 5, 9};
    
    // 添加元素
    vec.push_back(2);
    vec.insert(vec.begin() + 2, 100);
    
    // 访问元素
    cout << "第一个元素: " << vec.front() << endl;
    cout << "最后一个元素: " << vec.back() << endl;
    cout << "索引2的元素: " << vec[2] << endl;
    
    // 遍历
    cout << "所有元素: ";
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 排序
    sort(vec.begin(), vec.end());
    cout << "排序后: ";
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

// 2. List 容器示例
void listExample() {
    cout << "\n=== List 容器示例 ===" << endl;
    
    list<string> myList = {"apple", "banana", "cherry"};
    
    // 添加元素
    myList.push_front("strawberry");
    myList.push_back("orange");
    
    // 删除元素
    myList.remove("banana");
    
    // 遍历
    cout << "List 元素: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;
    
    // 排序
    myList.sort();
    cout << "排序后: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;
}

// 3. Set 和 Map 示例
void setMapExample() {
    cout << "\n=== Set 容器示例 ===" << endl;
    
    set<int> mySet = {5, 1, 3, 1, 3, 7};  // 自动去重和排序
    mySet.insert(2);
    
    cout << "Set 元素 (自动排序和去重): ";
    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    
    cout << "\n=== Map 容器示例 ===" << endl;
    
    map<string, int> scoreMap;
    scoreMap["Alice"] = 95;
    scoreMap["Bob"] = 87;
    scoreMap["Charlie"] = 92;
    scoreMap.insert({"David", 88});
    
    cout << "成绩表:" << endl;
    for (const auto& [name, score] : scoreMap) {
        cout << name << ": " << score << endl;
    }
    
    // 查找
    if (scoreMap.find("Bob") != scoreMap.end()) {
        cout << "Bob 的成绩: " << scoreMap["Bob"] << endl;
    }
}

// 4. Unordered 容器示例
void unorderedExample() {
    cout << "\n=== Unordered Map 示例 ===" << endl;
    
    unordered_map<string, double> priceMap = {
        {"apple", 2.5},
        {"banana", 1.8},
        {"orange", 3.2}
    };
    
    priceMap["grape"] = 4.5;
    
    cout << "价格表 (无序):" << endl;
    for (const auto& [item, price] : priceMap) {
        cout << item << ": $" << price << endl;
    }
    
    cout << "\n=== Unordered Set 示例 ===" << endl;
    
    unordered_set<int> hashSet = {10, 20, 30, 40, 50};
    hashSet.insert(25);
    
    cout << "HashSet 元素 (无序): ";
    for (const auto& elem : hashSet) {
        cout << elem << " ";
    }
    cout << endl;
}

// 5. Stack 和 Queue 示例
void stackQueueExample() {
    cout << "\n=== Stack 示例 ===" << endl;
    
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "Stack 出栈顺序: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
    
    cout << "\n=== Queue 示例 ===" << endl;
    
    queue<string> myQueue;
    myQueue.push("First");
    myQueue.push("Second");
    myQueue.push("Third");
    
    cout << "Queue 出队顺序: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    
    cout << "\n=== Priority Queue 示例 ===" << endl;
    
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    
    cout << "优先队列 (最大堆): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// 6. 算法示例
void algorithmExample() {
    cout << "\n=== 算法示例 ===" << endl;
    
    vector<int> nums = {3, 7, 1, 4, 6, 2, 9, 8, 5};
    
    // 查找
    auto it = find(nums.begin(), nums.end(), 6);
    if (it != nums.end()) {
        cout << "找到元素 6 在位置: " << distance(nums.begin(), it) << endl;
    }
    
    // 计数
    int count1 = count(nums.begin(), nums.end(), 4);
    cout << "元素 4 出现次数: " << count1 << endl;
    
    // 最大最小值
    auto minIt = min_element(nums.begin(), nums.end());
    auto maxIt = max_element(nums.begin(), nums.end());
    cout << "最小值: " << *minIt << ", 最大值: " << *maxIt << endl;
    
    // 求和
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "总和: " << sum << endl;
    
    // 排序
    sort(nums.begin(), nums.end());
    cout << "排序后: ";
    for (const auto& n : nums) {
        cout << n << " ";
    }
    cout << endl;
    
    // 反转
    reverse(nums.begin(), nums.end());
    cout << "反转后: ";
    for (const auto& n : nums) {
        cout << n << " ";
    }
    cout << endl;
    
    // 二分查找 (需要先排序)
    sort(nums.begin(), nums.end());
    bool found = binary_search(nums.begin(), nums.end(), 5);
    cout << "二分查找 5: " << (found ? "找到" : "未找到") << endl;
}

// 7. Lambda 表达式和函数对象
void lambdaExample() {
    cout << "\n=== Lambda 表达式示例 ===" << endl;
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 使用 lambda 进行条件计数
    int evenCount = count_if(vec.begin(), vec.end(), 
                            [](int n) { return n % 2 == 0; });
    cout << "偶数个数: " << evenCount << endl;
    
    // 使用 lambda 进行变换
    vector<int> squared;
    transform(vec.begin(), vec.end(), back_inserter(squared),
              [](int n) { return n * n; });
    
    cout << "平方后: ";
    for (const auto& n : squared) {
        cout << n << " ";
    }
    cout << endl;
    
    // 使用 lambda 进行过滤
    vector<int> filtered;
    copy_if(vec.begin(), vec.end(), back_inserter(filtered),
            [](int n) { return n > 5; });
    
    cout << "大于5的元素: ";
    for (const auto& n : filtered) {
        cout << n << " ";
    }
    cout << endl;
}

// 8. 智能指针示例
void smartPointerExample() {
    cout << "\n=== 智能指针示例 ===" << endl;
    
    // unique_ptr
    unique_ptr<int> uptr = make_unique<int>(42);
    cout << "unique_ptr 值: " << *uptr << endl;
    
    // shared_ptr
    shared_ptr<string> sptr1 = make_shared<string>("Hello");
    shared_ptr<string> sptr2 = sptr1;  // 共享所有权
    cout << "shared_ptr 值: " << *sptr1 << endl;
    cout << "引用计数: " << sptr1.use_count() << endl;
    
    // weak_ptr
    weak_ptr<string> wptr = sptr1;
    if (auto sptr = wptr.lock()) {  // 尝试获取 shared_ptr
        cout << "weak_ptr 访问: " << *sptr << endl;
    }
}

// 9. Pair 和 Tuple 示例
void pairTupleExample() {
    cout << "\n=== Pair 示例 ===" << endl;
    
    pair<string, int> p1 = make_pair("Alice", 25);
    pair<string, int> p2("Bob", 30);
    
    cout << p1.first << " 年龄: " << p1.second << endl;
    cout << p2.first << " 年龄: " << p2.second << endl;
    
    // 在 map 中使用 pair
    vector<pair<string, double>> scores = {
        {"Math", 95.5},
        {"Physics", 88.0},
        {"Chemistry", 92.3}
    };
    
    cout << "\n成绩单:" << endl;
    for (const auto& [subject, score] : scores) {
        cout << subject << ": " << score << endl;
    }
}

// 10. String 操作示例
void stringExample() {
    cout << "\n=== String 操作示例 ===" << endl;
    
    string str = "Hello, World!";
    
    // 基本操作
    cout << "原字符串: " << str << endl;
    cout << "长度: " << str.length() << endl;
    cout << "第5个字符: " << str[5] << endl;
    
    // 查找
    size_t pos = str.find("World");
    if (pos != string::npos) {
        cout << "\"World\" 位置: " << pos << endl;
    }
    
    // 子串
    string sub = str.substr(7, 5);
    cout << "子串(7, 5): " << sub << endl;
    
    // 替换
    str.replace(0, 5, "Hi");
    cout << "替换后: " << str << endl;
    
    // 插入和删除
    str.insert(3, " there");
    cout << "插入后: " << str << endl;
    
    str.erase(3, 6);
    cout << "删除后: " << str << endl;
    
    // 大小写转换
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "大写: " << str << endl;
}

// 主函数
int main() {
    cout << "===== C++ STL 综合示例 =====" << endl;
    
    vectorExample();
    listExample();
    setMapExample();
    unorderedExample();
    stackQueueExample();
    algorithmExample();
    lambdaExample();
    smartPointerExample();
    pairTupleExample();
    stringExample();
    
    cout << "\n===== 程序结束 =====" << endl;
    
    return 0;
}