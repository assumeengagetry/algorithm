#include <iostream>
#include <cstring>

class refcountNode {
private:
    int* data;
    int* count;

public:
    refcountNode* next;

    // 构造函数
    refcountNode(int value) {
        data = new int(value);
        count = new int(1);  // 初始化引用计数为 1
        next = nullptr;
    }

    // 拷贝构造函数
    refcountNode(const refcountNode& other) {
        data = new int(*other.data);  // 深拷贝数据
        count = new int(1);           // 初始化新的引用计数
        next = nullptr;
    }

    // 赋值运算符
    refcountNode& operator=(const refcountNode& other) {
        if (this != &other) {
            // 减少当前引用计数
            (*count)--;
            if (*count == 0) {
                delete count;
                delete data;
            }

            // 深拷贝
            data = new int(*other.data);  // 深拷贝数据
            count = new int(1);           // 初始化新的引用计数
            next = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~refcountNode() {
        (*count)--;
        if (*count == 0) {
            delete count;
            delete data;
        }
    }

    int getdata() const {
        return *data;
    }
};

class refcountList {
private:
    refcountNode* head;

public:
    refcountList(int val) {
        head = new refcountNode(val);
    }

    void addNode(int val) {
        refcountNode* newNode = new refcountNode(val);
        newNode->next = head;
        head = newNode;
    }

    ~refcountList() {
        delete head;  // 删除链表中的所有节点
    }
};

int main() {
    refcountList list(10);
    list.addNode(20);
    list.addNode(30);

    // list 中的节点和引用计数会自动管理
    return 0;
}
