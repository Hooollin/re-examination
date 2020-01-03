#include <stdio.h>

//AC
void Callatz(int n)
{
    int times = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = (3 * n + 1) / 2;
        }
        times += 1;
    }
    printf("%d", times);
}

int main()
{
    int n;
    scanf("%d", &n);
    Callatz(n);
}