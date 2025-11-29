#include <iostream>

class ReferenceCounted {
private:
    int* count;  // 引用计数

public:
    ReferenceCounted() {
        count = new int(1);  // 初始化计数为 1
    }

    // 拷贝构造函数
    ReferenceCounted(const ReferenceCounted& other) {
        count = other.count;  // 共享相同的引用计数
        ++(*count);           // 增加引用计数
    }

    // 赋值运算符
    ReferenceCounted& operator=(const ReferenceCounted& other) {
        if (this != &other) {
            --(*count);  // 减少当前对象的引用计数
            if (*count == 0) {
                delete count;  // 删除引用计数
            }
            count = other.count;  // 共享新的引用计数
            ++(*count);  // 增加引用计数
        }
        return *this;
    }

    // 析构函数
    ~ReferenceCounted() {
        --(*count);  // 减少引用计数
        if (*count == 0) {
            delete count;  // 删除引用计数
        }
    }

    // 获取当前引用计数
    int getCount() const {
        return *count;
    }
};

int main() {
    ReferenceCounted obj1;
    std::cout << "obj1 count: " << obj1.getCount() << std::endl;  // 输出 1

    ReferenceCounted obj2 = obj1;  // 拷贝构造
    std::cout << "obj1 count: " << obj1.getCount() << std::endl;  // 输出 2
    std::cout << "obj2 count: " << obj2.getCount() << std::endl;  // 输出 2

    ReferenceCounted obj3;
    obj3 = obj1;  // 赋值运算符
    std::cout << "obj1 count: " << obj1.getCount() << std::endl;  // 输出 3
    std::cout << "obj3 count: " << obj3.getCount() << std::endl;  // 输出 3

    return 0;
}
