#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkList
{
    int val;
    struct LinkList *next;
} LinkList;

LinkList *head = NULL;
int num = 0;

LinkList *newLinkList(int value)
{
    // void *malloc(size_t size);
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->val = value;
    node->next = NULL;
    return node;
}

void add_node(int value)
{
    LinkList *node = newLinkList(value);
    if (head == NULL)
    // head指向新节点即可
    {
        head = node;
    }
    else
    {
        LinkList *cur = head;
        while (cur->next)
            cur = cur->next;
        // 新节点插入到cur的后面
        cur->next = node;
    }
    return;
}

void del_node(LinkList *n)
{
    if (n == head)
        head = head->next;
    else
    {
        for (LinkList *cur = head; cur != n && cur;)
        {

            LinkList *tmp = cur;
            cur = cur->next;
            if (cur == n)
                ;
            tmp = cur->next;
        }
    }
}

int modify_node(LinkList *n, int m_value)
{
    for (LinkList *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur == n)
            cur->val = m_value;
    }
}

void traverse_LL()
{
    for (LinkList *cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->val);
    }
    char s[] = "\n";
    printf(s);
}

int main()
{
    add_node(1);
    add_node(2);
    add_node(3);
    del_node(head);
    add_node(4);
    modify_node(head, 100);
    traverse_LL();
    return 0;
}
// 二叉树怎么写
