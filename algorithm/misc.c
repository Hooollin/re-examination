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

/**
 * 合并两个有序数组A1，A2。A1中有足够的空间。
 * 像这种如果从前往后需要移动大量的数据，可以考虑从后往前。
 * 很强。
*/
int *mergeTwoSortedArray(int *A1, int *A2, int size1, int size2)
{
    int totalSize = size1 + size2;
    int idx = totalSize - 1, i = size1 - 1, j = size2 - 1;
    while (i >= 0 && j >= 0)
    {
        if (A1[i] > A2[j])
        {
            A1[idx--] = A1[i--];
        }
        else
        {
            A1[idx--] = A2[j--];
        }
    }
    while (i >= 0)
    {
        A1[idx--] = A1[i--];
    }
    while (j >= 0)
    {
        A1[idx--] = A2[j--];
    }
    return A1;
}
int main()
{
    //    srand(time(0));
    //int a = rand() % 100;
    //int b = rand() % 100;
    //printf("a=%d, b=%d, res=%d\n", a, b, gcd(a, b));
    //return 0;
    //  char *str = "I'm happy to know that";
    //char *repStr = "%20";
    //replace(str, ' ', repStr);
    //return 0;

    int A1[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, A2[10] = {1,
                                                            2,
                                                            3,
                                                            4,
                                                            5,
                                                            6,
                                                            7,
                                                            8,
                                                            9,
                                                            10};
    int *res = mergeTwoSortedArray(A1, A2, 10, 10);
    for (int i = 0; i < 20; i++)
    {
        printf("%d\t", res[i]);
    }
    return 0;
}