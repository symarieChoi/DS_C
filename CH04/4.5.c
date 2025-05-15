#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
    element *data;
    int capacity;
    int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == s->capacity - 1);
}

void push(StackType *s, element item)
{
    if (is_full(s))
    { // 포화 상태이면
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element)); // 배열의 크기를 늘리고
    }
    s->data[++(s->top)] = item; // 삽입(if-else 문 사용하면 안 됨)
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

int main(void)
{
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    free(s.data);
    return 0;
}