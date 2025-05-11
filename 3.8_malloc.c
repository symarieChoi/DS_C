#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void)
{
    int *p;

    p = (int *)malloc(sizeof(int) * SIZE);
    if (p == NULL)
    {
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }

    for (int i = 0; i < SIZE; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;
}