#include <stdio.h>

int main()
{
    short num;
    scanf("%d", &num);
    printf("Before: 0x%04x\n", num);
    short t = num >> 8;
    short k = num << 8;
    printf("After:  0x%04x\n", t | k);
    return 0;
}