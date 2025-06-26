TARGET = main
SHELL = CMD


target: $(TARGET)


# 生成可执行文件
$(TARGET): y.tab.c lex.yy.c common.c main.c
	gcc $^ -o $@


# 生成语法分析器
y.tab.c y.tab.h: parser.y
	bison -yd parser.y


# 生成词法分析器
lex.yy.c: lexer.l y.tab.h
	flex lexer.l


run: $(TARGET)
	./$(TARGET) code.c


clean:
ifeq ($(SHELL), CMD)
	del lex.yy.c *.tab.* code.txt $(TARGET).exe
else
	rm -f lex.yy.c *.tab.* code.txt $(TARGET)
endif
