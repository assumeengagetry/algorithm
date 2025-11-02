#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    std::stack<int> A, B; 

    void pourAtoB() {
        while (!A.empty()) {
            B.push(A.top());
            A.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        A.push(x);
    }

  
    int pop() {
        if (B.empty()) pourAtoB();
        if (B.empty()) return -1; 
        int v = B.top();
        B.pop();
        return v;
    }

    int peek() {
        if (B.empty()) pourAtoB();
        if (B.empty()) return -1;
        return B.top();
    }
  bool empty() {
        return A.empty() && B.empty();
    }
};

int main() {
    MyQueue q;
    cout << "push 1,2,3" << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "peek: " << q.peek() << " (expect 1)" << endl;
    cout << "pop: " << q.pop() << " (expect 1)" << endl;
    cout << "peek: " << q.peek() << " (expect 2)" << endl;
    q.push(4);
    cout << "push 4, peek: " << q.peek() << " (expect 2)" << endl;
    while (!q.empty()) {
        cout << "pop: " << q.pop() << endl;
    }
    cout << "empty: " << boolalpha << q.empty() << endl;
    return 0;
}
