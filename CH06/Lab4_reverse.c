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
    ListNode *p = (ListNode *)malloc((sizeof(ListNode)));
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

ListNode *reverse(ListNode *head)
{
    ListNode *p, *q, *r;

    p = head; // 역순으로 만들 리스트
    q = NULL; // 역순으로 만들 노드
    while (p != NULL)
    {
        r = q;       // 역순으로 된 리스트
                     // 역순으로 만들 노드 q를 가리킴
        q = p;       // q가 역순으로 만들 리스트의 첫 번째 노드를 가리킴
        p = p->link; // 역순으로 만들 노드의 다음 노드를 가리킴(역순으로 만들 리스트)
        q->link = r; // q의 링크 방향 바꾸기
    }
    return q;
}

int main(void)
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;
}