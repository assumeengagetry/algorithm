#include <algorithm>
#include <concepts>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string_view>
#include <vector>

template <std::ranges::input_range R>
void print_range(R&& range, std::string_view title) {
    std::cout << title << ": ";
    for (auto&& value : range) std::cout << value << ' ';
    std::cout << '\n';
}

// 使用 concepts 约束，生成懒加载的偶数平方视图
template <std::integral T>
auto even_square_view(T first, T last) {
    return std::views::iota(first, last)
         | std::views::filter([](T value) { return value % 2 == 0; })
         | std::views::transform([](T value) { return value * value; });
}

int main() {
    // 管道写法：生成 [1, 10) 的数字并翻倍
    auto doubled = std::views::iota(1, 10)
                 | std::views::transform([](int x) { return x * 2; });
    print_range(doubled, "翻倍后的序列");

    // 偶数平方：跳过前两个，截取接下来的五个元素
    auto sliced = even_square_view(1, 40)
                | std::views::drop(2)
                | std::views::take(5)
                | std::views::common; // common 视图让 begin/end 拥有同一 iterator 类型
    print_range(sliced, "偶数平方（跳过前2取5个）");

    const int slice_sum = std::accumulate(std::ranges::begin(sliced), std::ranges::end(sliced), 0);
    std::cout << "片段求和 = " << slice_sum << '\n';

    // 结合 ranges::sort + projection，对字符串按长度排序
    std::vector<std::string_view> words{"ranges", "make", "pipelines", "expressive", "fun"};
    std::ranges::sort(words, {}, [](std::string_view w) { return w.size(); });
    print_range(words, "按长度排序的单词");

    // 利用过滤视图取得长单词，并反转输出
    auto long_words = words | std::views::filter([](std::string_view w) { return w.size() > 5; });
    print_range(long_words, "长度 > 5 的单词");
    auto reversed_long_words = long_words | std::views::reverse;
    print_range(reversed_long_words, "反转后的长单词");

    // std::ranges 算法直接作用于容器
    std::vector<int> data(10);
    std::iota(data.begin(), data.end(), 1);
    auto odds_rev = data | std::views::filter([](int v) { return v % 2 == 1; }) | std::views::reverse;
    print_range(odds_rev, "奇数逆序");

    const bool has_large = std::ranges::any_of(data, [](int v) { return v > 8; });
    std::cout << std::boolalpha << "存在 > 8 的元素? " << has_large << '\n';

    return 0;
}
