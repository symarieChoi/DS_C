#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element item)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = item;
    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    node->link = head->link;
    head->link = node;

    return head;
}

int main(void)
{
    ListNode *head = NULL;

    head = insert_first(head, "KIM");
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");

    ListNode *p = head;
    for (int i = 0; i < 10; i++)
    {
        printf("현재 차례 = %s\n", p->data);
        p = p->link;
    }

    return 0;
}