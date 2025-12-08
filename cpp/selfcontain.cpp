#include <iostream>
#include <cstring>

class String{
private:
    char* data_;
    size_t size_;
public:
    String(): data_(new char[1]), size_(0){
        data_[0] = '\0';
    }    
    String(const char* s){
        if(!s){
            data_ = new char[1];
            data_[0] = '\0';
            size_ = 0;
        }
        else{
            size_ = std::strlen(s);
            data_ = new char[size_ + 1];
            std::strcpy(data_, s);
        }
    }
    String(const String& other): size_(other.size_), data_(new char[other.size_+1])
    {
        std::strcpy(data_, other.data_);
    }
    String& operator=(const String& other){
        if(this != &other){
            delete[] data_;
            size_ = other.size_;
            data_ = new char[size_ + 1];
            std::strcpy(data_, other.data_);
        }
        return *this;
    }
    ~String() {
        delete[] data_;
    } 
    size_t size() const{
        return size_;
    }
    const char* c_str() const {
        return data_;
    }
    char& operator[](size_t i){
        return data_[i];
    }
        const char& operator[](size_t i) const {
        return data_[i];
    }
  void test_string() {
    String s1("hello");
    std::cout << "s1 = " << s1.c_str() << ", size = " << s1.size() << std::endl;

    String s2 = s1;  // 拷贝构造
    std::cout << "s2 = " << s2.c_str() << ", size = " << s2.size() << std::endl;

    s2[0] = 'H';     // 改 s2，不应该影响 s1（验证深拷贝）
    std::cout << "after s2[0]='H':" << std::endl;
    std::cout << "s1 = " << s1.c_str() << std::endl;  // 仍然是 hello
    std::cout << "s2 = " << s2.c_str() << std::endl;  // 变成 Hello

    String s3;
    s3 = s1;         // 赋值运算符
    std::cout << "s3 = " << s3.c_str() << ", size = " << s3.size() << std::endl;

    s3 = s3;         // 自赋值测试，不应该崩溃
}
};

int main() {
    String s;
    s.test_string();
    return 0;
}  

