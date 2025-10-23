#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(const string &s) {

        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }
       if (st.empty()) return false;
            char t = st.top();
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
            st.pop();
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    vector<string> tests = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",
        "(",
        ")",
        "(([]){})",
    };

    for (auto &t : tests) {
        cout << "s=\"" << t << "\" -> " << (sol.isValid(t) ? "true" : "false") << '\n';
    }
    return 0;
}
