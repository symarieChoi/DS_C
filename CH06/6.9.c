#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode // 노드 타입
{
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType // 헤더 타입
{
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 헤더 생성 함수
ListType *create()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon은 지수
void insert_last(ListType *plist, int coef, int expon)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL)
    {
        error("메모리 할당 에러");
    }
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) // tail이 NULL이면 연결 리스트가 존재하지 않는다는 의미
    {
        plist->head = plist->tail = temp;
    }
    else
    {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

// list3 = list2 + list1
void poly_add(ListType *plist1, ListType *plist2, ListType *plist3)
{
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;

    while (a && b)
    {
        if (a->expon == b->expon) // a의 차수와 b의 차수가 같은 경우
        {
            sum = a->coef + b->coef;
            if (sum != 0)
            {
                insert_last(plist3, sum, a->expon);
            }
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon) // a의 차수가 b의 차수보다 큰 경우
        {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else
        {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    // a나 b 중 하나가 먼저 끝나게 되면 남은 항들을 모두 결과 다항식으로 복사
    for (a; a != NULL; a = a->link)
    {
        insert_last(plist3, a->coef, a->expon);
    }
    for (b; b != NULL; b = b->link)
    {
        insert_last(plist3, b->coef, b->expon);
    }
}

void poly_print(ListType *plist)
{
    ListNode *p = plist->head;

    printf("polynomial = ");
    for (p; p != NULL; p = p->link)
    {
        printf("%dx^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int main(void)
{
    ListType *list1, *list2, *list3;

    // 연결 리스트 헤더 생성
    list1 = create();
    list2 = create();
    list3 = create();

    // 다항식 1 생성
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    // 다항식 2 생성
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    // 다항식 3 = 다항식 1 + 다항식 2
    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1);
    free(list2);
    free(list3);

    return 0;
}