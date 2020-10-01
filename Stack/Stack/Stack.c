#include <stdio.h>
#include <stdlib.h>
int max_stack_size = 10;
int top = -1;

int isFull()
{
    if (top >= max_stack_size - 1)
        return 1;
    else
        return 0;
}

int** stackFull(int** stack)
{
    max_stack_size *= 2;
    *stack = realloc(*stack, sizeof(int) * max_stack_size);
    return stack;
}

int isEmpty()
{
	if (top < 0)
		return 1;
    else
        return 0;
}

void push(int** stack, int item)
{
    if (isFull())
        stack = stackFull(stack);
    (*stack)[++top] = item;
}

int pop(int** stack)
{
	if (isEmpty())
		return -1;
    else
        return (*stack)[top--];
}

int main(void)
{
    int* stack = (int*)malloc(sizeof(int) * max_stack_size);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    push(&stack, 40);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    free(stack);
	return 0;
}