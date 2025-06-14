#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5
typedef int element;
typedef struct
{
    element data[MAX_DEQUE_SIZE];
    int front, rear;
} DequeType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *q)
{
    q->front = q->rear = 0;
}

int is_empty(DequeType *q)
{
    return (q->front == q->rear);
}

int is_full(DequeType *q)
{
    return (q->front == (q->rear + 1) % MAX_DEQUE_SIZE);
}

void deque_print(DequeType *q)
{
    printf("DEQUE = (front = %d rear = %d) = ", q->front, q->rear);
    if (!is_empty(q))
    {
        int i = q->front;
        do
        {
            i = (i + 1) % MAX_DEQUE_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
            {
                break;
            }
        } while (i != q->front);
    }
    printf("\n");
}

void add_rear(DequeType *q, element item) // enqueue
{
    if (is_full(q))
    {
        error("큐 포화 에러");
    }
    q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(DequeType *q) // dequeue
{
    if (is_empty(q))
    {
        error("큐 공백 에러");
    }
    q->front = (q->front + 1) % MAX_DEQUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q)
{
    if (is_empty(q))
    {
        error("큐 공백 에러");
    }
    return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}

void add_front(DequeType *q, element val)
{
    if (is_full(q))
    {
        error("큐 포화 에러");
    }
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element delete_rear(DequeType *q)
{
    if (is_empty(q))
    {
        error("큐 공백 에러");
    }
    q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return q->data[q->rear];
}

element get_rear(DequeType *q)
{
    if (is_empty(q))
    {
        error("큐 공백 에러");
    }
    return q->data[q->rear];
}

int main(void)
{
    DequeType queue;

    init_deque(&queue);
    for (int i = 0; i < 3; i++)
    {
        add_front(&queue, i);
        deque_print(&queue);
    }
    for (int i = 0; i < 3; i++)
    {
        delete_rear(&queue);
        deque_print(&queue);
    }

    return 0;
}