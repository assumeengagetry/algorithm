#!/bin/bash
# 自动化测试脚本

echo "开始自动化测试..."
echo ""

# 创建测试输入文件
cat > input.txt << EOF
0 1 2
0 4 3
1 2 4
2 0 5
2 3 6
3 1 7
3 5 8
4 3 9
0 1 2
0 4 3
1 2 4
2 0 5
2 3 6
3 1 7
3 5 8
4 3 9
EOF

# 运行程序
./sparse_matrix < input.txt

echo ""
echo "测试完成！"
