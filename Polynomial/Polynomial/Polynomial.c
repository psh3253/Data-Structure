#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) ((x) < (y)) ? -1 : ((x) == ((y)) ? 0 : 1)
typedef struct
{
	float coef;
	int expon;
} polynomial;
polynomial* padd(polynomial*, polynomial*);
polynomial* pmul(polynomial*, polynomial*);
polynomial* single_mul(polynomial, polynomial*);
int startA, countA, startB, countB, countD;

polynomial* padd(polynomial* A, polynomial* B)
{
	polynomial* D = (polynomial*)malloc(sizeof(polynomial) * 10);
	float coefficient;
	int limit = 10;
	startA = 0;
	startB = 0;
	countD = 0;
	while (countA * countB > limit)
	{
		limit *= 2;
		D = realloc(D, sizeof(polynomial) * limit);
	}

	while (A[startA].expon != -1 && B[startB].expon != -1)
	{
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
	for (; A[startA].expon != -1; startA++)
	{
		D[countD].coef = A[startA].coef;
		D[countD++].expon = A[startA].expon;
	}

	for (; B[startB].expon != -1; startB++)
	{
		D[countD].coef = B[startB].coef;
		D[countD++].expon = B[startB].expon;
	}
	D[countD].coef = -1;
	D[countD].expon = -1;
	return D;
}

polynomial* pmul(polynomial* A, polynomial* B)
{
	int i, limit = 10;
	polynomial* X;
	polynomial* D = (polynomial*)malloc(sizeof(polynomial) * 10);
	while (countA * countB >= limit)
	{
		limit *= 2;
		D = realloc(D, sizeof(polynomial) * limit);
	}
	D[0].coef = -1;
	D[0].expon = -1;
	for (i = 0; A[i].expon != -1; i++)
	{
		X = (polynomial*)malloc(sizeof(polynomial) * 10);
		limit = 10;
		while (countB >= limit)
		{
			limit *= 2;
			X = realloc(X, sizeof(polynomial) * limit);
		}
		X = single_mul(A[i], B);
		D = padd(D, X);
		free(X);
	}
	return D;
}

polynomial* single_mul(polynomial A, polynomial* B)
{
	int i, limit = 10;
	polynomial* X = (polynomial*)malloc(sizeof(polynomial) * 10);
	while (countB >= limit)
	{
		limit *= 2;
		X = realloc(X, sizeof(polynomial) * limit);
	}

	for (i = 0; B[i].expon != -1; i++)
	{
		X[i].coef = A.coef * B[i].coef;
		X[i].expon = A.expon + B[i].expon;
	}
	X[i].coef = -1;
	X[i].expon = -1;
	return X;
}

int main(void) {
	float coef;
	int expon = 0, limit, i;
	countA = 0;
	limit = 10;

	polynomial* A = (polynomial*)malloc(sizeof(polynomial) * 10);
	polynomial* B = (polynomial*)malloc(sizeof(polynomial) * 10);
	polynomial* C = (polynomial*)malloc(sizeof(polynomial) * 10);
	polynomial* D = (polynomial*)malloc(sizeof(polynomial) * 10);

	while (1)
	{
		printf("다항식 A의 계수와 지수 입력 : ");
		scanf("%f %d", &coef, &expon);
		if (expon == -1)
		{
			A[countA].coef = -1;
			A[countA].expon = -1;
			countA++;
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
			B[countB].coef = -1;
			B[countB].expon = -1;
			countB++;
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

	limit = 10;
	while (countA + countB >= limit)
	{
		limit *= 2;
		C = realloc(C, sizeof(polynomial) * limit);
	}

	C = padd(A, B);
	expon = 0;
	i = 0;
	printf("다항식의 덧셈\n");
	while (1)
	{
		if (C[i].expon == -1)
			break;
		printf("계수 : %f, 지수 : %d\n", C[i].coef, C[i].expon);
		i++;
	}
	printf("\n");

	limit = 10;
	while (countA * countB >= limit)
	{
		limit *= 2;
		D = realloc(C, sizeof(polynomial) * limit);
	}
	D = pmul(A, B);
	expon = 0;
	i = 0;
	printf("다항식의 곱셈\n");
	while (1)
	{
		if (D[i].expon == -1)
			break;
		printf("계수 : %f, 지수 : %d\n", D[i].coef, D[i].expon);
		i++;
	}
	return 0;
}