#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *next;
} LinkedList;

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} Node, ListNode;

void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

/**
 * 辗转相除法求最大公约数
 * 原理:https://blog.csdn.net/qq_30062589/article/details/79908321
 * 无需swap(a, b)；b是remain最后总归为0
*/
int gcd(int a, int b)
{
    while (b > 0)
    {
        int remain = a % b;
        a = b;
        b = remain;
    }
    return a;
}
/**
 * 字符串双指针替换算法
 * 时间复杂度O(n)
 * 很牛逼
*/
void replace(char *str, char ch, char *repStr)
{
    int strLen = 0, repStrLen = 0, chFre = 0, newLen = 0;
    for (; str[strLen] != '\0'; strLen++)
    {
        if (str[strLen] == ch)
        {
            chFre++;
        }
    }

    for (; repStr[repStrLen] != '\0'; repStrLen++)
        ;
    newLen = strLen + chFre * repStrLen;
    char t[newLen + 1];
    int i = 0, j = 0;
    while (i < strLen)
    {
        if (str[i] == ch)
        {
            for (int k = 0; k < repStrLen; k++)
            {
                t[j++] = repStr[k];
            }
            i += 1;
        }
        else
        {
            t[j++] = str[i++];
        }
    }
    printf("%s", t);
}

/**
 * 合并两个有序数组A1，A2。A1中有足够的空间。
 * 像这种如果从前往后需要移动大量的数据，可以考虑从后往前。
 * 很强。
*/
int *mergeTwoSortedArray(int *A1, int *A2, int size1, int size2)
{
    int totalSize = size1 + size2;
    int idx = totalSize - 1, i = size1 - 1, j = size2 - 1;
    while (i >= 0 && j >= 0)
    {
        if (A1[i] > A2[j])
        {
            A1[idx--] = A1[i--];
        }
        else
        {
            A1[idx--] = A2[j--];
        }
    }
    while (i >= 0)
    {
        A1[idx--] = A1[i--];
    }
    while (j >= 0)
    {
        A1[idx--] = A2[j--];
    }
    return A1;
}

/**
 * 筛选法求素数，感觉好玄幻啊
 * 偶数一定不是素数，素数的倍数一定不是素数，素数的因数小于sqrt(素数)
 * 原理：https://blog.csdn.net/qq_34739984/article/details/52999528?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
 * 🐂🍺
*/
void prime(int n)
{
    int *p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        p[i] = 0;
    }
    // 筛选出不是偶数的数
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0 && i != 2)
        {
            p[i] = 0;
        }
        else
        {
            p[i] = 1;
        }
    }

    for (int i = 3; i < sqrt(n); i++)
    {
        if (p[i] == 1)
        {
            for (int j = i + i; j < n; j += i)
            {
                p[j] = 0;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 1)
        {
            if (count++ % 10 == 0)
            {
                printf("\n");
            }
            printf("%d\t", i);
        }
    }
}
/**
 * 字符串交换算法。交换一下指向的地址就好了
*/
void swapStr(char *str1, char *str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
    printf("str1:%s,str2:%s", str1, str2);
}

/**
 * 约瑟夫环
 * n总人数，k报数，m是杀到剩下多少停止
 * 有点麻烦，建议考前再复习一下
 */
void ysfh(int n, int k, int m)
{
    int *remain = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        remain[i] = 0;
    }
    // i是有效的increment增量
    int count = 0, start = 0, i = 0;
    while (count < m)
    {
        i = 0;
        while (i < k - 1)
        {
            if (remain[start] == 0)
            {
                i++;
            }
            do
            {
                start = (start + 1) % n;
            } while (remain[start] == 1);
        }
        printf("%d\t", start);
        remain[start] = 1;
        count += 1;
    }
}
/**
 * 带佬的约瑟夫环
*/
int ysfdg(int sum, int value, int n)
{
    if (n == 1)
        return (sum + value - 1) % sum;
    else
        return (ysfdg(sum - 1, value, n - 1) + value) % sum;
}

/**
 * 快排求第k小，感觉很有可能考
 * 枯了，排序的时候lo < hi就可以，但是有lo == hi，就是说待排的空间大小只为1且必定为答案，这个时候需要返回而不是不处理...
 * 花了20分钟排坑
*/
int kthElement(int *arr, int lo, int hi, int k)
{
    if (lo <= hi)
    {
        int _lo = lo, _hi = hi;
        int key = arr[lo];
        while (lo < hi)
        {
            while (lo < hi && arr[hi] >= key)
            {
                hi--;
            }
            arr[lo] = arr[hi];
            while (lo < hi && arr[lo] < key)
            {
                lo++;
            }
            arr[hi] = arr[lo];
        }
        //printf("key:%d, lo:%d\n", key, lo);
        arr[lo] = key;
        //for (int i = 0; i < 10; i++)
        //{
        //printf("%d\t", arr[i]);
        //}
        //printf("\n");
        if (lo == k - 1)
        {
            //   printf("solution: %d = %d ?\n", lo, k - 1);
            return key;
        }
        else if (lo > k - 1)
        {
            return kthElement(arr, _lo, lo - 1, k);
        }
        return kthElement(arr, lo + 1, _hi, k);
    }
}

/**
 * 轻松改成迭代
 */
int _kthElement(int *arr, int lo, int hi, int k)
{
    while (lo <= hi)
    {
        int _lo = lo, _hi = hi;
        int key = arr[lo];
        while (lo < hi)
        {
            while (lo < hi && arr[hi] >= key)
            {
                hi--;
            }
            arr[lo] = arr[hi];
            while (lo < hi && arr[lo] < key)
            {
                lo++;
            }
            arr[hi] = arr[lo];
        }
        //printf("key:%d, lo:%d\n", key, lo);
        arr[lo] = key;
        //for (int i = 0; i < 10; i++)
        //{
        //printf("%d\t", arr[i]);
        //}
        //printf("\n");
        if (lo == k - 1)
        {
            //   printf("solution: %d = %d ?\n", lo, k - 1);
            return key;
        }
        else if (lo > k - 1)
        {
            hi = lo - 1;
            lo = _lo;
        }
        lo = lo + 1;
        hi = _hi;
    }
}
/**对于找第k大的进一步优化
 * 可以通过随机函数随机选取pivot，然后和lo处的元素交换，这样可以基本确保不发生O(n^2)的情况
 * 太强了
 */
int randint(int lo, int hi)
{
    return rand() % (hi - lo + 1) + lo;
}
int findKthLargest(int *nums, int numsSize, int k)
{
    srand(time(0));
    int lo = 0, hi = numsSize - 1;
    k = numsSize - k;
    while (lo <= hi)
    {
        int i = lo, j = hi;
        int pi = randint(i, j);
        if (pi != i)
        {
            swap(nums, pi, i);
        }
        int key = nums[i];
        while (i < j)
        {
            while (i < j && nums[j] >= key)
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] < key)
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = key;
        if (i == k)
        {
            return key;
        }
        else if (i > k)
        {
            hi = i - 1;
        }
        else
        {
            lo = i + 1;
        }
    }
    return -1;
}

/**
 * 将字符串的数字提取出来
 * 应该一遍遍历就好了吧
 * 🐂🍺，不过溢出就没办法了，不想用数组存储啦
 */
void getNumberFromStr(char *str)
{
    int idx = 0, sum = 0;
    for (; str[idx] != '\0'; idx++)
    {
        int t = str[idx] - '0';
        if (t >= 0 && t <= 9)
        {
            sum = sum * 10 + t;
        }
        else
        {
            if (sum > 0)
            {
                printf("%d\n", sum);
            }
            sum = 0;
        }
    }
    if (sum != 0)
    {
        printf("%d\n", sum);
    }
}

/**
 * 20个数据（整型+浮点），逆序输入到单链表中
 * 头插法
 */

void reverseBuildLinkedList()
{
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList)), *curr;
    head->next = NULL, curr = head->next;
    for (int i = 0; i < 3; i++)
    {
        float input;
        scanf("%f", &input);
        LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
        newNode->data = input;
        newNode->next = curr;
        head->next = newNode;
        curr = newNode;
    }
    curr = head->next;
    for (int i = 0; i < 3; i++)
    {
        printf("%f->", curr->data);
        curr = curr->next;
    }
}

/**
 * 逆序字符数组
 * 迭代或者递归实现，双指针
 */
void reverseStr(char *str)
{
    int len = 0;
    for (; str[len] != '\0'; len++)
        ;
    int start = 0, end = len - 1;
    while (start < end)
    {
        char t = str[start];
        str[start] = str[end];
        str[end] = t;
        start++, end--;
    }
    printf("%s", str);
}
// 这里只想到了能够怎么逆序输出
void _reverseStr(char *str, int i)
{
    if (i < 0)
    {
        return;
    }
    if (str[i] != '\0')
    {
        _reverseStr(str, i + 1);
    }
    printf("%c", str[i]);
}

/**
 * 比较两个字符串是否相等
 * 规则和string.h的strcmp一样
 * 很强
 */

int _strcmp(char *str1, char *str2)
{
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0' && str2[len2] != '\0')
    {
        if (str1[len1] != str2[len2])
        {
            return str1[len1] - str2[len2];
        }
        len1++;
        len2++;
    }
    if (str1[len1] != '\0')
    {
        return str1[len1];
    }
    if (str2[len2] != '\0')
    {
        return str2[len2];
    }
    return 0;
}

/**
 * 怎么理解这段代码
 * 首先--的优先级大于*，那么这里返回值为2
 * 关键是这里作为参数传入的地址不会因为++改变main函数里面的那个指针指向的地址
 */

int func(int *t)
{
    printf("%p\n", t);
    return (*t++ = 3) - 1;
}
/**
 * 去掉字符串中的字母数字和重复项
 * 最简单的思想是以空间换时间，并且需要避免移动大量的字符，那么可以通过维护一个插入pos来实现。
 * pos差点没想到...🐂🍺
 */
void delSpecifiedChars(char *str)
{
    int mem[128], len = 0, pos = 0;
    for (int i = 0; i < 128; i++)
    {
        mem[i] = 0;
    }
    for (; str[len] != '\0'; len++)
    {
        if (mem[str[len]] > 0 || str[len] >= '0' && str[len] <= '9' || str[len] >= 'a' && str[len] <= 'z' || str[len] >= 'A' && str[len] <= 'Z')
        {
            continue;
        }
        else
        {
            str[pos++] = str[len];
            mem[str[len]]++;
        }
    }
    str[pos] = '\0';
    printf("%s", str);
}
/**
 * 删除有序数组中的重复项
 * 从上个算法题以及自己之前的惨痛教训的出来的经验
 * 希望自己以后不要忘记
 */
void delDup(int *arr, int size)
{
    int pos = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[pos++] = arr[i];
        }
    }
    for (int i = 0; i < pos; i++)
    {
        printf("%d\t", arr[i]);
    }
}

/**
 * 单链表的bubblesort
 * 还是太菜了 搞得头疼
 * shit code
 * 思路就是每次都把最大的元素冒泡到tail的位置，tail更新到前面一个结点，重复这个步骤
 * 注意如果curr与tail Swap过后，那么prev是有可能等于tail的。
 * curr != tail那么curr->next一定不为NULL，因为tail指向了最后一个元素
 * 在昨天的基础上优化了代码
 */
void listBubbleSort(LinkedList *head)
{
    // tail指向最后一个元素的位置
    LinkedList *tail = head;
    for (; tail->next != NULL; tail = tail->next)
        ;
    LinkedList *prev = head, *curr = head->next, *next;
    while (curr != NULL && curr != tail)
    {
        for (; prev != tail && curr != tail; prev = prev->next, curr = prev->next)
        {
            if (curr->data > curr->next->data)
            {
                next = curr->next;
                curr->next = next->next;
                next->next = curr;
                prev->next = next;
            }
        }
        tail = prev;
        prev = head;
        curr = head->next;
    }
    for (curr = head->next; curr != NULL; curr = curr->next)
    {
        printf("%d->", curr->data);
    }
}
/**
 * 选择排序的链表实现方式
 */
void listSelectionSort(LinkedList *head)
{
}

/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 简单思路：搞一个哈希表，时间复杂度O(n)
 * 带佬思路：利用XOR的性质：a^a=0,a^0=a。因此有 a ^ b ^ a = b;
 */
void singleNumber(int *arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res ^= arr[i];
    }
    printf("%d", res);
}

/**
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 很简单实现一下
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    Node *res = (Node *)malloc(sizeof(Node)), *curr1 = l1, *curr2 = l2, *curr = res;
    res->next = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->val > curr2->val)
        {
            curr->next = curr2;
            curr = curr2;
            curr2 = curr2->next;
        }
        else
        {
            curr->next = curr1;
            curr = curr1;
            curr1 = curr1->next;
        }
        curr->next = NULL;
    }
    if (curr1 != NULL)
    {
        curr->next = curr1;
    }
    else
    {
        curr->next = curr2;
    }
    return res->next;
}

/**
 * 递归版本
 */
struct ListNode *_mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return l1 == NULL ? l2 : l1;
    }
    if (l1->val > l2->val)
    {
        l2->next = _mergeTwoLists(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = _mergeTwoLists(l1->next, l2);
        return l1;
    }
}

/**
 * https://leetcode-cn.com/problems/next-greater-node-in-linked-list/solution/
 * 单调栈
 * 动态规划也可以接受
 * 🐂🍺
 */
int *nextLargerNodes(ListNode *head, int *returnSize)
{
    int len = 0, top = -1;
    ListNode *prev = NULL, *curr = head, *n;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
        len++;
    }
    *returnSize = len;
    int *res = (int *)malloc(sizeof(ListNode) * len);
    for (int i = 0; i < len; i++)
    {
        res[i] = 0;
    }
    curr = prev;
    ListNode *s[len];
    len -= 1;
    while (curr != NULL)
    {
        for (; top > -1; top--)
        {
            if (s[top]->val > curr->val)
            {
                res[len--] = s[top]->val;
                break;
            }
        }
        if (top == -1)
        {
            res[len--] = 0;
        }
        s[++top] = curr;
        curr = curr->next;
    }
    return res;
}
/**
 * 找众数
 * 保证众数存在
 * 保证数组不为空
 * 摩尔投票
 */
void mostAppearanceNumber(int *nums, int size)
{
    int res = nums[0], count = 1;
    for (int i = 1; i < size; i++)
    {
        if (count == 0)
        {
            res = nums[i];
        }

        if (nums[i] == res)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    printf("%d", res);
}
char digitToHexChar(int digit)
{
    return "0123456789ABCDEF"[digit];
}
int main()
{
    //    srand(time(0));
    //int a = rand() % 100;
    //int b = rand() % 100;
    //printf("a=%d, b=%d, res=%d\n", a, b, gcd(a, b));
    //return 0;
    //  char *str = "I'm happy to know that";
    //char *repStr = "%20";
    //replace(str, ' ', repStr);
    //return 0;

    //    int A1[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, A2[10] = {1,
    //2,
    //3,
    //4,
    //5,
    //6,
    //7,
    //8,
    //9,
    //10};
    //int *res = mergeTwoSortedArray(A1, A2, 10, 10);
    //for (int i = 0; i < 20; i++)
    //{
    //printf("%d\t", res[i]);
    //}
    //return 0;

    // prime(100);
    //return 0;

    //swapStr("hello", "world");
    //return 0;

    //ysfh(30, 9, 15);

    //int k = 1;
    //scanf("%d", &k);
    //int arr[10] = {3, 2, 1, 5, 4, 6, 9, 8, 7, 10};
    //printf("%d\n", _kthElement(arr, 0, 9, k));
    //for (int i = 0; i < 10; i++)
    //{
    //printf("%d\t", arr[i]);
    //}

    //getNumberFromStr("uestc23242hel21223lo1232hei233");

    //reverseBuildLinkedList();
    //char str[20] = {"helloworld"};
    //reverseStr(str);
    //printf("%d", _strcmp("hello", "hello"));
    //char str[20] = "hz..,,12321,,,*&#@&#";
    //delSpecifiedChars(str);

    //int arr[10] = {2, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    //delDup(arr, 10);

    //    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList)), *curr = head;
    //for (int i = 5; i > 0; i--)
    //{
    //LinkedList *t = (LinkedList *)malloc(sizeof(LinkedList));
    //t->data = i;
    //t->next = NULL;
    //curr->next = t;
    //curr = t;
    //}
    //listBubbleSort(head);

    // int arr[10] = {1, 2, 3, 2, 2, 3, 3, 2, 2, 3};
    //mostAppearanceNumber(arr, 10);

    for (int i = 0; i < 16; i++)
    {
        printf("%c", digitToHexChar(i));
    }
}