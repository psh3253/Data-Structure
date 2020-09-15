#include <stdio.h>
#include <time.h>
#define SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

void perm(int* list, int i, int n)
{
	int j, temp;
	if (i == n)
	{
		for (j = 0; j <= n; j++)
			printf("%d", list[j]);
		printf("	");
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}

int main(void)
{
	int num, i;
	int list[100];
	double duration;
	clock_t start;
	scanf("%d", &num);
	for (i = 0; i < num + 1; i++)
	{
		list[i] = i + 1;
	}
	start = clock();
	perm(list, 0, num - 1);
	duration = ((double)(clock() - start) / CLOCKS_PER_SEC);
	printf("\n%f", duration);
	return 0;
}