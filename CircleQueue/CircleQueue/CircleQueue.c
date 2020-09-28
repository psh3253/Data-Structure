#include <stdio.h>
#define MAX_QUEUE_SIZE	100
typedef struct
{
	int key;
} element;
element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;

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
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (isFullQ())
		return;
	queue[rear] = item;
}

element deleteQ()
{
	element item;
	if (isEmptyQ())
		return;
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int main(void)
{
	return 0;
}