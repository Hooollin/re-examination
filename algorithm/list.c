#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} LinkedList, ListNode;

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
    idxInsert(head, 0, 10000);
    printList(head);
    return 0;
}
