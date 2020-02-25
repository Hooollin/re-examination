#ifndef __STRING_H_
#define __STRING_H_

//在参数 str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）匹配的指针.
void *memchr(const void *str, int c, size_t n);

//计算字符串 str 的长度，直到空结束字符，但不包括空结束字符。
size_t strlen(const char *str);

// 把 str1 和 str2 的前 n 个字节进行比较。
int memcmp(const void *str1, const void *str2, size_t n);

//从 src 复制 n 个字符到 dest，但是源和目的的内存区域不能重叠。
void *memcpy(void *dest, const void *src, size_t n);

//从 src 复制 n 个字符到 dest,源和目的的内存区域可以重叠。
void *memmove(void *dest, const void *src, size_t n);

//复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
void *memset(void *str, int c, size_t n);

#endif
