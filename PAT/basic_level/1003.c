#include <stdio.h>

void valid(char *str)
{
    int index = 0;
    int hasP = 0, hasA = 0, valid = 0;
    char *curr = str;
    while (*curr != '\0')
    {
        if (*curr == 'P')
        {
            hasP = 1;
        }
        else if (*curr == 'A')
        {
            if (hasP)
                hasA = 1;
        }
        else if (*curr == 'T')
        {
            if (hasA)
            {
                valid = 1;
            }
        }
        else
        {
            printf("NO\n");
            return;
        }
        index += 1;
        curr += 1;
    }
    if (valid)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char str[100];
        scanf("%s", str);
        valid(str);
    }
    return 0;
}