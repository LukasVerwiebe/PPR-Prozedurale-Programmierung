/**
 * Vorlseung 6: Zeiger (Pointer)
 */

#include "library.h"

#include <stdio.h>

int main(void)
{
	printf("Hello, World!\n");
	return 0;
}

/**
 * Zeiger und Adressen:
 * Zeiger sind Variablen, deren Wert eine Speicheradresse ist, sozusagen ein Zeiger auf eine Speicherstelle
 *
 * Zeigervariablen:
 * - Für Zeigervariablen wird bei ihrer Definition ein Speicherbereich reserviert, in dem die Adresse auf eine andere
 * Speicherstelle abgelegt wird, an der der Wert abgelegt wird.
 * - Beim Zugriff auf die Zeigervariable kann direkt auf die Adresse oder indirekt auf den Wert zugegriffen werden. *
 * - Ein Zeiger benötigt eine Bytegruppe, die so groß ist, dass jede gültige Speicheradresse dort abgelegt werden kann.
 * - Zeiger zeigen immer auf den Anfang einer Bytegruppe
 *
 * Operatoren:
 * - Inhalts- oder Verweisoperator * (Syntax: *Zeigervariable)
 * Mit dem Inhaltsoperator kann auf den Wert zugegriffen werden, auf den der Zeiger verweist.
 * - Adressoperator: & (Syntax: &Variable)
 * Mit dem Adressoperator kann auf die Adresse einer Variable zugegriffen werden
 *
 * Zeigervariablen müssen vor ihrer ersten Verwendung definiert werden: Syntax: Typname *Bezeichner
 * bsp. int +p_int; char *p_char; long int *p_long_int;
 *
 * Zeigervariablen - Umgangsregeln:
 * 1. Zu jedem Zeiger muss es immer einen Speicherplatz geben, auf den der Zeiger zeigt und in dem ein Wert abgelegt
 * werden kann.
 * 2. Ein Zeiger muss dereferenziert werden, um auf den Wert im Pointer zuzugreifen.
 * 3. Durch die Zuweisung von Zeigern verweisen beide auf den selben Speicherbereich.
 *
 *
 */
