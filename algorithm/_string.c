#include <stdio.h>
#include <assert.h>
#include "_string.h"

void *memchr(const void *str, int c, size_t n)
{
    char *start = (char *)str;
    size_t i = 0;
    for (; i < n && *start != c; i++, start++)
        ;
    if (i == n)
    {
        return NULL;
    }
    return (void *)start;
}

size_t strlen(const char *str)
{
    size_t l = 0;
    for (; str[l] != '\0'; l++)
        ;
    return l;
}

int memcmp(const void *str1, const void *str2, size_t n)
{
    char *l1 = (char *)str1, *l2 = (char *)str2;
    for (size_t i = 0; i < n; i++, l1++, l2++)
    {
        if ((int)*l1 - (int)*l2 != 0)
        {
            return (int)*l1 - (int)*l2;
        }
    }
    return 0;
}

int main()
{
    char str1[10] = {"ello"};
    char str2[10] = {"ell1"};
    printf("%d", memcmp(str1, str2, 3));
    return 0;
}