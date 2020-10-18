#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int[], int);
void swap(int*, int*);
void insertList(struct node**, int);
void printList(struct node*, int);
struct node* mergeList(struct node*, struct node*);
void listToArray(struct node*, int[], int);

// 노드
struct node
{
	int data;
	struct node* next;
};

// 메인 함수
int main(void)
{
	// 배열과 연결리스트 선언
	int arr1[20], arr2[20], arr3[40];
	int i;
	struct node* a = NULL, * b = NULL, * d = NULL, * temp = NULL;

	// 난수 시드 초기화
	srand(time(NULL));

	// 배열 A와 B에 정수를 랜덤으로 할당
	for (i = 0; i < 20; i++)
	{
		arr1[i] = (rand() % 1000) + 1;
		arr2[i] = (rand() % 1000) + 1;
	}

	// 배열 A와 B를 오름차순으로 정렬
	sort(arr1, 20);
	sort(arr2, 20);

	// 배열 A와 B의 요소들을 연결리스트 A와 B에 각각 삽입
	for (i = 0; i < 20; i++)
	{
		insertList(&a, arr1[i]);
		insertList(&b, arr2[i]);
	}

	// 연결리스트 A와 B를 출력
	printf("연결리스트 A : ");
	printList(a, 20);
	printf("\n연결리스트 B : ");
	printList(b, 20);

	// 연결리스트 A와 B를 합친후 임시 연결리스트에 저장
	temp = mergeList(a, b);

	// 임시 연결리스트를 임시 배열로 변환
	listToArray(temp, arr3, 40);

	// 임시 배열을 오름차순으로 정렬
	sort(arr3, 40);

	// 정렬된 임시배열을 연결리스트 D에 삽입
	for (i = 0; i < 40; i++)
	{
		insertList(&d, arr3[i]);
	}

	// 연결리스트 D를 출력
	printf("\n연결리스트 D : ");
	printList(d, 40);

	return 0;
}

// 배열을 오름차순으로 정렬
void sort(int list[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(&list[i], &list[min]);
	}
}

// 데이터 2개를 스왑
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 연결리스트에 데이터 삽입
void insertList(struct node** list, int data)
{
	// 리스트에 노드가 존재하지 않는다면
	if (*list == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = data;
		temp->next = NULL;
		*list = temp;
	}
	// 리스트에 노드가 존재한다면
	else
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		struct node* ptr = *list;
		temp->data = data;
		temp->next = NULL;
		// ptr을 연결리스트 끝까지 이동
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

// 연결리스트를 출력
void printList(struct node* list, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

// 연결리스트 2개를 합친 후 하나로 반환
struct node* mergeList(struct node* a, struct node* b)
{
	struct node* d = a;
	// a를 연결리스트 끝까지 이동
	while (a->next != NULL)
	{
		a = a->next;
	}
	a->next = b;
	return d;
}

// 연결리스트를 배열로 변환
void listToArray(struct node* list, int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		array[i] = list->data;
		list = list->next;
	}
}
