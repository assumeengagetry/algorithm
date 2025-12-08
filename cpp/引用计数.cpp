#include <iostream>

class ReferenceCounted {
private:
    int* count;  // 引用计数

public:
    ReferenceCounted() {
      count = new int(1);
    }

    // 拷贝构造函数
    ReferenceCounted(const ReferenceCounted& other) {
        count = other.count;
        (*count) ++;
    }

    // 赋值运算符
    ReferenceCounted& operator=(const ReferenceCounted& other) {
        if(this != &other){
            (*count) --;
            if(*count == 0 ){
                delete count;
            }
            count = other.count;
            (*count) ++;
        }
        return *this;
    }

    // 析构函数
    ~ReferenceCounted() {
        (*count) --;
        if(*count == 0){
            delete count;
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
