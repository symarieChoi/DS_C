#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode // 이중연결 노드 타입
{
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode *phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode *phead, DListNode *current)
{
    DListNode *p;
    for (p = phead->rlink; p != phead; p = p->rlink)
    {
        if (p == current)
        {
            printf("<- |#%s#| ->", p->data);
        }
        else
        {
            printf("<- |%s| ->", p->data);
        }
    }
    printf("\n");
}

// 노드 newnode를 노드 before의 오른쪽쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    strcpy(newnode->data, data);
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DListNode *head, DListNode *removed)
{
    if (removed == head)
    {
        return;
    }
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void)
{
    char ch;
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    DListNode *current = head->rlink;
    print_dlist(head, current);

    do
    {
        printf("\n명령어를 입력하시오(<, >, q): ");
        ch = getchar();

        if (ch == '<')
        {
            current = current->llink;
            if (current == head)
            {
                current = current->llink;
            }
        }
        else if (ch == '>')
        {
            current = current->rlink;
            if (current == head)
            {
                current = current->rlink;
            }
        }
        print_dlist(head, current);
        getchar(); // 사용자가 입력한 문자 뒤에 남아 있는 '\n' 제거
    } while (ch != 'q');

    free(head);

    return 0;
}