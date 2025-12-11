#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class Person {
private:
  const std::string name; // const成员（必须初始化，不能赋值）
  int& age; // 引用成员（必须初始化，不能改绑）
  std::string addr;
public:
  // 初始化列表初始化成员（唯一能初始化const和引用的方式）
  Person(std::string n, int& a, std::string ad)
      : name(std::move(n)), age(a), addr(std::move(ad)) {
    // 构造函数体：可做其他逻辑（如参数校验）
    if (a < 0) throw std::invalid_argument("年龄不能为负");
  }

  void relocate(std::string newAddr) { addr = std::move(newAddr); }
  void haveBirthday() { ++age; }

  const std::string& getName() const { return name; }
  int getAge() const { return age; }
  const std::string& getAddress() const { return addr; }
};

int age = 25;
Person p("Eve", age, "Beijing"); // 正确初始化const、引用、普通成员


class FileGuard {
private:
  std::FILE* file = nullptr; // 资源：文件句柄
public:
  // 构造时获取资源（打开文件）
  FileGuard(const char* path, const char* mode) {
    file = std::fopen(path, mode);
    if (!file) throw std::runtime_error(std::string("文件打开失败: ") + path);
  }

  // 禁止拷贝，允许移动
  FileGuard(const FileGuard&) = delete;
  FileGuard& operator=(const FileGuard&) = delete;

  FileGuard(FileGuard&& other) noexcept : file(other.file) { other.file = nullptr; }

  FileGuard& operator=(FileGuard&& other) noexcept {
    if (this != &other) {
      if (file) std::fclose(file);
      file = other.file;
      other.file = nullptr;
    }
    return *this;
  }

  // 析构时释放资源（关闭文件）
  ~FileGuard() {
    if (file) std::fclose(file);
  }

  // 提供访问接口
  std::FILE* getFile() const { return file; }
};

// 使用：无需手动关闭文件
std::string readFile(const char* path) {
  FileGuard fg(path, "r"); // 打开文件（获取资源）

  std::string content;
  char buffer[256];
  std::size_t bytesRead = 0;
  while ((bytesRead = std::fread(buffer, 1, sizeof(buffer), fg.getFile())) > 0) {
    content.append(buffer, bytesRead);
  }

  if (std::ferror(fg.getFile())) {
    throw std::runtime_error(std::string("文件读取失败: ") + path);
  }

  return content;
} // fg销毁，析构函数自动关闭文件（释放资源）

int main() {
  try {
    std::cout << "当前信息: " << p.getName() << ", " << p.getAge()
              << " 岁, 地址 " << p.getAddress() << '\n';

    p.haveBirthday();
    p.relocate("Shanghai");
    std::cout << "生日后: " << p.getAge() << " 岁, 新地址 " << p.getAddress()
              << " (全局age = " << age << ")\n";

    std::cout << "尝试读取 test.txt...\n";
    const std::string content = readFile("test.txt");
    std::cout << "读取成功, 字节数: " << content.size() << '\n';
    std::cout << content << '\n';
  } catch (const std::exception& ex) {
    std::cerr << "发生异常: " << ex.what() << '\n';
    return 1;
  }

  return 0;
}
