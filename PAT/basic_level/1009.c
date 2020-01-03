#include <stdio.h>
#include <string.h>
void reversePrintWord(char *str)
{
    char *tail = strchr(str, ' ');
    if (tail == NULL)
    {
        printf("%s", str);
        return;
    }
    reversePrintWord(tail + 1);
    *tail = '\0';
    printf(" %s", str);
}

int main()
{
    char str[80];
    gets(str);
    printf("%s\n", str);
    reversePrintWord(str);
}