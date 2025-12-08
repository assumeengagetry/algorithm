#include <iostream>
#include <ranges>  // C++20 特性
int main() {
    auto nums = std::views::iota(1, 6) | std::views::transform([](int x) { return x * 2; });
    for (int x : nums) std::cout << x << " ";  // 输出：2 4 6 8 10
    return 0;
}

