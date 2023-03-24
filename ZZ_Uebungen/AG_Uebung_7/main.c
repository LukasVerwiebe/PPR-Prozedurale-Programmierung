#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>

// Aufgabe 9.1
union INT_BYTES
{
	int value;
	char bytes[sizeof(int)];
};

// Aufgabe 9.2
double average(int number, ...)
{
	va_list p_args;
	int current_number;
	int sum = 0;
	int count = 0;

	va_start(p_args, number);

	current_number = number;
	do
	{
		sum += current_number;
		count++;

		current_number = va_arg(p_args, int);
	} while (current_number != -1);

	va_end(p_args);

	return (double) sum / count;
}

int main()
{
	// Aufgabe 9.1
	union INT_BYTES number;
	int i;

	number.value = 0x11223344;

	for(i = 0; i < sizeof(int); i++)
	{
		printf("%2x ", (char) number.bytes[i]);
	}
	printf("\n");


	// Aufgabe 9.2
	printf("Durchschnitt: %6.1f\n", average(2, 3, 4, 5, -1));

	return 0;
}
