#include <stdio.h>

// Aufgabe: 5.1
#define SWAP(TYPE, V1, V2) \
	{ TYPE _tmp = V1; V1 = V2; V2 = _tmp; }

// Aufgabe: 5.2
//#define DEBUG printf("Fehlermeldung")

#ifdef DEBUG
#define DPRINT(P) printf(#P " = %d\n", P)
#else
#define DPRINT(EXP, FORMAT) \
    printf(#EXP " = %"#FORMAT "\n", EXP)
#endif



int main()
{
	// Aufgabe: 5.1
	int a = 5;
	int b = 33;

	printf("Aufgabe: 5.1\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("SWAP\n");

	SWAP(int, a, b);

	printf("a: %d\n", a);
	printf("b: %d\n", b);

	// Aufgabe: 5.2 a)
	printf("Aufgabe: 5.2\n");
	//DPRINT(55);

	// Aufgabe: 5.2 b)
	double x = 3.0;
	double y = 4.0;
	double z = 2.0;
	DPRINT(x + y - z, f);
	DPRINT("text", s);
	DPRINT(3.5 - 0.5, f);
	DPRINT(5 + 5, d);

	// Aufgabe: 5.3
	/* Vorteile:
	 * Geringe Laufzeit, da der Makroaufruf durch den Ersatztext ersetzt wird und damit keine Stack-Operationen
	 * wie beim Funktionsaufruf notwendig sind.
	 *
	 * Durch die Textersetzung kann ein Makro mit unterschiedlichen Typen aufgerufen werden, wenn der Ausdruck
	 * als Ersatztext mehrere Typen zulässt. Bei Funktionen ist man auf den einen angegebenen Typ eingeschränkt.
	 *
	 * Nachteile:
	 * Kommt ein Parameter im Ersatztext mehrfach vor, muss ggf. auch mehrfach ausgewertet werden.
	 * Beim Funktionsaufruf wird nur einmal ausgewertet.
	 *
	 * Makrodefinitionen sind häufig kompliziert und damit schlechter verständlich.
	 *
	 * Makrodefinitionen werden beim Debuggen nicht aufgelöst.
	 *
	 * Makrodefinitionen haben tendenziell ein Problem mit Programmierrichtlinien und Formatierungsstandrads...
	 *
	 */

	return 0;
}
