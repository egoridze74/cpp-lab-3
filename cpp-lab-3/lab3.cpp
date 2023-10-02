#include <stdio.h>
#include <stdlib.h>

//basic recursive function
int get_diff(int i, int n, int* array, int first_sum, int second_sum)
{
	if ((i == n) || array[i] == 0)
		return abs(first_sum - second_sum);
	else
	{
		int masha = get_diff(i + 1, n, array, first_sum + array[i], second_sum); //Masha + chashka #i
		int petya = get_diff(i + 1, n, array, first_sum, second_sum + array[i]); //Petya + chashka #i
		if (masha < petya)
			return masha;
		else 
			return petya;
	}
}



int main()
{
	int n;
	scanf_s("%d", &n); //input number of cups

	int array[32];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &array[i]); //sizes of cups

	int difference = get_diff(0, n, array, 0, 0);
	printf("%d", difference);
}