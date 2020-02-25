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
int main()
{
    char str1[10] = {"hello"};
    char str2[10] = {""};
    memset(str1, 'a', 2);
    printf("%s", str1);
    return 0;
}