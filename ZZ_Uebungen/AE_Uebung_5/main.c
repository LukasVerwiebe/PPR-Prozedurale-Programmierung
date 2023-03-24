#include <stdio.h>

void bubblesort(int *a, int length);

// Aufgabe: 7.1 a)
#define MAX_LENGTH 100
void bubblesort_v2(int **a, int length);
void intit_ptrs_v2(int **p, int *a, int length);

// Aufgabe: 7.1 b)
typedef int (*COMP_FCT) (void *, void *);
void bubblesort_v3(void **a, int length, COMP_FCT cmp);
void init_ptrs_v3(void **p, void *a, int length, int width);



int main()
{
	int ints[] = {1,9,2,8,4,5,6,3,7,0};
	int count = 10;
	int i;

	bubblesort(ints, count);

	for(i = 0; i < count; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");

	// Aufgabe: 7.1 a)
	int ints2[] = {1,9,2,8,4,5,6,3,7,0};
	int count2 = 10;

	int *ptrs[MAX_LENGTH] = {NULL};
	intit_ptrs_v2(ptrs, ints2, count2);

	bubblesort_v2(ptrs, count2);

	for(i = 0; i < count2; i++)
	{
		printf("%d ", *ptrs[i]);
	}
	printf("\n");

	// Aufgabe: 7.1 b)
	int ints3[] = {1,5,4,2,3};
	void *ptrs2[5];

	init_ptrs_v3(ptrs2, ints3, 5, sizeof(int));

	//bubblesort_v3(ptrs2, 5, 5);

	for(i = 0; i < 5; i++)
	{
		printf("%d ", ints3[i]);
	}
	printf("\n");


	// Aufgabe: 7.2
	/*
	 *	Was waren noch Signaturen?
	 *	- Signaturen definierten die formale Schnittstelle einer Funktion.
	 *	- Funktionsprototypen geben die Signatur einer Funktion an.
	 *
	 *	Die Signatur der übergebenen Funktion muss mit dem Typ des Parameters übereinstimmen. Das bedeutet im Einzelnen:
	 *	- zum einen muss der Rückgabetyp identisch sein oder sich implizit vom gegeben in gefragte Typ konvertieren
	 *	lassen.
	 *	- zum anderen muss die Parameterliste übereinstimmen, was bedeutet, dass jeder Parametertyp der gegebenen
	 *	Parameterliste in gleicher Reihenfolge zu jedem Parametertyp der gefragten Parameterliste passen muss.
	 *	- mit "passen" ist gemeint, dass der Typ entweder identisch ist oder sich der gegebene Typ implizit in den
	 *	gefragten Typ konvertieren lässt (implizites Casting).
	 *
	 */

	return 0;
}

void bubblesort(int *a, int length)
{
	int i;
	int j;
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0; j <length - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// Aufgabe: 7.1 a)
void bubblesort_v2(int **a, int length)
{
	int i;
	int j;
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0; j <length - i - 1; j++)
		{
			if(*a[j] > *a[j + 1])
			{
				int *tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void intit_ptrs_v2(int **p, int *a, int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		p[i] = &a[i];
	}
}

// Aufgabe 7.1 a)
void bubblesort_v3(void **a, int length, COMP_FCT cmp)
{
	int i;
	int j;
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0; j <length - i - 1; j++)
		{
			if(cmp(a[j], a[j+1]) == 1)
			{
				void *tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void init_ptrs_v3(void **p, void *a, int length, int width)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		p[i] = a + i * width;
	}
}