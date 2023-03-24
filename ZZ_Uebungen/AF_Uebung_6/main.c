#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
	BLUES,
	CLASSIC,
	JAZZ,
	POP,
	ROCK
} GENRE;

typedef struct
{
	int tag;
	int monat;
	int jahr;
} DATUM;

typedef struct
{
	char titel[50];
	GENRE genre;
	DATUM edatum;
} CD;


static bool cmp_datum(DATUM *d1, DATUM *d2)
{
	return d1 != NULL && d2 != NULL
			&& d1->tag == d2->tag
			&& d1->monat == d2->monat
			&& d1->jahr == d2->jahr;
}

static bool cmp_cd(CD *cd1, CD *cd2)
{
	return cd1 != NULL && cd2 != NULL
			&& strcmp(cd1->titel, cd2->titel) == 0
			&& cd1->genre == cd2->genre
			&& cmp_datum(&(cd1->edatum), &(cd2->edatum));
}

void print_cd(CD cd)
{
	printf("Titel: %s, Genre: %d, Datum: %2d.%2d.%4d",
			cd.titel, cd.genre,
			cd.edatum.tag, cd.edatum.monat,
			cd.edatum.jahr);
}

void init_memory(void)
{
	char text1[sizeof(CD)];
	memset(text1, '*', sizeof(CD));

	char text2[sizeof(CD)];
	memset(text2, '-', sizeof(CD));

	char text3[sizeof(CD)];
	memset(text3, '=', sizeof(CD));
}

void structfunction(void)
{
	CD cd1 = {"Revolver", POP, {22,03,2001}};
	CD cd2 = {"Revolver", POP, {22,03,2001}};
	CD cd3 = cd1;

	printf("Groesse des Typs GENRE: %4d\n", 			sizeof(GENRE));
	printf("Groesse der Struktur DATUM: %4d\n", 		sizeof(DATUM));
	printf("Groesse der Komponente titel: %4d\n", 	sizeof(cd1.titel));
	printf("Summe der Komponenten: %4d\n", 			sizeof(GENRE) + sizeof(DATUM) + sizeof(cd1.titel));
	printf("Groesse der Struktur CD: %4d\n", 		sizeof(CD));
	printf("\n");

	print_cd(cd1);
	printf(", Padbytes: '%c%c'\n", cd1.titel[50], cd1.titel[51]);

	print_cd(cd2);
	printf(", Padbytes: '%c%c'\n", cd2.titel[50], cd2.titel[51]);

	print_cd(cd3);
	printf(", Padbytes: '%c%c'\n", cd3.titel[50], cd3.titel[51]);

	printf("\n");
	printf("cd1 und cd1 sind %s\n", cmp_cd(&cd1, &cd1) ? "gleich" : "ungleich");
	printf("cd1 und cd2 sind %s\n", cmp_cd(&cd1, &cd2) ? "gleich" : "ungleich");
	printf("cd1 und cd3 sind %s\n", cmp_cd(&cd1, &cd3) ? "gleich" : "ungleich");
}


int main()
{
	init_memory();
	structfunction();

	return 0;
}
