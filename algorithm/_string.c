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
    const char *p = str;
    while (*str++)
        ;
    return str - p - 1;
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

void *memcpy(void *dest, const void *src, size_t n)
{
    const char *prt1 = src;
    char *prt2 = dest;
    size_t i = 0;
    for (; i < n; i++, prt1++, prt2++)
    {
        *prt2 = *prt1;
    }
    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    if (src >= dest || (char *)src + n < (char *)dest)
    {
        size_t i = 0;
        const char *prt1 = src;
        char *prt2 = dest;
        for (; i < n; i++, prt1++, prt2++)
        {
            *prt2 = *prt1;
        }
    }
    else
    {
        char *l = (char *)src + n;
        size_t len = ((char *)dest - (char *)src);
        while (l != (char *)src - 1)
        {
            *(l + len) = *l;
            l--;
        }
    }
    return dest;
}

void *memset(void *str, int c, size_t n)
{
    char *p = str;
    for (size_t i = 0; i < n; i++, *(p++) = c)
        ;
    return p;
}

char *strcat(char *dest, const char *src)
{
    char *prt = dest;
    for (; *prt; prt++)
        ;
    for (; *src; *prt++ = *src++)
        ;
    *prt = '\0';
    return dest;
}

int strcmp(const char *str1, const char *str2)
{
    for (; *str1 == *str2; ++str1, ++str2)
    {
        if (!*str1)
        {
            return 0;
        }
    }
    return *str1 > *str2 ? 1 : -1;
}

int _strncmp(const char *str1, const char *str2, size_t n)
{
    for (; n > 0 && *str1 == *str2; n--, str1++, str2++)
        ;
    if (n == 0)
    {
        return 0;
    }
    return *str1 > *str2 ? 1 : -1;
}

int main()
{
    char str1[10] = {"abc"};
    char str2[10] = {"ab"};
    size_t n = 5;
    int res = strlen(str1);
    printf("\n%d", res);
    return 0;
}