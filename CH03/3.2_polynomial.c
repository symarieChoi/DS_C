#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // 조건 연산자: 조건 ? 조건이 참일 때 수행 : 조건이 거짓일 때 수행
#define MAX_DEGREE 101

typedef struct
{
    int degree;             // 다항식 차수
    float coef[MAX_DEGREE]; // 다항식 계수
} polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;                     // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if (degree_a > degree_b)
        { // A항 > B항
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b)
        { // A항 == B항
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else
        { // A항 < B항
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }

    return C;
}

void print_poly(polynomial p)
{
    for (int i = p.degree; i > 0; i--)
    {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("----------------------------------------------------------\n");
    print_poly(c);

    return 0;
}