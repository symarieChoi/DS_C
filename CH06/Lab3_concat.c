#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head)
{
    ListNode *p;
    for (p = head; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

ListNode *concat_list(ListNode *head1, ListNode *head2)
{
    ListNode *p = head1;
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    else
    {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

int main(void)
{
    ListNode *head1 = NULL, *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);

    ListNode* total = concat_list(head1, head2);
    print_list(total);

    return 0;
}