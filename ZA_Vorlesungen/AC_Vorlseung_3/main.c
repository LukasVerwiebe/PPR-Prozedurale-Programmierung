/**
 * Vorlesung 3: Grundelemente der Programmiersprache C - Fortsetzung
 */

#include <stdio.h>

int main(void)
{
	printf("Hello, World!\n");
	return 0;
}

/**
 * Operatoren:
 * Operatoren sind im Prinzip vordefinierte Funktionen, die netterweise ohne Klammern und (meistens) in Infix-Notation
 * notiert werden können.
 * - Infix-Notation: Mathematisch eNotation, bei der die Operatoren zwischen die Operanden gesetzt werden, z.B. 1+2
 *
 * Arithmetische Operatoren:
 * Binär:
 * - + Addition
 * - - Subtraktion
 * - * Multiplikation
 * - / Division
 * - % Ganzzahliger Rest nach Division
 * Unär:
 * - - Minus
 * - ++ Inkrement
 * - -- Dekrement
 *
 * Vergleichsoperatoren:
 * - == gleich
 * - != ungleich
 * - > größer
 * - >= größer gleich
 * - < kleiner
 * - <= kleiner gleich
 *
 * Logische Operatoren:
 * - ! Negation
 * - && logisches und
 * - || logisches oder
 *
 * Bitoperatoren:
 * - ~ Bitweises Komplement
 * - & Bitweises und
 * - | Bitweises oder
 * - ^ Bitweises exklusiv oder
 * - << Bit-Verschiebung nach links
 * - >> Bit-Verschiebung nach rechts
 */

/**
* Typumwandlung:
 * - Implizite Typumwandlungen treten bei der Auswertung von ausdrücken und bei Wertzuweisung auf. z.B. 2.5 + 3
 * - Explizite Typumwandlungen können mit dem unären Cast-Operator erzwungen werden: Syntax (<Typname>) <Ausdruck>
 * Die explizite Umwandlungsoperation ist gleichbedeutend mit der Zuweisung des Ausdrucks an eine Variable des
 * angegebene Typs
*/

/**
* Kontrollstrukturen:
 * Kontrollstrukturen sind Sprachkonstrukte, mit denen die Reihenfolge der Ausführung gesteuert werden kann.
 * - Ein Ausdruck dem ein ';' folgt ist eine Anweisung
 * - Fehlt der Ausdruck, bezeichnet man die Anweisung als leere Anweisung oder englisch als null statement
 * - Mehrere Definitionen und Anweisungen können mit geschweiften Klammern { und } zu einem Block zusammengefasst werden
 * - Vorsicht: Für eine Variable, die in einem inneren Block definiert wird, kann ein Name verwendet werden, der bereits
 * in einem äußeren Block definiert wurde.
 * - Mit if-else-Anweisungen werden Entscheidungen formuliert
 * - Die switch-Anweisung erlaubt eine Auswahl unter mehreren Alternativen
 * - while, do-while
 * - for
 * - Mit der break-Anweisung kann man eine Schleife oder eine switch-Anweisung vorzeitig verlassen (Nur in switch verwenden)
 * - Mit der continue-Anweisung kann man dafür sorgen, dass die nächste Wiederholung der Schleife unmittelbar begonnen
 * wird
 * - Mit der goto-Anweisung kann zu einer bestimmten Marke im Code gesprungen werden
*/