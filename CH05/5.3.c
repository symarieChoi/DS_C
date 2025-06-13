#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct
{
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
    {
        error("공백 포화 오류");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
    {
        error("큐 공백 오류");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void queue_print(QueueType *q)
{
    printf("QUEUE = (front = %d rear = %d) = ", q->front, q->rear);
    if (!is_empty(q))
    {
        int i = q->front;
        do
        {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
            {
                break;
            }
        } while (i != q->front);
        printf("\n");
    }
}

int main(void)
{
    QueueType queue;

    init_queue(&queue);
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        if (rand() % 5 == 0) // 5로 나누어 떨어지면
        {
            enqueue(&queue, rand() % 100); // 0~99 범위 안의 난수
        }
        queue_print(&queue);
        if (rand() % 10 == 0) // 10으로 나누어 떨어지면
        {
            int delete = dequeue(&queue);
            printf("delete: %d\n", delete);
        }
        queue_print(&queue);
    }

    return 0;
}
