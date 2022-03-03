#include <stdio.h>
#define MAX 50

typedef struct
{
    int data[MAX];
    int top;
} stack;

int push(int value, stack *s); // đặt là *s vì để có thể thay đổi top (vì đang truyền tham trị -> truyền tham chiếu)
int pop(int *topValue, stack *s);
int isEmpty(stack *s);
int isFull(stack *s);

int main(int count, char **args)
{
    // init myStack
    stack myStack;
    myStack.top = -1; // vì phần tử đầu tiên nếu stack là 0 nên cho  = -1 để biểu thị đang rỗng

    push(1, &myStack);
    push(2, &myStack);
    push(3, &myStack);
    push(4, &myStack);

    int top;
    while (pop(&top, &myStack))
    {
        printf("%d | ", top);
    }
    return 0;
}

int pop(int *topValue, stack *s)
{
    // Step 1:
    if (isEmpty(s))
    {
        // Step 2:
        return 0;
    }
    // Step 3:
    *topValue = s->data[s->top];
    // Step 4:
    s->top -= 1;
    // Step 5:
    return 1;
}

int push(int value, stack *s)
{
    // Step 1:
    if (isFull(s))
    {
        // Step 2:
        return 0;
    }
    // Step 3:
    s->top += 1;
    // Step 4:
    s->data[s->top] = value;
    // Step 5:
    return 1;
}

int isEmpty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *s)
{
    if (s->top == 49)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}