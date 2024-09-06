#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

typedef struct _stack
{
    int stack[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void Push(Stack *s, int data)
{
    if (s->top + 1 == MAX_SIZE)
    {
        return; // 스택 오버플로우 방지
    }
    s->stack[++(s->top)] = data;
}

int Pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->stack[(s->top)--];
}

int Top(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->stack[s->top];
}

int size(Stack *s)
{
    return s->top + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    Stack _s;
    InitStack(&_s);

    char command[10];
    int x;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            scanf("%d", &x);
            Push(&_s, x);
        }
        else if (strcmp(command, "pop") == 0)
        {
            printf("%d\n", Pop(&_s));
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size(&_s));
        }
        else if (strcmp(command, "empty") == 0)
        {
            printf("%d\n", isEmpty(&_s));
        }
        else if (strcmp(command, "top") == 0)
        {
            printf("%d\n", Top(&_s));
        }
    }

    return 0;
}
