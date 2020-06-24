#include <stdio.h>

int LSearch(int ar[], int len, int target)	// 순차 탐색 알고리즘 적용된 함수
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;	// 찾은 대상의 인덱스 값 반환
	}
	return -1;
}

int main(void)
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}