#include <stdio.h>

int ulam_max(int a0);
int ulam_twins(int limit);
int ulam_multiples(int limit, int number);

int main()
{
	printf("%i\n", ulam_max(5));
	printf("%i\n", ulam_max(7));
	printf("\n");
	printf("%i\n", ulam_twins(6));
	printf("%i\n", ulam_max(6));
	printf("%i\n", ulam_max(5));
	printf("%i\n", ulam_twins(5));
	printf("\n");
	printf("%i\n", ulam_multiples(10, 2));
	printf("%i\n", ulam_multiples(1000, 3));
	printf("%i\n", ulam_multiples(108, 3));
	printf("%i\n", ulam_multiples(1391, 6));

	return 0;
}

int ulam_max(int a0)
{
	int storage = 0;

	if(a0 <= 0)
	{
		return -1;
	}

	while(a0 > 1)
	{
		if(a0 > 1 && a0 % 2 == 0)
		{
			a0 = a0 / 2;
		}
		else if(a0 > 0 && a0 % 2 != 0)
		{
			a0 = a0 * 3 + 1;
		}

		if(a0 > storage)
		{
			storage = a0;
		}
	}

	return storage;
}

int ulam_twins(int limit)
{
	int storage = -1;
	int limit_value = 1;

	if(limit < 0)
	{
		return -1;
	}

	while(limit_value < limit)
	{
		if(ulam_max(limit_value) == ulam_max(limit_value + 1))
		{
			storage = limit_value;
		}
		limit_value = limit_value + 1;
	}

	return storage;
}

int ulam_multiples(int limit, int number)
{
	
}
