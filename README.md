# 文件说明

- Scanner.l : 词法分析脚本
- Parser.y  : 语法分析脚本

- main.c : 主程序

- common.h : 数据结构和函数声明
- common.c : 函数实现

- code.txt  : 测试用例
- codegen.txt : 中间代码

# 运行:

make run

# 运行结果

见 codegen.txt

# 难点

1. 理清楚词法分析脚本和语法分析脚本的关系结构;
2. 拆分代码到不同的文件中, 使每一份代码简短易读;
3. 分支结构的处理, 回填法的实现;