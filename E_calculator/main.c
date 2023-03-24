/**
 * @mainpage calculator (PPR)
 *
 * Dieses Projekt realisiert einen Taschenrechner mit den vier Grundrechenarten
 * und veranschaulicht dabei die Modularisierung in C mit den Präprozessor-
 * Direktiven sowie den Einsatz von Makros und der bedingten Überstzung.
 *
 */

/**
 * @file
 * 
 * Dieses Modul startet den Taschenrechner.
 *
 */


/* ===========================================================================
 * Header-Dateien einbinden
 * ======================================================================== */

#include <stdio.h>
#include <stdlib.h>

#include "parse.h"
#include "evaluate.h"
#include "calculator_common.h"


/* ===========================================================================
 * Funktionsdefinitionen
 * ======================================================================== */

/**
 * Realisiert eine Endlosschleife, in der der arithmetische Ausdruck eingelesen,
 * ausgewertet und auf dem Bildschirm ausgegeben wird. Zum Beenden des
 * Taschenrechners muss das Fenster geschlossen werden.
 *
 * @return liefert immer EXIT_SUCCESS
 */
int main(void)
{
    double result;
    
    while (TRUE)
    {
        printf("PPR-Taschenrechner> ");
        parse();
#ifdef DEBUG
        print_postfix_tokens();
#endif
        result = evaluate();
        printf("Ergebnis: %.1f\n\n", result);
    }

    return EXIT_SUCCESS;
}
