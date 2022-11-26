/**
 * Vorlesung 1: Erste C-Programme
 */

/**
 * Einfügen von weiteren Bibliotheken mit zusätzlichen Funktionen
 * Hier: Nutzung von Funktionen der Standrad-Bibliothek
 */
#include <stdio.h>

/**
 * Globale Variablen:
 */
double betrag = 33.0;
int size;

/**
 * Funktion-Signatur:
 * Funktionen müssen vor ihrem Aufruf deklariert werden
 */
int temp();
int temp2();
int temp3();
int temp4();
double transform_fahrenheit_to_celsius(int fahr);
int get_fahrenheit(void);


/**
 * - Jedes ausführbare Programm enthält genau eine Funktion main
 * - Jede logische Programmzeile wird durch ein ';' abgeschlossen
 * - Geschweifte Klammern '{' und '}' gruppieren Anweisungen zu Blöcken
 * - Die Funktion main liefert einen Resultwert an die Umgebung
 */
int main(void)
{
	printf("Hello, World!\n");

	// Ausführung der Funktion temp
	temp();
	temp2();
	temp3();
	temp4();
	get_fahrenheit();
	return 0;
}

/**
 * Schleifen: while, for, do-while
 * Programm zur Umwandlung von Fahrenheit
 * in Celsius für 0, 20, ..., 300 Grad
 * @return
 */
int temp()
{
	int fahr;
	int celsius;

	fahr = 0;
	while(fahr <= 300)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + 20;
	}
	return 0;
}

/**
 * Primitive Datentypen: char, int, float, double
 * Programm zur Umwandlung von Fahrenheit
 * in Celsius für 0, 20, ..., 300 Grad
 * @return
 */
int temp2()
{
	int fahr;
	double celsius;

	fahr = 0;
	while(fahr <= 300)
	{
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%d\t%f\n", fahr, celsius);
		fahr = fahr + 20;
	}
	return 0;
}

/**
* Formatierte Ausgabe:
 * Mit printf können die Anzahl der insgesamt ausgegebenen Stellen
 * und die Nachkommastellen festgelegt werden.
*/
// printf("%d\t%f\n", fahr, celsius);
// printf("%3d %6.1f\n", fahr, celsius);
/**
 * Der Platzhalter bestimmt den Typ des Parameters:
 * %d	int				dezimal
 * %u	unsigned int	dezimal
 * %o	unsigned int	oktal
 * %x	unsigned int	hexadezimal
 * %f	double			dezimal mit vor- und Nachkommastellen
 * %c	char			Zeichen gemäß ASCII
 * %s	Zeichenkette	Zeichenkette gemäß ASCII
 * %p	Zeige			Speicheradresse (hexadezimal)
 */

/**
 * Symbolische Konstanten sind reine Textersetzung
 * Programm zur Umwandlung von Fahrenheit
 * in Celsius für 0, 20, ..., 300 Grad
 */
#define LOWER 0		// Untere Grenze der Temperaturtabelle
#define UPPER 300	// obere Grenze der Temperaturtabelle
#define STEP 20		// Schrittweite

int temp3()
{
	int fahr;
	double celsius;

	fahr = LOWER;
	while(fahr <= UPPER)
	{
		celsius = (5.0 / 9.0) * (fahr - 32);
		printf("%d\t%f\n", fahr, celsius);
		fahr = fahr + STEP;
	}
	return 0;
}

/**
 * Funktionen
 * Programm zur Umwandlung von Fahrenheit
 * in Celsius für 0, 20, ..., 300 Grad
 */
int temp4()
{
	int fahr;
	double celsius;

	fahr = LOWER;
	while(fahr <= UPPER)
	{
		celsius = transform_fahrenheit_to_celsius(fahr);
		printf("%d\t%f\n", fahr, celsius);
		fahr = fahr + STEP;
	}
	return 0;
}
double transform_fahrenheit_to_celsius(int fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}

/**
 * Ein- und Ausgabe
 * Gegenstück zu getchar: int putchar(int)
 *
 * Die Funktion scanf liest eine formatierte Eingabe von der Tastatur.
 * scanf("%d and %d", &number1, &number2);
*/
int get_fahrenheit(void)
{
	int a_char = 0;
	int fahr = 0;

	printf("Geben Sie einen Fahrenheitwert ein: ");
	fflush(stdout);
	/* Zeichenweises Einlesen und Berechnen des Zahlenwertes */
	a_char = getchar();
	while(a_char != '\n')
	{
		if(a_char >= '0' && a_char <= '9')
		{
			fahr = (fahr * 10) + (a_char - '0');
		}
		a_char = getchar();
	}
	return fahr;
}
