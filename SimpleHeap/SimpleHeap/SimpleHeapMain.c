#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);	// ���� �ʱ�ȭ

	HInsert(&heap, 'A', 1);	// ���� 'A'�� �ְ��� �켱������ ����
	HInsert(&heap, 'B', 2);	// ���� 'B'�� �� ��° �켱������ ����
	HInsert(&heap, 'C', 3);	// ���� 'C'�� �� ��° �켱������ ����
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);	// ���� 'A' �� �� �� ����!
	HInsert(&heap, 'B', 2);	// ���� 'B' �� �� �� ����!
	HInsert(&heap, 'C', 3);	// ���� 'C' �� �� �� ����!
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}