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

// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
char *strcat(char *dest, const char *src);

// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
char *strncat(char *dest, const char *src, size_t n);

//在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。
char *strchr(const char *str, int c);

// 把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
int strcmp(const char *str1, const char *str2);

//把 str1 和 str2 进行比较，最多比较前 n 个字节。
int _strncmp(const char *str1, const char *str2, size_t n);

//把 str1 和 str2 进行比较，结果取决于 LC_COLLATE 的位置设置。
int strcoll(const char *str1, const char *str2);
#endif
