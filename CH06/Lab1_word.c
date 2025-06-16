#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
} element;

typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode *insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value; // p->data의 타입 element, value 타입 element, p->data.name의 타입 char --> p->data.name = value (X)
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%s -> ", p->data.name);
    }
    printf("NULL\n");
}

int main(void)
{
    ListNode *head = NULL;
    element item;

    strcpy(item.name, "APPLE");
    head = insert_first(head, item);
    print_list(head);

    strcpy(item.name, "KIWI");
    head = insert_first(head, item);
    print_list(head);

    strcpy(item.name, "BANANA");
    head = insert_first(head, item);
    print_list(head);

    return 0;
}