#include <stdio.h>
#include <stdlib.h>

// 스택 코드 시작
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1; // top만 -1면 스택이 빈 것으로 간주함
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == MAX_STACK_SIZE - 1);
}

// 삽입 함수
void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

// 삭제 함수
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

// 피크 함수
element peek(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[s->top];
}

int main(void)
{
    StackType s; // 스택 정적으로 생성하기

    init_stack(&s);
    push(&s, 1); // 함수 호출 시 스택의 주소 전달
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}