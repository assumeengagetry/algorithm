# Makefile for Sparse Matrix Implementation

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = sparse_matrix
SOURCE = sparse_matrix.cpp

.PHONY: all clean run test

# 编译主程序
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 运行测试
test: $(TARGET)
	@echo "运行自动化测试..."
	./test.sh

# 清理生成文件
clean:
	rm -f $(TARGET) *.o
	@echo "清理完成！"

# 调试版本（带调试信息）
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)
	@echo "调试版本编译完成！"

# 性能优化版本
release: CXXFLAGS += -O3 -DNDEBUG
release: $(TARGET)
	@echo "优化版本编译完成！"

# 帮助信息
help:
	@echo "可用的make目标："
	@echo "  all     - 编译程序（默认）"
	@echo "  run     - 编译并运行程序"
	@echo "  test    - 运行自动化测试"
	@echo "  clean   - 清理生成文件"
	@echo "  debug   - 编译调试版本"
	@echo "  release - 编译优化版本"
	@echo "  help    - 显示此帮助信息"
