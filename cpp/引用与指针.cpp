//TODO:练习题：实现 `swap(int&, int&)` 和 `swap(int*, int*)`
#include <iostream>


class classroom{
public:
    int x;
    classroom(int val){
        x = val;
    }
    void display(){
        std::cout << x << std::endl;
    }
};
class Person {
public:
    std::string name;
    int age;

    // 默认构造函数
    Person() {
        name = "Unknown";
        age = 0;
    }
    Person(std::string x, int y) {
        name = x;
        age = y;
    }
    void display(){
        std::cout<<name<<std::endl;
    }
    ~Person() {
        std::cout << "Person object destroyed" << std::endl;
    }
};


class MyClass {
public:
    int* ptr;

    // 构造函数：动态分配内存
    MyClass() {
        ptr = new int;  // 动态分配内存
    }

    // 析构函数：释放动态分配的内存
    ~MyClass() {
        delete ptr;  // 释放内存
    }
};

class Car{
public:
    int year;
    std::string brand;
    Car() {
        year = 1999;
        brand = "SCU";
    }
    Car(const std::string& b, int y){
        year = y;
        brand = b;
    }
    ~Car(){
        std::cout << "destroyed" << std::endl;
    }
};

// 交换函数：指针版 vs 引用版
void swap_ptr(int* a, int* b) {
    int tmp = *a;  // 必须解引用（dereference）
    *a = *b;
    *b = tmp;
}

void swap_ref(int& a, int& b) {
    int tmp = a;   // 直接像变量一样使用
    a = b;
    b = tmp;
}
inline int multioly(int a, int b){
    return a*b;
}
void ptr(const std::string& name = "help"){
    std::cout<<name<<std::endl;

}
int add(int a, int b) {
    std::cout << "Called add(int, int)" << std::endl;
    return a + b;
}

double add(double a, double b) {
    std::cout << "Called add(double, double)" << std::endl;
    return a + b;
}

// 使用
int main()
{
    int x = 1, y = 2;
    swap_ptr(&x, &y);  // 必须取地址，语法冗余
    swap_ref(x, y);    // 直观，像传值一样
    ptr();
    add(3, 5);       // 调用 add(int, int)
    add(3.5, 5.2);   // 调用 add(double, double)
    add(3.0, 5.2);     // 调用 add(double, double) - int 会被提升为 double
    classroom obj(10);
    obj.display();

    Person per("scu", 10);
    per.display();

    // 创建 Car 对象并调用构造函数
    Car car1; // 默认构造函数
    Car car2("BYD", 2022); // 有参构造函数
    // 作用域结束后会自动调用析构函数
    return 0;
}




