#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TERMS	101
#define MAX_COL	10
typedef struct
{
	int col;
	int row;
	int value;
} term;

void fastTranspose(int a[], int b[])
{
	int row_terms[100] = { 0, };
	int starting_pos[100] = { 0, };
	int i;
	for (i = 0; i < 100; i++)
	{
		row_terms[a[i]]++;
	}
	for (i = 0; i < 100; i++)
	{
		printf("row_terms[%d] : %d\n", i, row_terms[i]);
	}
	starting_pos[0] = 0;
	for (i = 1; i < 100; i++)
	{
		starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
	}
	for (i = 0; i < 100; i++)
	{
		printf("starting_pos[%d] : %d\n", i, starting_pos[i]);
	}
	for (i = 0; i < 100; i++)
	{
		b[starting_pos[a[i]]++] = a[i];
	}
}

int main(void)
{
	int a[100];
	int b[100];
	int i, j;
	srand(time(NULL));
	for (i = 0; i < 100; i++)
	{
		a[i] = rand() % 100;
	}
	printf("배열 A : ");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	fastTranspose(a, b);
	printf("배열 B : ");
	for (i = 0; i < 100; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}