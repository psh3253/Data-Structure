#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y)) ? -1 : ((x) == ((y)) ? 0 : 1)
typedef struct
{
	float coef;
	int expon;
} polynomial;
polynomial* A, * B, * C;
int startA, countA, startB, countB, countD;

polynomial* padd(polynomial* A, polynomial* B)
{
	polynomial* D = (polynomial*)malloc(sizeof(polynomial) * 10);
	float coefficient;
	int limit = 10;
	startA = 0;
	startB = 0;
	countD = 0;

	while (startA < countA && startB < countB)
	{
		if (countD >= limit)
		{
			limit *= 2;
			C = (polynomial*)realloc(C, sizeof(polynomial) * limit);
			D = (polynomial*)realloc(D, sizeof(polynomial) * limit);
		}
		switch (COMPARE(A[startA].expon, B[startB].expon))
		{
		case -1:
			D[countD].coef = B[startB].coef;
			D[countD++].expon = B[startB].expon;
			startB++;
			break;
		case 0:
			coefficient = A[startA].coef + B[startB].coef;
			if (coefficient)
			{
				D[countD].coef = coefficient;
				D[countD++].expon = A[startA].expon;
			}
			startA++;
			startB++;
			break;
		case 1:
			D[countD].coef = A[startA].coef;
			D[countD++].expon = A[startA].expon;
			startA++;
		}
	}
	for (; startA < countA; startA++)
	{
		if (countD >= limit)
		{
			limit *= 2;
			C = (polynomial*)realloc(C, sizeof(polynomial) * limit);
			D = (polynomial*)realloc(D, sizeof(polynomial) * limit);
		}
		D[countD].coef = A[startA].coef;
		D[countD++].expon = A[startA].expon;
	}

	for (; startB < countB; startB++)
	{
		if (countD >= limit)
		{
			limit *= 2;
			C = (polynomial*)realloc(C, sizeof(polynomial) * limit);
			D = (polynomial*)realloc(D, sizeof(polynomial) * limit);
		}
		D[countD].coef = B[startB].coef;
		D[countD++].expon = B[startB].expon;
	}
	return D;
}

int main(void) {
	float coef;
	int expon = 0, limit, i;
	countA = 0;
	limit = 10;

	A = (polynomial*)malloc(sizeof(polynomial) * 10);
	B = (polynomial*)malloc(sizeof(polynomial) * 10);
	C = (polynomial*)malloc(sizeof(polynomial) * 10);

	while (1)
	{
		printf("다항식 A의 계수와 지수 입력 : ");
		scanf("%f %d", &coef, &expon);
		if (expon == -1)
		{
			printf("\n");
			break;
		}
		if (countA >= limit)
		{
			limit *= 2;
			A = (polynomial*)realloc(A, sizeof(polynomial) * limit);
		}
		A[countA].coef = coef;
		A[countA].expon = expon;
		countA++;
	}
	countB = 0;
	limit = 10;

	while (1)
	{
		printf("다항식 B의 계수와 지수 입력 : ");
		scanf("%f %d", &coef, &expon);
		if (expon == -1)
		{
			printf("\n");
			break;
		}
		if (countB >= limit)
		{
			limit *= 2;
			B = (polynomial*)realloc(B, sizeof(polynomial) * limit);
		}
		B[countB].coef = coef;
		B[countB].expon = expon;
		countB++;
	}
	C = padd(A, B);
	for (i = 0; i < countD; i++)
	{
		printf("계수 : %f, 지수 : %d\n", C[i].coef, C[i].expon);
	}
	return 0;
}