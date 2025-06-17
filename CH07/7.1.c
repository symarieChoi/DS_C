#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode *head)
{
    ListNode *p;

    if (head == NULL)
        return;
    p = head->link; // head는 마지막 노드를 가리키고 있음
    do
    {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("%d -> ", p->data); // 마지막 노드 출력
}

ListNode *insert_first(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode *insert_last(ListNode *head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int main(void)
{
    ListNode *head = NULL;

    // list = 10 -> 20 -> 30 -> 40
    head = insert_last(head, 20); // insert_last()가 반환한 헤드 포인터를 head에 대입
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);

    return 0;
}