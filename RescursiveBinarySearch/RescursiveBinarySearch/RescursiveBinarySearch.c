#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;	// -1ÀÇ ¹İÈ¯Àº Å½»öÀÇ ½ÇÆĞ¸¦ ÀÇ¹Ì
	mid = (first + last) / 2;

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	return 0;
}