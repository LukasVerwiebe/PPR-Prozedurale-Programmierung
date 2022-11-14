/**
 * Vorlesung 4: Funktionen
 */

#include "library.h"

#include <stdio.h>

int main(void)
{
	printf("Hello, World!\n");
	return 0;
}

/**
* Übersicht:
 * - Funktionen sind vergleichbar mit statischen Methoden in Java.
 * - Funktionen werden nicht auf einem Objekt ausgeführt, sondern erhalten alle Werte über Parameter
 *
 * Funktionsdefinition:
 * <Resultatttyp> <Funktionsname>(<Parameterliste>)
 * {
 * 		<Funktionskörper>
 * }
 *
 * - In C können Funktionen nicht überladen und nicht geschachtelt werden *
 * - Die return-anweisung dient dazu, ein Ergebnis von der aufgerufenen Funktion an den Aufrufer zu liefern
 *
 * Exit:
 * - Die Standard-Bibliothek stdlib.h stellt die Funktion exit zur Verfügung
 * - Exit beendet das Programm und liefert den Argumentwert an die laufende Umgebung. Zusätzlich schließt exit auch
 * noch alle offenen Dateien
 * - Exit kann auch aus allen anderen Funktionen aufgerufen werden, z.B. bei schwerwiegenden Fehlern.
 * - Es sollten immer die in der Standard-Bibliothek vordefinierten symbolischen Konstanten EXIT_SUCCESS und EXIT_FAILURE
 * verwendet werden. bsp. return (EXIT_SUCCESS)
 *
 * Funktionsaufrufe: <Funktionsname>(<Argumentliste>)
 * - Funktionen können innerhalb andere Funktionen aufgerufen werden
 * - Funktionen können sich selber und gegenseitig aufrufen (Rekursion)
 *
 * Parameterübergabe:
 * - Call-by-value: Argumente werden kopiert und die kopie an die aufgerufene Funktion übergeben
 * - call-by-reference: kann in C durch Übergabe von Speicheradressen (Zeigern) simuliert werden (bsp. Startadresse Vektor)
 * - call-by-name:
 *
 * Funktionsprototypen:
 * - In C muss jeder Bezeichner vor seiner ersten Verwendung deklariert sein.
 * - Ein Funktionsprototyp teilt dem Compiler mit, dass es eine Funktion einmal geben wird: z.B. double atof(char s[]);
 * - Werden im Prototypen die Parameter weggelassen, wird die Prüfung der Parameter abgeschaltet. Funktionen ohne
 * Parameter sollten daher mit void vereinbart werden: bsp. int dummy(void)
 *
*/

/**
* Lebensdauer und sichtbarkeit:
 * - Die Lebensdauer ist die Zeitspanne, in der dem Bezeichner ein Speicherbereich zugeordnet ist
 * - Der Sichtbarkeitsbereich (oder Scope) ist der Codebereich, in dem der Bezeichner ansprechbar ist
 *
 * Arten von Bezeichnern:
 * - Funktionen: Leben ab Definition bis Programmende sind im gesamten Programm ansprechbar (sichtbar)
 * - Globale Variablen: Leben ab Definition bis Programmende sind im gesamten Programm ansprechbar (sichtbar) können
 * aber verdeckt werden
 * - Lokale Variablen: Leben ab Definition bis ende des Blocks nur innerhalb des Blocks der Funktion ansprechbar können
 * überdeckt werden
 * - Formale Parameter: Formale Parameter werden in einem Funktionskopf definiert
 * Leben ab Definition bis ende der Funktion, sind nur innerhalb der Funktion ansprechbar können überdekct werden
 *
*/

/**
* Speicherklassen:
 * Variablen und Funktionen können verschiedenen Speicherklassen zugeordnet werden.
 * - extern
 * Soll eine globale Variable verwendet werden, bevor sie definiert wird, oder wird sie in einer anderen Quelldatei
 * definiert, muss sie als extern deklariert werden.
 *
 * - static
 * Wird eine Funktion als static vereinbart, wird die Sichtbarkeit auf den Rest der Quelldatei begrenzt, in der sich
 * die Definition befindet.
 *
 * - register
 * Man kann dem Compiler mitteilen, dass eine Variable in einem Register gehalten werden soll, Vereinbarung mit register
 *
 * - auto
 *
*/

/**
* Typ-Attribute:
 * - Mit dem Attribut const kann man Variablen definieren, die nur einmal initialisiert und anschließend nicht mehr
 * geändert werden können. auch bei Vektoren möglich const char PRIMES[] = {1, 2, 3, 4, 5};
 * - const-Deklarationen sind #define-Direktiven vorzuziehen, da sie Gültigkeitsbereiche und Typisierung berücksichtigen
 * - Guter Stil: Verändert eine Funktion den Inhalt eines formalen Parameters nicht, sollte dieser const definiert werden
 * int gcd(const int n, const int m);
 * - Mit dem Attribut volatile kann man festlegen, dass der Wert einer Variablen bei jedem Zugriff neu aus dem
 * Hauptspeicher gelesen wird.
*/