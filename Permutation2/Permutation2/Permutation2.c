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
	int num, i;
	char list[100000];
	scanf("%d", &num);
	for (i = 0; i < num + 1; i++)
	{
		list[i] = (char)(i + 49);
	}
	//char list[3] = { 'a', 'b', 'c' };
	perm(list, 0, num - 1);
	return 0;
}