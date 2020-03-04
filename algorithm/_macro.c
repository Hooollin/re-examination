#include <stdio.h>

#define BEGIN {
#define END }
#define back return
#define start printf("executed on %s at %s, everything seems to be fine.\n", __DATE__, __TIME__)
#define print(x) printf(#x " = %lf\n", (x))
/* 可能会有副作用 */
#define max(x, y) ((x) > (y) ? (x) : (y))
#define GENERIC_MAX(type)           \
    type type##_max(type a, type b) \
    {                               \
        return a > b ? a : b;       \
    }
int main()
    BEGIN

    start;
/* 有副作用的max */
int sn = 21, bn = 20;
print(max(sn++, bn));
print(sn);
GENERIC_MAX(float);
print(float_max(20.0, 30.0));

back 0;
END
