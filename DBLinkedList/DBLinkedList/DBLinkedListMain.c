#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// 리스트의 생성 및 초기화 ///////
	List list;
	int data;
	ListInit(&list);

	// 8개의 데이터 저장 ///////
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// 저장된 데이터의 전체 출력 ///////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// 오른쪽 노드로 이동하며 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		// 왼쪽 노드로 이동하며 데이터 조회
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}