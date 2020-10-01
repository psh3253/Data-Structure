#include <stdio.h>
#include <stdlib.h>
int max_queue_size = 10;
int rear = 0;
int front = 0;

int isEmpty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int isFull()
{
	if ((rear + 1) % max_queue_size == front)
		return 1;
	else
		return 0;
}

int** queueFull(int** queue)
{
	max_queue_size *= 2;
	*queue = realloc(*queue, sizeof(int) * max_queue_size);
}

void add(int** queue, int item)
{
	if (isFull())
		queueFull(queue);
	rear = (rear + 1) % max_queue_size;
	(*queue)[rear] = item;
}

int delete(int** queue)
{
	if (isEmpty())
		return -1;
	else
	{
		front = (front + 1) % max_queue_size;
		return (*queue)[front];
	}
}

int main(void)
{
	int* queue = (int*)malloc(sizeof(int) * max_queue_size);
	add(&queue, 10);
	add(&queue, 20);
	add(&queue, 30);
	printf("%d\n", delete(&queue));
	printf("%d\n", delete(&queue));
	add(&queue, 40);
	printf("%d\n", delete(&queue));
	printf("%d\n", delete(&queue));
	free(queue);
	return 0;
}