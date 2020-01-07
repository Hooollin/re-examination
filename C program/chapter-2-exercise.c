#include <stdio.h>

void dtox(int n)
{
    if (n == 0)
        return;
    dtox(n / 16);
    int t = n % 16;
    if (t >= 10)
        printf("%c", 'a' + t - 10);
    else
        printf("%d", t);
}

void dtoo(int n)
{
    if (n == 0)
    {
        return;
    }
    dtoo(n / 8);
    printf("%d", n % 8);
}

void dtob(int n)
{
    if (n == 0)
        return;
    dtob(n / 2);
    printf("%d", n % 2);
}

void fun2_1()
{
    int n = 200;
    dtox(n);
    printf("\n");
    dtoo(n);
    printf("\n");
    dtob(n);
    printf("\n");
}

void fun2_3()
{
    char c, d;
    c = 'd';
    d = c;
    printf("%d=%c", d);
}
void fun2_4()
{
    // 0x为十六进制 0开头为8进制
    int a = 0x1a, b = 0xb7, c = 022, d = 0xf91, e = 0x4444, f = 0621;
    // a = 0x1a = 00011010b = 2 + 8 + 16 = 26
    // c = 022 =  000010010b = 2 + 16 = 18
    // b = 0xb7 = 10110111b = 1 + 2 + 4 + 16 + 32 + 128 = 183
    // d = 0xf91= 111110010001b = 1 + 16 + 128 + 256 + 512 + 1024 + 2048 = 3985
    // e = 0x4444=0100010001000100b =
    printf("a=%d\tb=%d\tc=%x\td=%d\te=%d\tf=%d\t", a, b, c, d, e, f);
}

void fun2_5()
{
    char c, d, e;
    c = 'c';
    // char是按照ASCII码存储在计算机中的，故d为'd', e为'b'
    d = c + 1;
    e = c - 1;
    printf("d=%c\te=%c", d, e);
}

void fun2_6()
{
    char ch;
    scanf("%c", &ch);
    printf("%c %c", ch - 2, ch + 2);
}

void fun2_7()
{
    char ch = 'c';
    // 输出'c'的ASCII码以及c
    printf("%d%c\n", ch, ch);
}

void fun2_13()
{
    int x = 0;
    // 1!=2:1, 8<=10==1:0,(错了) <=优先级大于==; (3+4)==2:0, x!=!x:1
    printf("1!=2:%d\t8<=10==1:%d\tx=(3+4)==2:%d\tx!=!x:%d", 1 != 2, 8 <= 10 == 1, (3 + 4) == 2, x != !x);
    // 结果：1!=2:1  8<=10==1:1      x=(3+4)==2:0    x!=!x:1
}

void fun2_16()
{
    int a, b, c;
    // 先赋值了c = 8,再赋值b = 11, 最后赋值a = 4
    a = (b = (c = 8) + 3) - 7;
    printf("a=%d\tb=%d\tc=%d\t", a, b, c);
}

void fun2_17()
{
    int a = 0, b = 1;
    //==优先级高于&&和||，故先算b == a为0, &&高于||，故接着算a&&0为0，最后算0||b为1
    int res1 = a && b == a || b;
    printf("%d\n", res1);
    //==的优先级高于&，&的优先级高于|，故先算b == a为0，再算a & 0得0， 最后算0 | b得1
    int res2 = a & b == a | b;
    printf("%d\n", res2);
}
void fun2_18()
{
    short n;
    scanf("%d", &n);
    char hi_eight = n >> 8;
    char lo_eight = n;
    printf("0x%02x 0x%02x", hi_eight, lo_eight);
}

void fun2_19()
{
    int i = 0;
    unsigned int j = 0;
    // i是补码存储，取反后为1
    i = ~i;
    // j是无符号整型，取反后为2^31
    j = ~j;
    //这里输出是一样的，都为-1
    printf("~i=%d, ~j=%d", i, j);
}

int main()
{
    fun2_19();
    return 0;
}