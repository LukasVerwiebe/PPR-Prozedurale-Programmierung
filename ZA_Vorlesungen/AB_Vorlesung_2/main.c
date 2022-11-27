/**
 * Vorlesung 2: Grundelemente der Programmiersprache C
 */

#include <stdio.h>

int main(void)
{
	printf("Hello, World!\n");
	return 0;
}

/**
 * Primitive Datentypen:
 * Typ:			Größe:
 * boolean		1 Byte
 * char			2 Byte
 * byte			1 Byte
 * short		2 Byte
 * int			4 Byte
 * long			8 Byte
 * float		4 Byte
 * double		8 Byte
 * Die Größen der Datentypen sind in der Sprache C nicht festgelegt und damit
 * plattformabhängig, d.h. abhängig von Compiler, Betriebssystem und Hardware
 *
 * Mittels des sizeof-Operators können die Typen und Variablen Größen während des
 * Programmablaufs abgefragt werden.
 * sizeof(varname)
 * sizeof(typname)
 *
 * Modifikatoren:
 * signed 		Ganzzahl mit Vorzeichen
 * unsigned		Ganzzahl ohne Vorzeichen
 * signed char: -128 - 127
 * unsigned char: 0 - 255
 *
 * Wahrheitswerte:
 * False = 0
 * True = 1
*/

/**
 * Variablen:
 * - Namen für Variablen enthalten nut kleinbuchstaben und Ziffern
 * - Zur Worttrennung verwendet man den Unterstrich
 * - Führende Unterstriche bleiben Systemvariablen vorbehalten
 * - Notation wird als snake_case bezeichnet
 * Hinweis: guter Stil jede Variable wird separat definiert
 *
 * Jede Variable muss immer am Anfang eines Blocks, d.h. vor allen Anweisungen
 * Definitionen können frei platziert werden.
 *
 * Zeichenketten:
 * Soll eine Zeichenkette Sonderzeichen enthalten, muss man die üblichen Ersatzdarstellungen verwenden
 * bspw. \" für anführungszeichen oder \n für Zeilenumbrüche
 */

/**
 * Vektoren:
 * Ein Vektor (oder auch Array) ist ein indizierbares Feld, das eine Folge von Daten desselben Typs aufnehmen kann.
 * Vektoren können eindimensional oder mehrdimensional sein.
 * - Die Anzahl der Elemente, die ein Vektor maximal aufnahmen kann, muss zur Übersetzungszeit bekannt sein.
 * 		- int vector[100];
 * 		- char string[20];
 * 		- int matrix[10][20]
 * - Die Länge der Vektoren kann vor der Definition im Programm berechnet werden.
 * 		- size = i * 3; int vector[size];
 * 		- length = size + 1; char string[length];
 *
 * 	Einzelne Elemente werden durch Angabe ihrer Position (Index) in eckigen Klammern angesprochen
 * 	- vector[22], vector[index + 3] ,matrix[5][7]
 * 	- Das erste Element hat immer den Index 0
 * 	- Die größe von Vektoren kann nicht berechnet werden, auch nicht mit sizeof
 * 	- int vector[10]; vector[17] = 42 ist ein zulässiges Programmstück
 *
 * 	Ein Vektor kann bei seiner Definition explizit initialisiert werden:
 * 	- char vector[] = {'p', 'p', 'r'}; Vektor mit länge 3
 * 	- int vector[20] = {0, 1,2, 3, 4, 5}; Vektor mit länge 20 die ersten 5 Elemente haben werte der rest 0
 * 	- int vector[20] = {0}; Vektor mit länge 20 alle Elemente haben den Wert 0
 *
 * 	Vektoren können nicht durch Zuweisung kopiert werden, Sie müssen elementweise übernommen werden.
 */

/**
 * Zeichenketten:
 * Eine Zeichenkette ist nichts als ein Vektor, dessen Elemente Zeichen sind.
 * - char string[100];
 * Zeichenvektoren können bei der Definition initialisiert werden.
 * - char string[] = "hello\n";
 * Eine Zeichenkette wird immer mit einem Nullbyte '\0' beendet, d.h. die letzte Position im string ist ein '\0'.
 * Die Zeichenkette ist daher immer um 1 länger als die Anzahl der Zeichen der Zeichenkette.
 *
 * In der Standardbibliothek <string.h> sind nützliche Standardfunktionen zu finden.
 * - int strlen(cs) länge des strings
 * - strcpy(s, ct) Zeichenkette ct in Vektor s kopieren
 * - strcat(s, ct) Zeichenkette ct hinten an die Zeichenkette s anfügen
 * - strcmp(cs, ct) Zeichenketten vergleichen
 *
 */


/**
 * Aufzählungstypen:
 *
 * enum WorkingDays
 * {
 * 	MON = 1, TUE, WED, THU, FRI
 * };
 */

/**
 * Typnamen:
 * Mit der typedef-Anweisung können in C neue Typnamen als Synonym für einen existierenden Typ vereinbart werden.
 * - typedef int BOOL;
 * - typedef double CELSIUS;
 * - typedef char TEXT[50];
 * Benutzerdefinierte Typen werden mit Großbuchstaben notiert.
 * Typnamen können auch über Aufzählungen definiert werden.
 *
 * Alternative zur Definition von Typnamen mit #define
 */