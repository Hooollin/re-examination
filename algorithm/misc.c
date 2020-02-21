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
/**
 * 字符串双指针替换算法
 * 时间复杂度O(n)
 * 很牛逼
*/
void replace(char *str, char ch, char *repStr)
{
    int strLen = 0, repStrLen = 0, chFre = 0, newLen = 0;
    for (; str[strLen] != '\0'; strLen++)
    {
        if (str[strLen] == ch)
        {
            chFre++;
        }
    }

    for (; repStr[repStrLen] != '\0'; repStrLen++)
        ;
    newLen = strLen + chFre * repStrLen;
    char t[newLen + 1];
    int i = 0, j = 0;
    while (i < strLen)
    {
        if (str[i] == ch)
        {
            for (int k = 0; k < repStrLen; k++)
            {
                t[j++] = repStr[k];
            }
            i += 1;
        }
        else
        {
            t[j++] = str[i++];
        }
    }
    printf("%s", t);
}

int main()
{
    //    srand(time(0));
    //int a = rand() % 100;
    //int b = rand() % 100;
    //printf("a=%d, b=%d, res=%d\n", a, b, gcd(a, b));
    //return 0;
    char *str = "I'm happy to know that";
    char *repStr = "%20";
    replace(str, ' ', repStr);
    return 0;
}