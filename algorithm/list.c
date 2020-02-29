#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} LinkedList, ListNode;

LinkedList *buildLinkedList();
void append(LinkedList *head, int data);
void insertHead(LinkedList *head, int data);
void insert(LinkedList *head, ListNode *target, int data);
void idxInsert(LinkedList *head, int idx, int data);
int findIdx(LinkedList *head, int data);
ListNode *findNode(LinkedList *head, int data);
void printList(LinkedList *head);
void _swap(LinkedList *head, int val1, int val2);
void swap(LinkedList *head, ListNode *node1, ListNode *node2);
void sortList(LinkedList *head);

/**
 * 分割链表，大于x的放在前面，保证结点的相对顺序不变
 * 往后插入其实有点头疼，不过还是可取的，bug可能会出现在你通过是否到了tail来判断循环是否结束
 * 第二种方法是先分割两个链表，代码更简洁
 */
ListNode *partition(ListNode *head, int x)
{
    ListNode *curr = head, *tail = head->next, *next;
    int len = 1;
    for (; tail->next != NULL; tail = tail->next, len++)
        ;
    while (len-- > 0)
    {
        if (curr->next->data >= x)
        {
            next = curr->next->next;
            curr->next->next = NULL;
            tail->next = curr->next;
            curr->next = next;
            tail = tail->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

/**
 * 状态越来越好了
 * 链表的mergesort一次过，果然思路想清楚了就没有什么搞不对的了
 * 待优化
 */
ListNode *merge(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        return h1 == NULL ? h2 : h1;
    }
    else
    {
        if (h1->data > h2->data)
        {
            h2->next = merge(h1, h2->next);
            return h2;
        }
        else
        {
            h1->next = merge(h1->next, h2);
            return h1;
        }
    }
}

ListNode *mergeSort(ListNode *s, ListNode *t)
{
    if (s != t)
    {
        //printf("%d,%d\n", s->val, t->val  );
        ListNode *slow = s, *fast = s, *before = slow;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            before = slow;
            slow = slow->next;
        }
        if (fast != NULL)
        {
            ListNode *next = slow->next;
            slow->next = NULL;
            ListNode *lh = mergeSort(s, slow);
            ListNode *rh = mergeSort(next, t);
            return merge(lh, rh);
        }
        else
        {
            before->next = NULL;
            ListNode *lh = mergeSort(s, before);
            ListNode *rh = mergeSort(slow, t);
            return merge(lh, rh);
        }
    }
    else
    {
        return s;
    }
}

void sortList(ListNode *head)
{
    ListNode *tail;
    for (tail = head; tail->next != NULL; tail = tail->next)
        ;
    head->next = mergeSort(head->next, tail);
}

/**
 * 思路就是每次都把最大的元素冒泡到tail的位置，tail更新到前面一个结点，重复这个步骤
 * 注意如果curr与tail Swap过后，那么prev是有可能等于tail的。
 * curr != tail那么curr->next一定不为NULL，因为tail指向了最后一个元素
 * 在昨天的基础上优化了代码
 */
void listBubbleSort(LinkedList *head)
{
    // tail指向最后一个元素的位置
    ListNode *tail = head;
    for (; tail->next != NULL; tail = tail->next)
        ;
    ListNode *prev = head, *curr = head->next, *next;
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
}

/**
 * 通过值来找到Node并且交换两个Node
 * 不保证元素重复的时候交换的是你想象中的元素
 */
void _swap(LinkedList *head, int data1, int data2)
{
    ListNode *node1 = head->next, *node2 = head->next;
    for (; node1->data != data1; node1 = node1->next)
        ;
    for (; node2->data != data2; node2 = node2->next)
        ;
    swap(head, node1, node2);
}
/**
 * 没有头结点的swap要考虑是不是第一个结点，带头结点的就不用了
 * 同时要考虑两个结点是否相邻
 */
void swap(LinkedList *head, ListNode *node1, ListNode *node2)
{
    ListNode *prev1 = head, *curr1 = head->next, *prev2 = head, *curr2 = head->next, *next;
    for (; curr1 != node1; prev1 = prev1->next, curr1 = curr1->next)
        ;
    for (; curr2 != node2; prev2 = prev2->next, curr2 = curr2->next)
        ;
    if (curr1->next == curr2)
    {
        next = curr2->next;
        curr2->next = curr1;
        curr1->next = next;
        prev1->next = curr2;
    }
    else if (curr2->next == curr1)
    {
        next = curr1->next;
        curr1->next = curr2;
        curr2->next = next;
        prev2->next = curr1;
    }
    else
    {
        next = curr1->next;
        curr1->next = curr2->next;
        curr2->next = next;
        prev1->next = curr2;
        prev2->next = curr1;
    }
}
LinkedList *buildLinkedList()
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode)), *curr = head;
    head->data = 0;
    head->next = NULL;
    int data = -1;
    do
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->data = data;
        newNode->next = NULL;

        curr->next = newNode;
        curr = newNode;
    } while (1);
    return head;
}

void appendNode(LinkedList *head, ListNode *node)
{
    ListNode *last = head;
    for (; last->next != NULL; last = last->next)
        ;
    last->next = node;
}

void append(LinkedList *head, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    appendNode(head, newNode);
}

void insertNodeHead(LinkedList *head, ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    node->next = head->next;
    head->next = node;
}

void insertHead(LinkedList *head, int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = data;
    insertNodeHead(head, node);
}

void insertNode(LinkedList *head, LinkedList *target, ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    ListNode *prev = head, *curr = prev->next;
    for (; curr != target; prev = prev->next, curr = prev->next)
        ;
    node->next = target;
    prev->next = node;
}

void insert(LinkedList *head, ListNode *target, int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = data;
    insertNode(head, target, node);
}
/**
 * 通过下标插入数据
 * idx从0开始
 */
void idxInsert(LinkedList *head, int idx, int data)
{
    ListNode *curr = head->next;
    for (int i = idx; curr != NULL && i > 0; i--, curr = curr->next)
        ;
    insert(head, curr, data);
}

void delNode(LinkedList *head, ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    ListNode *prev = head, *curr = head->next;
    for (; curr != node && curr != NULL; prev = prev->next, curr = curr->next)
        ;
    if (curr != NULL)
    {
        prev->next = curr->next;
    }
    free(curr);
}

void valDel(ListNode *head, int val)
{
    ListNode *curr = head->next, *prev = head;
    //for循环无法删除curr后无法回退到之前的状态，while较为简单
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            delNode(head, curr);
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = prev->next;
        }
    }
}

int findIdx(LinkedList *head, int data)
{
    ListNode *curr = head->next;
    for (int i = 0; curr != NULL; i++, curr = curr->next)
    {
        if (curr->data == data)
        {
            return i;
        }
    }
    return -1;
}

ListNode *findNode(LinkedList *head, int data)
{
    ListNode *curr = head->next;
    for (; curr != NULL; curr = curr->next)
    {
        if (curr->data == data)
        {
            return curr;
        }
    }
    return NULL;
}

void printList(LinkedList *head)
{
    for (head = head->next; head != NULL; head = head->next)
    {
        printf("%4d->", head->data);
        //    if (head->next != NULL)
        //{
        //printf("->");
        //}
    }
    printf("NULL\n");
}

int main()
{
    LinkedList *head = buildLinkedList();
    printList(head);
    partition(head, 9);
    printList(head);
    return 0;
}
