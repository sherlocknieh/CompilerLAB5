TARGET = main
SHELL = CMD


target: $(TARGET)


# 生成可执行文件
$(TARGET): y.tab.c lex.yy.c common.c main.c
	gcc $^ -o $@


# 生成语法分析器
y.tab.c y.tab.h: Parser.y
	bison -yd Parser.y


# 生成词法分析器
lex.yy.c: Scanner.l y.tab.h
	flex Scanner.l


run: $(TARGET)
	./$(TARGET) code.txt


clean:
ifeq ($(SHELL), CMD)
	del lex.yy.c *.tab.* codegen.txt $(TARGET).exe
else
	rm -f lex.yy.c *.tab.* codegen.txt $(TARGET)
endif
