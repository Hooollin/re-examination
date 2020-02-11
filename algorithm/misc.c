#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

/**
 * 辗转相除法求最大公约数
 * 原理:https://blog.csdn.net/qq_30062589/article/details/79908321
 * 无需swap(a, b)；b是remain最后总归为0
*/
int gcd(int a, int b)
{
    while (b > 0)
    {
        int remain = a % b;
        a = b;
        b = remain;
    }
    return a;
}

int main()
{
    srand(time(0));
    int a = rand() % 100;
    int b = rand() % 100;
    printf("a=%d, b=%d, res=%d\n", a, b, gcd(a, b));
    return 0;
}