#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

int push(Stack *stack, int value);

int main(int argc, char const *argv[])
{
    Stack stack;
    stack.top = -1;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        stack.data[i] = rand() % 101;
        push(&stack, stack.data[i]);
    }

    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d | ", stack.data[i]);
    }

    return 0;
}

int push(Stack *stack, int value)
{
    if (stack->top == MAX - 1)
    {
        return 0;
    }
    stack->data[stack->top += 1] = value;
    return 1;
}