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
    _swap(head, 10, 20);
    printList(head);
    return 0;
}
