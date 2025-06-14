#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
typedef struct
{
    int id;
    int arrival_time;
    int service_time;
} element;

typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
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
        error("큐 포화 에러");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
    {
        error("큐 공백 에러");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void)
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0; // 방문한 총 고객 수 count(고객 number)
    int service_time = 0;
    int service_customer;
    QueueType queue;
    init_queue(&queue);

    srand(time(NULL));
    for (int clock = 0; clock < minutes; clock++)
    {
        printf("현재시각 = %d\n", clock);
        if ((rand() % 10) < 3) // 새로운 고객이 들어온 경우: 난수가 3보다 작으면 새로운 고객이 들어왔다고 판단
        {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1;
            enqueue(&queue, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) // 현재 처리 중인 고객의 업무 처리 시간을 보여줌
        {
            printf("고객 %d 업무처리중입니다.\n", service_customer);
            service_time--;
        }
        else // 처리해야할 고객의 업무 시작 시간과 대기시간을 보여줌
        {
            if (!is_empty(&queue))
            {
                element customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
                       customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("전체 대기 시간 = %d분\n", total_wait);
    return 0;
}