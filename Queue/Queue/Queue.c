#include <stdio.h>
#define MAX_QUEUE_SIZE	10
int queue[MAX_QUEUE_SIZE];
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

void addQ(int item)
{
	if (isFullQ)
		return;
	queue[++rear] = item;
}

int deleteQ()
{
	if (isEmptyQ)
		return;
	return queue[++front];
}

int main(void)
{
	return 0;
}