#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct QueueType
{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화 함수
void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

// 원형큐 출력 함수: 큐의 삽입과 삭제를 시각적으로 보여줌
void queue_print(QueueType *q)
{
    printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
    if (!is_empty(q))
    {
        int i = q->front; // i 변수: 원형 큐의 현재 상태를 출력하는 반복 변수
        do
        {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
            {
                break;
            }
        } while (i != q->front);
    }
    printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
    if (is_full(q))
    {
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 배열의 끝에 다다른 경우 0으로 증가시키기 위해 MAX_QUEUE_SIZE로 나눈 나머지를 취함
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
    if (is_empty(q))
    {
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 배열의 끝에 다다른 경우 0으로 증가시키기 위해 MAX_QUEUE_SIZE로 나눈 나머지를 취함
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
    {
        error("큐가 공백상태입니다");
    }
    return q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}

int main(void)
{
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue))
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다. \n\n");

    printf("--데이터 삭제 단계--\n");
    while (!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("꺼내진 정수: %d \n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}