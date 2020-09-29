#include <stdio.h>
#define MAX_STACK_SIZE    10
int stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty()
{
	if (top < 0)
		return 1;
    else
        return 0;
}

int isFull()
{
	if (top >= MAX_STACK_SIZE - 1)
		return 1;
	else
        return 0;
}

void push(int item)
{
	if (isFull())
		return;
	else
        stack[++top] = item;
}

int pop()
{
	if (isEmpty())
		return -1;
	else
        return stack[top--];
}

int main(void)
{
    push(10);
    push(20);
    push(30);
    printf("%d\n", pop());
    printf("%d\n", pop());
    push(40);
    printf("%d\n", pop());
    printf("%d\n", pop());
	return 0;
}