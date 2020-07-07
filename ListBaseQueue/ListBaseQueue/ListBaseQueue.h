#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue
{
	Node* front;	// �׸��� ���ؼ� F�� ǥ���� ���
	Node* rear;	// �׸��� ���ؼ� R�̶� ǥ���� ���
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);	// enqueue ���� ��� �Լ�
Data Dequeue(Queue* pq);	// dequeue ���� ��� �Լ�
Data QPeek(Queue* pq);

#endif // !__LB_QUEUE_H__
