/**
 * Vorlesung 5: Der C-Präprozessor
 */
#include <stdio.h>

#define MSDOS 1
#define VMS 2
#define BSD 3
#define TARGET MSDOS

int main(void)
{

	return 0;
}

/**
 * Einfügen von Dateien:
 * Mit der #include-Direktive kann der gesamte Inhalt einer Datei in den Quellcode eingefügt werden.
 * Syntax: #include <Dateiname>
 */

/**
 * Makros:
 * Mit der #define-Direktive können symbolische Namen definiert werden.
 * Syntax: #define <Name><Ersatztext>
 * Alle Vorkommen des symbolischen Namens werden ab der Definition bis zum Ende der Datei durch den Ersatztext ersetzt.
 *
 * Mit der #undef-Direktive können symbolische Namen wieder gelöscht werden
 */

/**
* Bedingte Übersetzung:
 * Mit der #if-Direktive kann die Ausführung des Präprozessors kontrolliert werden
 * Der Programmtext wird abhängig vom Wert der Bedingungen eingefügt:
 * #if ConstExpr-1
 * 		Programmtext-1
 * #elif ConstExpr-2
 * 		Programmtext-2
 * #else
 * 		Programmtext-n
 * #endif
*/

/**
* Modularisierung:
 *
*/