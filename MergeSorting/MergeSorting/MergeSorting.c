#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int[], int);
void swap(int*, int*);
void insertList(struct node**, int);
void printList(struct node*, int);
struct node* mergeList(struct node*, struct node*);
void listToArray(struct node*, int[], int);

// ���
struct node
{
	int data;
	struct node* next;
};

// ���� �Լ�
int main(void)
{
	// �迭�� ���Ḯ��Ʈ ����
	int arr1[20], arr2[20], arr3[40];
	int i;
	struct node* a = NULL, * b = NULL, * d = NULL, * temp = NULL;

	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// �迭 A�� B�� ������ �������� �Ҵ�
	for (i = 0; i < 20; i++)
	{
		arr1[i] = (rand() % 1000) + 1;
		arr2[i] = (rand() % 1000) + 1;
	}

	// �迭 A�� B�� ������������ ����
	sort(arr1, 20);
	sort(arr2, 20);

	// �迭 A�� B�� ��ҵ��� ���Ḯ��Ʈ A�� B�� ���� ����
	for (i = 0; i < 20; i++)
	{
		insertList(&a, arr1[i]);
		insertList(&b, arr2[i]);
	}

	// ���Ḯ��Ʈ A�� B�� ���
	printf("���Ḯ��Ʈ A : ");
	printList(a, 20);
	printf("\n���Ḯ��Ʈ B : ");
	printList(b, 20);

	// ���Ḯ��Ʈ A�� B�� ��ģ�� �ӽ� ���Ḯ��Ʈ�� ����
	temp = mergeList(a, b);

	// �ӽ� ���Ḯ��Ʈ�� �ӽ� �迭�� ��ȯ
	listToArray(temp, arr3, 40);

	// �ӽ� �迭�� ������������ ����
	sort(arr3, 40);

	// ���ĵ� �ӽù迭�� ���Ḯ��Ʈ D�� ����
	for (i = 0; i < 40; i++)
	{
		insertList(&d, arr3[i]);
	}

	// ���Ḯ��Ʈ D�� ���
	printf("\n���Ḯ��Ʈ D : ");
	printList(d, 40);

	return 0;
}

// �迭�� ������������ ����
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

// ������ 2���� ����
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// ���Ḯ��Ʈ�� ������ ����
void insertList(struct node** list, int data)
{
	// ����Ʈ�� ��尡 �������� �ʴ´ٸ�
	if (*list == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = data;
		temp->next = NULL;
		*list = temp;
	}
	// ����Ʈ�� ��尡 �����Ѵٸ�
	else
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		struct node* ptr = *list;
		temp->data = data;
		temp->next = NULL;
		// ptr�� ���Ḯ��Ʈ ������ �̵�
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

// ���Ḯ��Ʈ�� ���
void printList(struct node* list, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

// ���Ḯ��Ʈ 2���� ��ģ �� �ϳ��� ��ȯ
struct node* mergeList(struct node* a, struct node* b)
{
	struct node* d = a;
	// a�� ���Ḯ��Ʈ ������ �̵�
	while (a->next != NULL)
	{
		a = a->next;
	}
	a->next = b;
	return d;
}

// ���Ḯ��Ʈ�� �迭�� ��ȯ
void listToArray(struct node* list, int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		array[i] = list->data;
		list = list->next;
	}
}
