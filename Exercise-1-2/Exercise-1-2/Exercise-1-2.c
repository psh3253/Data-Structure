#include <stdio.h>

int HornerLaw(int arr[], int size, int x)
{
	int i, result;
	result = arr[size - 1];
	for (i = size - 2; i >= 0; i--)
	{
		result = result * x + arr[i];
	}
	return result;
}

int main(void)
{
	int arr[5] = { -7, 1, -3, 2, 5 };
	int size = sizeof(arr) / sizeof(int);
	int result = HornerLaw(arr, size, 3);
	printf("result : %d", result);
	return 0;
}