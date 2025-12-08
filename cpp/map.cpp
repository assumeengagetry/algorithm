#include<iostream>
#include<sstream>
#include<map>
int main(){
std::string text = "hello world hello c++ hello STL";
std::map<std::string, int> m;
std::stringstream ss(text);
std::string word;

while(ss>>word){
    m[word]++;
}
for(const auto& pair : m){
    std::cout<<pair.first<<" "<<pair.second<<std::endl;
}
return 0;
}
