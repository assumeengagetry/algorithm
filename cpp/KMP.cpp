#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 构建 next 数组
vector<int> buildNext(const string &pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
    return next;
}

// KMP 搜索
int KMP(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> next = buildNext(pattern);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m)
            return i - m + 1; // 匹配成功，返回起始位置
    }
    return -1; // 未找到
}

int main() {
    string text = "ABC ABCDAB ABCDABCDABDE";
    string pattern = "ABCDABD";
    int pos = KMP(text, pattern);
    if (pos != -1)
        cout << "匹配成功，位置：" << pos << endl;
    else
        cout << "未找到匹配" << endl;
    return 0;
}
