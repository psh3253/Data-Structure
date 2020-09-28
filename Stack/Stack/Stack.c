#include <stdio.h>
#define MAX_STACK_SIZE	100
typedef struct
{
	int key;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty()
{
	if (top < 0)
		return 1;
	return 0;
}

int isFull()
{
	if (top >= MAX_STACK_SIZE - 1)
		return 1;
	return 0;
}

void push(element item)
{
	if (isFull())
		return;
	stack[++top] = item;
}

element pop()
{
	if (isEmpty())
		return;
	return stack[top--];
}

int main(void)
{
	return 0;
}