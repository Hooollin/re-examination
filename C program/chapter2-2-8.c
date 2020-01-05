#include <stdio.h>

int main()
{
    int x = 1, y = 0;
    printf("%d\t", !x && y);   // 先!x再&& 0&&0 = 0，输出0
    printf("%d\t", !(x && y)); // 先括号内的x&&y = 0再取非得1
    int z;
    printf("%d\t", z = x * x == y); // 先算乘法x * x = 1，从右往左可以得x == y为0，z = 0,输出0
    int w;
    printf("%d\t", w = x == y != z); //从右往左计算得 z != y结果为0，x == 0结果为0，w结果为0, 输出0
    return 0;
}