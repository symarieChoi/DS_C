#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct StackType
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == MAX_STACK_SIZE - 1);
}

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

int prec(char op)
{
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]) // 혹은 char* exp
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for (i = 0; i < len; i++)
    {
        ch = exp[i]; // 처리할 다음 문자 저장
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':                                               // 연산자 처리
            while (!is_empty(&s) && prec(ch) <= prec(peek(&s))) // 스택에 있는 연산자의 우선순위가 더 크거나 같으면
            {
                printf("%c", pop(&s)); // 스택 상단 연산자 출력
            }
            push(&s, ch); // 현재 처리 중인 연산자 스택에 삽입
            break;        // switch문 탈출(다음 문자 처리 시작)
        case '(':
            push(&s, ch); // 왼쪽 괄호는 무조건 스택에 삽입
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(') // 왼쪽 괄호를 만날 때까지
            {
                printf("%c", top_op); // 스택의 연산자 pop -> 출력력
                top_op = pop(&s);
            }
            break;
        default: // 피연산자
            printf("%c", ch);
            break;
        }
    }

    while (!is_empty(&s)) // 스택에 남은 연산자 처리
    {
        printf("%c", pop(&s));
    }
}

int main(void)
{
    char *s = "(2+3)*4+9";
    printf("중위표기수식 %s\n", s);
    printf("후위표기수식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}