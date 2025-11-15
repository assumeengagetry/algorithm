#include<iostream>
#include<string>
#include<cstring>

class MyString{
private:
    char* str;
    int len;

public:

    MyString() : str(nullptr), len(0) { };
    MyString(const char* s){
        len = std::strlen(s);
        str = new char[len + 1];
        std::strcpy(str, s);

    } 
    ~MyString(){
        delete[] str;
    }
    void input(){
        char temp[100];
        std::cin.getline(temp, 100);
        len = std::strlen(temp);
        str = new char[len + 1];
        std::strcpy(str, temp);    
    }
    void output() const {
        std::cout<< str<< std::endl;
    }



};


int main(){
    MyString s1;
    s1.input();

    s1.output();

}
