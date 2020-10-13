#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void insert_front(struct node** A, int data)
{
	if (*A == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = data;
		temp->next = NULL;
		*A = temp;
	}
	else
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = data;
		temp->next = *A;
		*A = temp;
	}
}

void print_list(struct node** A)
{
	struct node* ptr = *A;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void insert_last(struct node** A, int data)
{
	if (*A == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		temp->data = data;
		temp->next = NULL;
		*A = temp;
	}
	else
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node*));
		struct node* ptr = *A;
		temp->data = data;
		temp->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

int search(struct node** A, int data)
{
	int num = 0;
	struct node* ptr = *A;
	while (ptr != NULL)
	{
		if (ptr->data == data)
		{
			return num;
		}
		ptr = ptr->next;
	}
	return -1;
}

int delete_front(struct node** A)
{
	int data;
	struct node* ptr = *A;
	data = ptr->data;
	*A = ptr->next;
	//free(*A);
	return data;
}

int delete(struct node** A, int data)
{
	struct node* ptr = *A;
	struct node* temp;
	while (ptr->next != NULL)
	{
		if (ptr->next->data == data)
		{
			temp = ptr->next;
			ptr->next = ptr->next->next;
			//free(temp);
			return data;
		}
		ptr = ptr->next;
	}
	return -1;
}

int main(void)
{
	struct node* A = NULL;
	insert_front(&A, 20);
	insert_front(&A, 10);
	insert_last(&A, 30);
	insert_last(&A, 40);
	delete_front(&A);
	delete(&A, 30);
	print_list(&A);
	return 0;
}