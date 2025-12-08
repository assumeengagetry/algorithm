// 请编写一个函数 process_data，要求：
//
// 接收一个 std::vector<int> 的引用。
//
// 在 vector 的 末尾 插入数字 100。
//
// 查找 vector 中是否包含数字 5，如果找到，将它 删除（只删除第一个找到的即可）。
//
// 打印最终 vector 的大小 (size) 和容量 (capacity)。
//
// 提示：查找和删除可能需要用到 std::find（虽然它是算法库的，但你可以先尝试用循环写，或者查一下 vector 的 erase 方法）。
#include<iostream>
#include<algorithm>
#include<vector>
void process_data(std::vector<int> v){
    v.push_back(100);
    auto it = std::find(v.begin(),v.end(),5);
    if(it != v.end()){
        v.erase(it);
    }
    std::cout<<v.size()<<" "<<v.capacity()<<std::endl;
}
int main(){
    std::vector<int> v = {1,2,3,4,5};
    v.push_back(6);
    v.erase(v.begin() + 2);
    auto it = std::find(v.begin() ,v.end(), 4);
    if(it != v.end()){
    std::cout<<"FOUND:"<<*it<<std::endl;

    }
    for(int a : v){
    std::cout<<a<<std::endl;
    }
    return 0;

}
