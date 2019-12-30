#include <stdio.h>
#include <stdlib.h>

int _max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    printf("This is a C program.\n");
    printf("//this is not a comment.\n");
    printf("/* this is not a comment block. */\n");
    srand((unsigned int)time(NULL));
    int a = rand();
    int b = rand();
    int sum = a + b;
    printf("a = %d, b = %d, a + b = %d. \n", a, b, sum);

    int ip1, ip2;
    scanf("%d %d", &ip1, &ip2);
    printf("ip1 = %d, ip2 = %d, maximum = %d.\n", ip1, ip2, _max(ip1, ip2));
    return 0;
}