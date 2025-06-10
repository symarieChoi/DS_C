#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct
{
    short r;
    short c;
} element;

typedef struct StackType
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

element here = {1, 0};
element entry = {1, 0};
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}};

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
    return (s->top == MAX_STACK_SIZE);
}

void push(StackType *s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++s->top] = item;
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->data[s->top--];
}

// 위치를 스택에 삽입
void push_loc(StackType *s, int r, int c)
{
    if (r < 0 || c < 0) // 존재하지 않는 위치
        return;
    if (maze[r][c] != '1' && maze[r][c] != '.') // 벽이 아니고 방문하지 않았다면
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

// 미로를 화면에 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++)
    {
        for (int c = 0; c < MAZE_SIZE; c++)
        {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void)
{
    int r, c;
    StackType s;

    init_stack(&s);
    here = entry;                       // 현재 위치 = 입구 위치
    while (maze[here.r][here.c] != 'x') // 현재 위치가 출구가 아닌 동안
    {
        r = here.r;             // 현재 위치의 행 위치를 r에 저장
        c = here.c;             // 현재 위치의 열 위치를 c에 저장
        maze[r][c] = '.';       // 해당 위치(현재 위치)를 방문했음을 표시
        maze_print(maze);       // 미로 출력
        push_loc(&s, r - 1, c); // 위치를 스택에 삽입(현재 위치 위)
        push_loc(&s, r + 1, c); // 위치를 스택에 삽입(현재 위치 아래)
        push_loc(&s, r, c - 1); // 위치를 스택에 삽입(현재 위치 왼쪽)
        push_loc(&s, r, c + 1); // 위치를 스택에 삽입(현재 위치 오른쪽)

        if (is_empty(&s)) // 스택이 비어 있는데 출구를 찾지 못했다면(출구를 찾지 못함 == while문 조건건)
        {
            printf("실패\n"); // 실패
            return 1;
        }
        else
            here = pop(&s); // 스택의 상단 위치로 이동동
    }
    printf("성공\n");

    return 0;
}