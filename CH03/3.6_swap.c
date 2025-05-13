#include <stdio.h>

void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main(void)
{
    int a = 1, b = 2;
    printf("swap을 호출하기 전: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("swap 호출 후: a = %d, b = %d\n", a, b);
    return 0;
}