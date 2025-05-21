#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_full(StackType *s)
{
    return s->top == MAX_STACK_SIZE - 1;
}

int is_empty(StackType *s)
{
    return s->top == -1;
}

void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int check_matching(const char *in)
{
    StackType *s; // 괄호를 저장할 스택
    s = (StackType *)malloc(sizeof(StackType));
    char ch, open_ch;
    int i, n = strlen(in); // n = 문자열의 길이
    init_stack(s);         // 스택의 초기화

    for (i = 0; i < n; i++)
    {
        ch = in[i]; // ch = 다음 문자
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(s, ch);
            break; // switch문 탈출
        case ')':
        case ']':
        case '}':
            if (is_empty(s)) // 스택이 비어 있는 경우
                return 0;
            else
            { // 스택이 비어 있지 않은 경우
                open_ch = pop(s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(s))
        return 0; // 스택에 남아있으면 오류(오른쪽 괄호가 없어 짝이 맞지 않는다는 의미)

    free(s);
    return 1;
}

int main(void)
{
    char *p = "{ A[(i+1)]=0; }";
    if (check_matching(p) == 1)
    {
        printf("%s 괄호 검사 성공\n", p);
    }
    else
    {
        printf("%s 괄호 검사 실패\n", p);
    }

    return 0;
}
