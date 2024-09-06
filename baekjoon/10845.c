#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

typedef struct _queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;
} Q;

void InitQueue(Q *q)
{
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Q *q)
{
    return (q->front == q->rear) ? 1 : 0;
}

void Push(Q *q, int data)
{
    q->queue[q->rear++] = data;
}

int Pop(Q *q)
{
    return isEmpty(q) ? -1 : q->queue[q->front++];
}

int size(Q *q)
{
    return q->rear - q->front;
}

int Front(Q *q)
{
    return isEmpty(q) ? -1 : q->queue[q->front];
}

int Back(Q *q)
{
    return isEmpty(q) ? -1 : q->queue[q->rear - 1];
}

int main()
{
    int n;
    scanf("%d", &n);

    Q q;
    InitQueue(&q);

    char command[10];
    int x;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &x);
            Push(&q, x);
        }
        else if (strcmp(command, "pop") == 0)
        {
            printf("%d\n", Pop(&q));
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size(&q));
        }
        else if (strcmp(command, "empty") == 0)
        {
            printf("%d\n", isEmpty(&q));
        }
        else if (strcmp(command, "front") == 0)
        {
            printf("%d\n", Front(&q));
        }
        else if (strcmp(command, "back") == 0)
        {
            printf("%d\n", Back(&q));
        }
    }
    return 0;
}