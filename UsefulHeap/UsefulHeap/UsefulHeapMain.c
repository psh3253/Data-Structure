#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2)	// �켱���� ���Լ�
{
	return ch2 - ch1;
//	reutnr ch1 - ch2;
}
int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);	// ���� �ʱ�ȭ

	HInsert(&heap, 'A');	// ���� 'A'�� �ְ��� �켱������ ����
	HInsert(&heap, 'B');	// ���� 'B'�� �� ��° �켱������ ����
	HInsert(&heap, 'C');	// ���� 'C'�� �� ��° �켱������ ����
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');	// ���� 'A' �� �� �� ����!
	HInsert(&heap, 'B');	// ���� 'B' �� �� �� ����!
	HInsert(&heap, 'C');	// ���� 'C' �� �� �� ����!
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}