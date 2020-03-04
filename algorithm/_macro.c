#include <stdio.h>

#define BEGIN {
#define END }
#define back return
#define start printf("executed on %s at %s, everything seems to be fine.\n", __DATE__, __TIME__)
int main()
    BEGIN
    start;
back 0;
END
