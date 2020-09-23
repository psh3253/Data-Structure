#include <stdio.h>
#define SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

void perm(char* list, int i, int n)
{
	int j, temp;
	if (i == n)
	{
		for (j = 0; j <= n; j++)
			printf("%c", list[j]);
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
	int i, j;
	char A[4][6] = { "GO", "BOY", "GIRL", "GIRLS" };
	for (i = 0; i < 4; i++)
	{
		j = 0;
		while (A[i][j] != '\0')
		{
			j++;
		}
		perm(A[i], 0, j - 1);
		printf("\n");
	}
	return 0;
}