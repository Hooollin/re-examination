#include <stdio.h>

void print(int num, int level)
{
    if (num == 0)
        return;
    print(num / 10, level + 1);
    printf("%d", num % 10);
    if (level != 0 && level % 3 == 0)
        printf(",");
}
void fun(int a, int b)
{
    int sum = a + b;
    if (sum == 0)
    {
        printf("0");
        return;
    }
    if (sum < 0)
    {
        printf("-");
        sum = -sum;
    }
    print(sum, 0);
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    fun(a, b);
    return 0;
}