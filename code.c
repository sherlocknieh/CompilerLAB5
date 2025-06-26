/* function */
int main()
{
    /* decls */
    float price;
    char ch;
    int i;
    int sum;

    /* stmts */
    /* 赋值语句 */
    price = 3.54;
    ch = 'B';
    i = -2;
    sum = 0;

    /* 表达式 */
    price = price - i;
    sum = sum + (i * price);
    ch = ch + i;

    /* 控制流 */
    while (i <= 100)
    {
        int j;
        j = 5;
        sum = sum + j;
        if (i < 50)
            i = i + 2;
        else
            i = i + 3;
    }
}