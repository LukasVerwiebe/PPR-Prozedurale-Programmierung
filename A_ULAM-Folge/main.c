/*
 * PPR-Praktikum: Aufgabe 1 (ULAM-Folge)
 * Programm zur Berechnung der ULAM-Folge
 * Autor: Lukas Verwiebe
 */
#include <stdio.h>

/**
 * Funktionsdefinition:
 */
// Teilaufgabe 1.1:
int ulam_max(int a0);
// Teilaufgabe 1.2:
int ulam_twins(int limit);
// Teilaufgabe 1.3:
int ulam_multiples(int limit, int number);

/**
 * Teilaufgabe 1.1: C-Funktion zur Ausgabe des maximalen Wertes in der ULAM-Folge.
 * Die Funktion berechnet die Zahlen der Folge und überschreibt den Integer zwischenspeicher jedes Mal,
 * wenn die berechnete Zahl größer als die vorherige Zahl ist. Dieser wird dann als Ergebnis ausgegeben.
 *
 * Sollte die berechnete oder eingegebene Zahl kleiner oder gleich 0 sein wird als Rückgabe Wert die -1 zurückgegeben
 * und die Schleife wird gestoppt.
 * @param a0
 * @return
 */
int ulam_max(int a0)
{
	// Zwischenablage für die Werte:
	int rechnung = a0;
	int zwischenspeicher = a0;

	// Werte unter 0 abfangen und Programm beenden
	if(a0 <= 0)
	{
		return -1;
	}

	// Schleife: Läuft, solange, bis die Berechnung bei 1 angekommen ist
	for (int i = 1; i < rechnung; i++)
	{
		// Prüfen ob ZAhl Gerade oder nicht
		if (rechnung % 2 == 0)
		{
			// Wenn Gerade durch 2 teilen
			rechnung = rechnung / 2;
			// Wenn die Zahl größer ist, als die bereits gespeichert wird diese überschrieben
			if (rechnung > zwischenspeicher)
			{
				zwischenspeicher = rechnung;
			}
		}
		else
		{
			// Wenn ungerade Zahl mal 3 Plus 1
			rechnung = 3 * rechnung + 1;
			// Wenn die Zahl größer ist als die bereits gespeichert wird diese überschrieben
			if (rechnung > zwischenspeicher)
			{
				zwischenspeicher = rechnung;
			}
		}
	}
	// Rückgabe des Maximalwertes der Folge
	return zwischenspeicher;
}

/**
 * Teilaufgabe 1.2: C-Funktion die prüft, ob es im Intervall von 1 bis einschließlich limit zwei benachbarte
 * Werte a0 und a0 + 1 gibt. Ein solches Paar wird als ULAM-Zwilling bezeichnet.
 *
 * Die Funktion soll a0 liefern, wenn ein Paar gefunden wurde und a0 der kleinere Wert in einem solchen Paar ist.
 * Sind mehrere Paare im Intervall enthalten, soll das letzte Paar gesucht werden. Die Funktion soll -1 zurückgeben,
 * wenn kein solches Zwillingspaar gefunden wurde:
 * @param limit
 * @return
 */
int ulam_twins(int limit)
{
	// Zwischenablage für die Werte:
	int zwischenspeicher = -1;
	int speicher1 = 0;
	int speicher2 = 0;

	// Werte unter 0 abfangen und Programm beenden
	if(limit <= 0)
	{
		return -1;
	}

	// Äußere Schleife: Durchlauf des Intervalls darin Vergleich der nachfolgenden Werte
	for (int i = 1; i < limit; i++)
	{
		// Berechnung Start Max Wert
		speicher1 = ulam_max(i);
		// Berechnung benachbarter Max Wert
		speicher2 = ulam_max(i + 1);

		// Prüfung ob Werte gleich und ob die Zahlen benachbart sind, wenn, ja dann Wert setzten
		if (speicher2 == speicher1)
		{
			zwischenspeicher = i;
		}
	}
	// Rückgabe von a0
	return zwischenspeicher;
}

/**
 * Teilaufgabe 1.1: C-Funktion die prüft, ob im Intervall von 1 bis einschließlich limit ULAM-Mehrlinge mit
 * der Anzahl number vollständig enthalten sind.
 *
 * Die Funktion soll a0 liefern, wenn Mehrlinge gefunden wurden und a0 der kleinste Wert ist, der zu den Mehrlingen
 * gehört. Sind weitere Mehrlingsgruppen vollständig im Intervall enthalten, soll der kleinste Wert der letzten Gruppe
 * zurück gegeben werden. Die Funktion soll -1 zurückgeben, wenn die Parameter nicht sinnvoll sind oder keine solchen
 * Mehrlinge gefunden wurden.
 * @param limit
 * @param number
 * @return
 */
int ulam_multiples(int limit, int number)
{
	// Zwischenablage für die Werte:
	int zwischenspeicher = -1;
	int speicher1;
	int speicher2;
	int zaehler;

	// Äußere Schleife: Steuerung des Zählers
	for (int i = 1; i < limit - number + 2; i++)
	{
		zaehler = 1;
		// Innere Schleife: Prüfung der einzelnen Stellen und Speicherung wenn Anzahl korrekt
		for (int j = 1; j < number; j++)
		{
			// Berechnung Start Max Wert
			speicher1 = ulam_max(i);
			// Berechnung benachbarter Max Wert
			speicher2 = ulam_max(i + j);

			// Prüfung ob Werte gleich und ob die Zahlen benachbart sind, wenn, ja dann Wert setzten
			if (speicher2 == speicher1)
			{
				// Zähler erhöhen für Vergleich mit number
				zaehler = zaehler + 1;
			}
			// Prüfung ob der Zähler gleich der eingegebenen Anzahl ist
			if (zaehler == number)
			{
				// Wert für die Rückgabe ablegen
				zwischenspeicher = i;
			}
		}
	}
	// Rückgabe von a0
	return zwischenspeicher;
}

/**
 * Main Funktion zur Eingabe und Ausgabe von Werten in die Funktionen
 * @return
 */
int main(void)
{
	//printf("\n%d",ulam_max(3));
	//printf("\n%d",ulam_max(5));
	//printf("\n%d",ulam_max(7));
	//printf("\n%d",ulam_max(-3));
	//printf("\n%d",ulam_max(11));
	//printf("\n%d",ulam_max(70));
	//printf("\n%d",ulam_max(1));
	//printf("\n%d",ulam_max(2));
	//printf("\n%d",ulam_max(4));

	//printf("\n%d", ulam_twins(6));
	//printf("\n%d", ulam_twins(5));
	//printf("\n%d", ulam_twins(70));
	//printf("\n%d", ulam_twins(1000));

	//printf("\n%d", ulam_multiples(10, 2));
	//printf("\n%d", ulam_multiples(1000, 3));
	//printf("\n%d", ulam_multiples(108, 3));
	//printf("\n%d", ulam_multiples(391, 6));
	//printf("\n%d", ulam_multiples(110, 4));
	//printf("\n%d", ulam_multiples(111, 4));
	return 0;
}
