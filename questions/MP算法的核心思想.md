
 KMP（Knuth–Morris–Pratt）算法是**一种高效的字符串匹配算法**，用于在主串中查找子串出现的位置。
 它的最大优点是：在匹配失败时，**不会回退主串指针**，而是利用已经匹配的部分信息来“跳转”子串，从而避免重复比较。

------

## 🧩 一、KMP算法的核心思想

KMP算法的关键在于一个辅助数组：
 👉 **next数组（或称为部分匹配表 / 前缀函数）**

### 基本思想

假设我们要在主串 `S` 中寻找子串 `P`：

当匹配到某个位置时，比如：

```
S: ... A B C D E F G ...
P:     A B C D X
```

匹配到 `D` 时出错（E ≠ X）。

传统暴力匹配会把主串回退到下一位重新开始比较。
 而KMP利用已知的匹配结果（`ABCD`），
 判断：在 `ABCD` 里有没有一部分可以“重用”？

于是，KMP通过 **next数组** 来告诉我们：
 “子串当前匹配失败时，下一次该从哪里开始比对。”

------

## ⚙️ 二、next数组的含义

**定义：**
 `next[i]` 表示：在子串 `P[0..i]` 中，
 **最长的相等前后缀的长度。**

例如：

```
P = "ABCDABD"
```

| i    | 字符 | 前缀   | 后缀  | 最长相等前后缀长度 | next[i] |
| ---- | ---- | ------ | ----- | ------------------ | ------- |
| 0    | A    | -      | -     | 0                  | 0       |
| 1    | B    | A      | B     | 0                  | 0       |
| 2    | C    | AB     | BC    | 0                  | 0       |
| 3    | D    | ABC    | BCD   | 0                  | 0       |
| 4    | A    | ABCD   | BCDA  | 1（A）             | 1       |
| 5    | B    | ABCDA  | CDAB  | 2（AB）            | 2       |
| 6    | D    | ABCDAB | CDABD | 0                  | 0       |

👉 所以 `next[] = {0, 0, 0, 0, 1, 2, 0}`

------

## 💡 三、匹配过程

假设：

```
主串 S = ABC ABCDAB ABCDABCDABDE
子串 P = ABCDABD
```

1. 从 S[0] 和 P[0] 开始匹配。
2. 匹配到 P[6] 失败时，KMP查next[5] = 2
    → 意味着“子串前2个字符（AB）已经匹配，可以从P[2]继续”。
3. 主串不回退，子串跳转，从新位置继续匹配。

这样，主串的每个字符最多比较一次，时间复杂度 **O(n + m)**。

------

## 🧠 四、C++实现示例

```cpp
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
```

------

## 🧾 五、复杂度分析

| 操作           | 时间复杂度   | 空间复杂度 |
| -------------- | ------------ | ---------- |
| 构造 next 数组 | O(m)         | O(m)       |
| 匹配过程       | O(n)         | O(1)       |
| **总计**       | **O(n + m)** | **O(m)**   |

相比普通暴力匹配 O(n × m)，效率高得多。

------

## 🎯 六、总结

KMP算法的关键是：

1. **前缀函数（next数组）** 记录子串的部分匹配信息。
2. **匹配失败不回退主串**，而是通过 next 数组快速跳转。
3. 时间复杂度线性，适合大规模字符串匹配。