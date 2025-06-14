#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct
{
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_list(ArrayListType *L)
{
    L->size = 0;
}

int is_empty(ArrayListType *L)
{
    return (L->size == 0);
}

int is_full(ArrayListType *L)
{
    return (L->size == MAX_LIST_SIZE);
}

// pos 위치의 요소 반환
int get_entry(ArrayListType *L, int pos)
{
    if (pos < 0 || pos >= L->size)
    { // 현재 값이 저장되어 있는 위치 범위 안에서만 반환해야 하므로
        error("위치 오류");
    }
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType *L)
{
    int i;
    for (i = 0; i < L->size; i++)
    {
        printf("%d -> ", L->array[i]);
    }
    printf("\n");
}

// 마지막 자리에 요소 삽입
void insert_last(ArrayListType *L, element item)
{
    if (L->size >= MAX_LIST_SIZE)
    {
        error("리스트 오버플로우");
    }
    L->array[L->size++] = item;
}

// pos 위치에 요소 삽입
void insert(ArrayListType *L, element item, int pos)
{
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) // L->size 위치에도 값이 저장될 수 있음
    {
        for (int i = L->size - 1; i >= pos; i--)
        {
            L->array[i + 1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

// 항목 삭제 연산
element delete(ArrayListType *L, int pos)
{
    element item;

    if (pos < 0 || pos >= L->size)
    {
        error("위치 오류");
    }

    item = L->array[pos];
    for (int i = pos; i < L->size; i++)
    {
        L->array[i] = L->array[i + 1];
    }
    L->size--;

    return item;
}

int main(void)
{
    // ArrayListType을 정적으로 생성하고 ArrayListType을 가리키는 포인터를 함수의 매개변수로 전달
    ArrayListType list;

    init_list(&list);
    insert(&list, 10, 0);
    print_list(&list);
    insert(&list, 20, 0);
    print_list(&list);
    insert(&list, 30, 0);
    print_list(&list);
    insert_last(&list, 40);
    print_list(&list);
    delete(&list, 0);
    print_list(&list);

    return 0;
}