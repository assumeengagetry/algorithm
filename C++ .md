① 基础语法 & C++98 标准库（地基）

目标：学会语法、内存模型、STL，理解 RAII。

📌 学习内容

基础语法：变量、函数、类、继承、多态、模板、异常等

C++98 STL：vector/map/set/algorithm/string/iostream

内存模型：指针、引用、堆、栈、作用域

RAII（资源自动管理）

构造函数/析构函数/拷贝语义

📘 必学 C++98 技术

模板（函数/类模板）

迭代器

异常机制

namespace

RTTI（typeid、dynamic_cast）

🎯 阶段产出

会用 STL 容器和算法

能写简单类、继承、虚函数

会正确使用 new/delete

了解 C++ 的基本复杂性

② C++11：现代 C++ 的核心（必须精通）

目标：掌握现代 C++ 的主要特征。
C++11 是现代 C++ 的基础墙体。

📌 学习内容

主要包括 10 大核心：

auto 类型推断

智能指针（unique_ptr / shared_ptr / weak_ptr）

右值引用 + 移动语义（核心难点）

lambda 表达式

range-based for

constexpr（编译期计算）

enum class

nullptr

多线程库（thread/mutex/lock_guard）

可变参数模板

📘 C++11 代表代码块

移动构造函数

lambda 捕获详解

使用智能指针管理资源

多线程的生产者-消费者

🎯 阶段产出

理解现代 C++ 的根本思想（值类别、资源控制、自动化）

会写“正确、安全、现代”的代码

能读懂主流开源库代码（如 Qt、Abseil）

③ C++14：语法糖与优化（中等重要）

C++14 不多，但非常实用，能让你的代码更流畅。

📌 学习内容

泛型 lambda

decltype(auto)

std::make_unique

变量模板

constexpr 扩展

🎯 阶段产出

理解 C++14 是 C++11 的修补

会写“无痛可读”的 lambda 和模板

④ C++17：工程实用特性（必须熟）

现代工程几乎全部基于 C++17。

📌 学习内容

结构化绑定 auto [x,y] = ...

optional / variant / any

filesystem（超实用）

if/switch 带初始化语句

并行算法

折叠表达式（fold expression）

CTAD（模板实参推导）

🎯 阶段成果

可以写现代风格的工程代码

学会 optional/variant 解决错误与类型问题

会用 filesystem 写工具/脚本

⑤ C++20：重大变革（高级部分）

这是 C++ 近 20 年最大革新，难度偏高。

📌 学习内容（4 大块）
① Concepts（概念）

requires 子句

约束模板

type trait + concepts 合作

② Ranges（超强现代算法框架）

views

pipeline（链式操作）

懒序列

③ 协程（coroutine）

co_await

co_yield

返回协程类型

④ 模块（module）

export

import

与头文件的区别

其他 C++20 新特性

spaceship <=>

consteval / constinit

span

format（重要）

chrono 扩展

线程库增强

🎯 阶段产出

能设计现代风格接口

掌握异步模型（协程）

能用模块构建大型工程

⑥ C++23：补完与库增强（轻量）

强化库功能 + 更强 constexpr。

📌 学习内容

expected（错误返回类型）

更多 ranges（zip、chunk、slide）

容器新 API

deducing this

constexpr 扩展

char8_t 与 UTF-8

🎯 阶段产出

掌握 C++20 后自然能吸收 C++23

补强工程风格

⑦ 专题进阶：跨版本综合能力

将所有 C++ 标准的知识整合起来的终极阶段。

📌 专题清单

内存模型（值类别 + 生命周期）

模板元编程（TMP / SFINAE / Concepts）

异步编程（多线程 + 协程）

工程构建（CMake + modules）

性能优化（移动语义、避免拷贝、span）

“现代 interface 设计”（optional、expected、ranges）

单元测试与调试（gtest、sanitizer）

# 📘 C++ 12 周学习计划（Markdown 版）

> 适合大二学生 / 从 C++98 → C++23 的系统化学习路线
>  每周 8–12 小时，含每日任务 + 练习题 + 参考答案

------

# 🗓 总览

- Week 1：C++98 基础语法 & 内存模型
- Week 2：STL 容器 & 迭代器
- Week 3：面向对象、异常、RTTI
- Week 4：C++11 基础语法升级
- Week 5：智能指针 & RAII
- Week 6：移动语义（核心）
- Week 7：Lambda & 多线程
- Week 8：C++14/17 语法糖 + optional/variant
- Week 9：C++17 深水区（并行算法、fold、CTAD）
- Week 10：C++20 Concepts & Ranges
- Week 11：协程 & 模块
- Week 12：C++23 + 最终项目

------

# 📘 Week 1 — C++98 基础语法 & 内存模型

## 🎯 学习目标

- 理解变量、作用域、堆/栈、指针引用
- 能写简单类（构造/拷贝/析构）
- 会用 new/delete（理解生命周期）

## 📅 日程安排

### Day 1

- 学内容：基本类型、作用域、指针与引用
- 练习题：实现 `swap(int&, int&)` 和 `swap(int*, int*)`

### Day 2

- 学内容：函数、内联函数、默认参数、重载
- 练习题：写三个重载的 `max()` 函数

### Day 3

- 学内容：类与对象、构造/析构
- 练习题：写一个 `Point` 类

### Day 4

- 学内容：拷贝构造与赋值运算符
- 练习题：写一个管理 `char*` 的 `String` 类（深拷贝）

### Day 5

- 学内容：引用计数（手动）
- 练习题：实现一个简单的引用计数资源

### Day 6–7（实践）

- 小项目：手写 `String` 类（含拷贝/赋值/析构），带测试

## 📝 练习题答案

- swap、max、String 深拷贝构造函数的完整代码样例

------

# 📘 Week 2 — STL 容器 / 算法 / 迭代器

## 🎯 学习目标

- 熟练使用 vector/list/map/string
- 使用迭代器与算法库

## 📅 日程安排

### Day 1

- vector、list 用法
- 练习：用 vector 实现插入/删除/查找

### Day 2

- map/set
- 练习：词频统计

### Day 3

- 迭代器种类
- 练习：写一个自定义迭代器（简单）

### Day 4

- 算法库（sort/find/accumulate）
- 练习：对结构体排序

### Day 5

- string & iostream
- 练习：把 CSV 文件按行读入 vector

### Day 6–7

- 小项目：CSV reader 工具

## 📝 练习题答案

包含：词频统计、结构体排序、自定义迭代器样例

------

# 📘 Week 3 — OOP / 异常 / RTTI

## 🎯 学习目标

- 虚函数、继承、多态
- 异常（try/catch/throw）
- RTTI：typeid, dynamic_cast

## 📅 日程安排

### Day 1

- 继承、多态
- 练习：Shape 基类，Circle/Rect 派生

### Day 2

- 虚函数机制
- 练习：虚函数表打印（示意）

### Day 3

- 异常：throw、捕获规则
- 练习：写一个 divide 函数抛出异常

### Day 4

- RTTI
- 练习：用 dynamic_cast 判断类型

### Day 5

- 异常安全（强/基本保证）
- 练习：在资源管理中使用异常

### Day 6–7

- 小项目：图形类层次结构 + 异常安全加载器

## 📝 练习题答案

包含：Shape 类、divide 异常、安全资源管理

------

# 📘 Week 4 — C++11 语法升级（auto / nullptr / enum class）

## 🎯 目标

- 掌握 C++11 新基础语法
- 改造前 3 周旧式代码

## 📅 日程安排

### Day 1

- auto / decltype

### Day 2

- nullptr / enum class

### Day 3

- range-for rewrite

### Day 4

- uniform initialization

### Day 5

- override / final

### Day 6–7

- 重构 Week 1–3 代码为 C++11 风格

------

# 📘 Week 5 — 智能指针（unique_ptr / shared_ptr / weak_ptr）

## 🎯 目标

- RAII 与资源管理现代化
- 避免内存泄漏与悬空指针

## 📅 日程安排

### Day 1

unique_ptr

### Day 2

shared_ptr

### Day 3

weak_ptr（解决循环引用）

### Day 4

make_shared / make_unique

### Day 5

智能指针最佳实践

### Day 6–7

小项目：智能指针版链表 or 树结构

------

# 📘 Week 6 — 移动语义（C++11 核心）

## 🎯 目标

理解值类别、右值引用、移动构造

## 📅 日程

### Day 1

左值与右值

### Day 2

右值引用 、std::move

### Day 3

移动构造函数

### Day 4

移动赋值

### Day 5

完美转发

### Day 6–7

小项目：实现可移动 vector

------

# 📘 Week 7 — Lambda & 多线程

## 🎯 目标

- lambda 捕获
- thread/mutex/lock_guard
- condition_variable

## 📅 日程

### Day 1

lambda 基础

### Day 2

捕获（按值/引用/混合）

### Day 3

thread

### Day 4

mutex/lock_guard

### Day 5

condition_variable

### Day 6–7

小项目：生产者-消费者队列

------

# 📘 Week 8 — C++14/17

## 🎯 目标

- 泛型 lambda、make_unique
- optional, variant, any
- filesystem

## 📅 日程

### Day 1

泛型 lambda

### Day 2

decltype(auto)

### Day 3

optional

### Day 4

variant

### Day 5

filesystem

### Day 6–7

小项目：文件扫描工具

------

# 📘 Week 9 — C++17 深水区

## 🎯 目标

理解并使用：

- CTAD
- 并行算法
- Fold expressions

## 📅 日程

### Day 1

CTAD 示例

### Day 2

fold 表达式

### Day 3

并行算法

### Day 4

inline variables

### Day 5

C++17 综合

### Day 6–7

小项目：并行排序 + 性能对比

------

# 📘 Week 10 — C++20 Concepts & Ranges

## 🎯 目标

- requires、concept 定义
- Ranges（filter/transform/views）

## 📅 日程

### Day 1

requires 基础

### Day 2

自定义 concept

### Day 3

ranges filter

### Day 4

ranges transform

### Day 5

ranges pipeline 综合

### Day 6–7

小项目：数据流水线工具

------

# 📘 Week 11 — 协程 & 模块

## 🎯目标

- 初步理解协程结构
- 写 generator
- 使用模块

## 📅 日程

### Day 1

协程语法

### Day 2

co_yield 示例

### Day 3

awaitable 分析

### Day 4

模块 export/import

### Day 5

模块化重写工具

### Day 6–7

小项目：协程生成器 or 模块化库

------

# 📘 Week 12 — C++23 + 最终项目

## 🎯目标

- expected
- ranges 更多 views（chunk/slide）
- constexpr 增强

## 📅 日程

### Day 1

expected

### Day 2

ranges chunk/slide

### Day 3

constexpr 优化

### Day 4

综合复习

### Day 5

最终项目准备

### Day 6–7

最终项目（任选其一）

- A：文件搜索与索引器
- B：JSON-lite 解析器（variant + expected）
- C：协程异步任务执行器

------

```cpp
// C++ 12-Week Exercise Answers
// This file contains reference solutions for all daily exercises.
// Organized by week/day.

/**************************************
 * Week 1 — C++98 Fundamentals
 **************************************/

// Day 1: Variables & Functions
int add(int a, int b) { return a + b; }

// Day 2: Pointers & References
void swap_ptr(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void swap_ref(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// Day 3: Classes & Constructors
class Person {
    std::string name;
public:
    Person(const std::string& n) : name(n) {}
    std::string get() const { return name; }
};

// Day 4: Inheritance & Polymorphism
class Animal { public: virtual std::string sound() const { return "???"; }};
class Dog : public Animal { public: std::string sound() const override { return "woof"; }};

// Day 5: STL vector
int sum_vector(const std::vector<int>& v) {
    int s = 0;
    for (int x : v) s += x;
    return s;
}

// Day 6: map
std::string find_name(const std::map<int,std::string>& mp, int id) {
    auto it = mp.find(id);
    return it == mp.end() ? "NA" : it->second;
}

// Day 7: Exception
int divide(int a, int b) {
    if (b == 0) throw std::runtime_error("div 0");
    return a / b;
}

/**************************************
 * Week 2 — C++98 Templates / RAII
 **************************************/

// Day 8: Function Template
template<typename T>
T mymax(T a, T b) { return a > b ? a : b; }

// Day 9: Class Template
template<typename T>
class Box { T v; public: Box(T x):v(x){} T get() const { return v; }};

// Day 10: RAII
class File {
    FILE* fp;
public:
    File(const char* path){ fp=fopen(path,"r"); }
    ~File(){ if(fp) fclose(fp); }
};

// Day 11: Iterator Use
int sum_it(std::vector<int>::const_iterator b,
           std::vector<int>::const_iterator e){
    int s=0; while(b!=e) s+=*b++; return s;
}

// Day 12: RTTI
std::string type_name(const Animal* a){
    if(dynamic_cast<const Dog*>(a)) return "Dog";
    return "Animal";
}

// Day 13–14: Mini Project — Omitted for brevity

/**************************************
 * Week 3 — C++11 Core Features
 **************************************/

// Day 15: auto
auto mul = [](int a,int b){ return a*b; };

// Day 16: unique_ptr
std::unique_ptr<int> make_int(){ return std::make_unique<int>(42); }

// Day 17: Move Semantics
class Move { public: Move(){} Move(Move&&){} };

// Day 18: Lambda capture
int x = 10;
auto lam = [x](int v){ return x+v; };

// Day 19: Thread
template<typename F>
void run(F f){ std::thread t(f); t.join(); }

// Day 20: Variadic Template
template<typename... Args>
int count_args(Args...){ return sizeof...(Args); }

// Day 21: constexpr
constexpr int sq(int x){ return x*x; }

/**************************************
 * Week 4 — C++11 Advanced
 **************************************/

// Day 22: enum class
enum class Color{Red,Blue};

// Day 23: shared_ptr
struct Node { std::shared_ptr<Node> next; int v; };

// Day 24: weak_ptr (break cycle)
struct A { std::weak_ptr<A> self; };

// Day 25: noexcept
void foo() noexcept {}

// Day 26: initializer_list
int sum_init(std::initializer_list<int> a){ int s=0; for(int x:a)s+=x; return s; }

// Day 27: =delete
struct NoCopy { NoCopy(){} NoCopy(const NoCopy&)=delete; };

// Day 28: Mini Project — Omitted

/**************************************
 * Week 5 — C++14
 **************************************/

auto gen_lambda = [](auto x){ return x+1; };

auto ret_ref(int& r)->decltype(auto){ return (r); }

/**************************************
 * Week 6 — C++14 Advanced
 **************************************/

constexpr int fib(int n){ return n<=1?n:fib(n-1)+fib(n-2); }

/**************************************
 * Week 7 — C++17
 **************************************/

auto [a,b] = std::pair<int,int>{1,2};

std::optional<int> maybe(int x){ return x>0?std::optional<int>(x):std::nullopt; }

/**************************************
 * Week 8 — C++17 Advanced
 **************************************/

std::variant<int,std::string> getv(bool f){ return f?variant<int,string>(1):"hi"; }

/**************************************
 * Week 9 — C++20 Basics
 **************************************/

// Concept
#include <concepts>
template<std::integral T>
T add2(T a,T b){ return a+b; }

// Ranges
#include <ranges>
auto view_even(const std::vector<int>& v){ return v | std::views::filter([](int x){return x%2==0;}); }

/**************************************
 * Week 10 — C++20 Coroutines
 **************************************/
// Minimal coroutine example (pseudo)
#include <coroutine>
struct Task {
    struct promise_type {
        Task get_return_object(){return{};} 
        std::suspend_never initial_suspend(){return{};} 
        std::suspend_never final_suspend() noexcept {return{};} 
        void return_void(){}
        void unhandled_exception(){throw;}
    };
};
Task foo_co(){ co_return; }

/**************************************
 * Week 11 — C++20 Modules
 **************************************/
// Not runnable here, example syntax only:
// export module math;
// export int add_mod(int a,int b){ return a+b; }

/**************************************
 * Week 12 — C++23
 **************************************/

#include <expected>
std::expected<int,std::string> safe_div(int a,int b){
    if(b==0) return std::unexpected("div0");
    return a/b;
}

```

