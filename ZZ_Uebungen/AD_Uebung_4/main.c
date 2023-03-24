#include <stdio.h>
#include <string.h>

// Aufgabe 6.2: d)
#define MAX 10

//char buffer[MAX] = "";
char *search(char *text, char c)
{
	//char buffer[MAX] = "";
	static char buffer[MAX] = "";
	int i = 0;

	while(text[i] != '\0' && text[i] != c)
	{
		i++;
	}
	strncpy(buffer, &text[i], MAX);

	return buffer;
}

// Aufgabe 6.2:
#define MAXVALUE 100
int vector[MAXVALUE];

void initUsingIndexoperator(void)
{
	int i;

	for(i = 0; i < MAXVALUE; i++)
	{
		vector[i] = 0;
	}
}

void initUsingPointer(void)
{
	int i;
	int *p = vector;

	for(i = 0; i < MAXVALUE; i++)
	{
		*p = 0;
		p++;
	}
}

// Aufgabe 6.3:
void xxx(void)
{
	char *lectures[] = {"SPIN", "TENI", "THI", "ADS", "SWT"};

	char *p;
	char **pp;

	p = lectures[1];
	pp = lectures;

	printf("1. %s\n", p);
	printf("2. %s\n", p + 2);
	printf("3. %s\n", *(pp + 2));
	printf("4. %s\n", *pp + 2);
	printf("5. %s\n", *(pp + 1) + 2);
	printf("6. %s\n", *(lectures + 2));
	printf("7. %s\n", (lectures[2] + 2));
	/*
	 * 1. TENI
	 * 2. NI
	 * 3. THI
	 * 4. IN
	 * 5. NI
	 * 6. THI
	 * 7. I
	 *
	 */
}


int main()
{
	// Aufgabe 6.1: a)
	/*
	int ival;
	int *ptr;
	printf("Test 0: %d\n", ival);

	ptr = ival;
	*ptr = 255;

	printf("Test 1: %d\n", *ptr);
	printf("Test 2: %d\n", ival);
	*/
	/*
	 * int ival = Zufälliger Wert (z.B. 0x12345678)
	 * int *ptr = Zufälliger Wert (z.B. 0x12345678)
	 *
	 * ptr = ival 	Die Vriable ival it nicht initialisiert worden damit wird auf einen zufälligen Wert gezeigt.
	 * Außerdem muss auf mit dem Adressoperator auf den Wert in der Variable gezeigt werden.
	 *
	 * In Zeile 3 wird ptr mit dem Ganzzahlwert von ival ohne Typkonvertierung und
	 * nicht mit einer Adresse initialisiert.
	 *
	 * *ptr = 255 	Der Speicherstelle von ival wird ein Wert hinzugefügt.
	 * ival und der *ptr haben bei der Ausgabe beid den Wert.

	int a = 5;
	int *ptr_int = &a;
	printf("Test: %d\n", *ptr_int);
	*/

	// Aufgabe 6.1: b)
	/*
	int *ptr = NULL;
	int ival;
	ptr = &ival;
	ival = 9876;
	*ptr = 1234;

	printf("%d\n", *ptr);
	printf("%d\n", ival);
	 */
	/*
	 * Der Wert 9876 in ival wird durch den Pointer auf die Adresse von ival geändert in den Wert 1234
	 */

	// Aufgabe 6.1: c)
	/*
	int vector[] = {12, 34, 56, 78, 90, 23, 45};
	int *ptr1;
	int *ptr2;

	ptr1 = vector;
	ptr2 = &vector[4];
	ptr1 += 2;
	ptr2++;

	printf("1: %d\n", *ptr1);
	printf("2: %d\n", *ptr2);
	printf("3: %d\n", ptr2 - ptr1);
	printf("4: %d\n", ptr1 < ptr2);
	printf("5: %d\n", *ptr1 < *ptr2);
	*/

	// Aufgabe 6.2: d)
	/*
	char *text = search("Hallo Welt!", 'W');
	printf("%s\n", text);
	*/


	// Aufgabe 6.2: e)
	/*
	char str1[] = "Hallo Welt";
	char *str2 = "Hallo Welt";

	printf("%s\n", str1);
	printf("%s\n", str2);
	 */
	/*
	 * str1[] = str1 ist ein char-Vektor mit dem 12 Elemente, in die bei der Initialisierung die Zeichenkette
	 * reinkopiert wird.
	 *
	 * str2 ist ein char-Zeiger, der auf die Startadresse einer Konstanten Zeichenkette zeigt.	 *
	 */

	// Aufgabe 6.3:
	/*
	 * Jeder Zugriff mittels Indexoperator [] wird vom Compiler direkt in einen Zeiger-Zugriff umgeformt
	 * vector[i] -> *(vector + i)
	 * Die Addition von i zur Startadresse impliziert die Multiplikation von i mit der Breite des Elementtyps
	 *
	 * Die Addition von 1 zu einer Zeigerposition impliziert nur die Addition der Breit des Typs
	 *
	 * Schlussfolgerung:
	 * Die Funktion mit der Zeigerarithmetrik ist schneller und damit "laufzeiteffizienter", da hier keine
	 * Multiplikation notwendig ist.
	 */



	return 0;
}
