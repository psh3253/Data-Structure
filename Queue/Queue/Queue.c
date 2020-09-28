#include <stdio.h>
#define MAX_QUEUE_SIZE	100
typedef struct
{
	int key;
} element;
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

int isEmptyQ()
{
	if (front == rear)
		return 1;
	return 0;
}

int isFullQ()
{
	if (rear == MAX_QUEUE_SIZE - 1)
		return 1;
	return 0;
}

void addQ(element item)
{
	if (isFullQ)
		return;
	queue[++rear] = item;
}

element deleteQ()
{
	if (isEmptyQ)
		return;
	return queue[++front];
}

int main(void)
{
	return 0;
}