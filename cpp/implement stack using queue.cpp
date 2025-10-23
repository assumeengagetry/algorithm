#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
	queue<int> queue1;
	queue<int> queue2;
	MyStack() {}
    
	void push(int x) {
		queue2.push(x);
		while (!queue1.empty()){
			queue2.push(queue1.front());
			queue1.pop();
		}
		swap(queue1, queue2);
	}
    
	int pop() {
		if (queue1.empty()) return -1; 
        int r = queue1.front();
		queue1.pop();
		return r;
	}
    
	int top() {
		if (queue1.empty()) return -1;
		return queue1.front();
	}
    
	bool empty() {
		return queue1.empty();
	}
};

int main() {
	MyStack st;
	cout << "push 1,2,3" << endl;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "top: " << st.top() << " (expect 3)" << endl;
	cout << "pop: " << st.pop() << " (expect 3)" << endl;
	cout << "top: " << st.top() << " (expect 2)" << endl;
	st.push(4);
	cout << "push 4, top: " << st.top() << " (expect 4)" << endl;
	while (!st.empty()) {
		cout << "pop: " << st.pop() << endl;
	}
	cout << "empty: " << boolalpha << st.empty() << endl;
	return 0;
}
