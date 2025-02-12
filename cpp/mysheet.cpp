#include<iostream>
#include<string>
#include<stack>
using namespace std;
class solution{
private:
    stack<char> st;
public:
void push(char x){
    st.push(x);
}
void pop(){
    if(!st.empty()){
        st.pop();
    }
}
char top(){
    if (!st.empty()){
        return st.top();
    }
}
bool is_valid(string s){
    
    if(s.size()%2!=0) return false;
    for(int i=0;i< s.size()+1; i++){
        if(s[i]=='(') st.push(')');
        else if(s[i]=='{') st.push('}');
        else if(s[i]=='[') st.push(']');
        else if(st.empty() || st.top() != s[i]) return false;
        else st.pop();
    }
    return st.empty();
}
string tostring(){
    stack<char> temst(st) ;
    string s;
    while (!temst.empty())
    {
        s+=temst.top();
        temst.pop();
    }
    return s;

}
};
int main(){
solution stack;
int a;cin>>a;
for(int j=0; j< a; j++){
    int b;cin>>b;
    if(b==1) {
        char c; cin>>c; stack.push(c);
    }
    else  if(b==2){
        stack.pop();
    }
    else if(b==3){
        char d=stack.top();
        if(d!= '\0') cout<<d<<endl;
    }
    else if(b==4){
         string s=stack.tostring();
        cout<<(stack.is_valid(s) ? "YES":"NO")<<endl;
    }
}
}
