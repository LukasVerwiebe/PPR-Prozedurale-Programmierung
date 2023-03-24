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


int ulam_multiples_1(int limit, int number);
int ulam_multiples_2(int limit, int number);


/**
 * Main Funktion zur Eingabe und Ausgabe von Werten in die Funktionen
 * @return
 */
int main()
{
	printf("%i\n", ulam_max(5));
	printf("%i\n", ulam_max(7));
	printf("\n");
	printf("%i\n", ulam_twins(6));
	printf("%i\n", ulam_max(6));
	printf("%i\n", ulam_max(5));
	printf("%i\n", ulam_twins(5));
	printf("\n");
	printf("%i\n", ulam_multiples(10, 2));
	printf("%i\n", ulam_multiples(1000, 3));
	printf("%i\n", ulam_multiples(108, 3));
	printf("%i\n", ulam_multiples(391, 6));
	printf("\n");
	printf("%i\n", ulam_multiples_2(10, 2));
	printf("%i\n", ulam_multiples_2(1000, 3));
	printf("%i\n", ulam_multiples_2(108, 3));
	printf("%i\n", ulam_multiples_2(391, 6));

	return 0;
}

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
	int storage = 0;

	if(a0 <= 0)
	{
		return -1;
	}

	while(a0 > 1)
	{
		if(a0 > 1 && a0 % 2 == 0)
		{
			a0 = a0 / 2;
		}
		else if(a0 > 0 && a0 % 2 != 0)
		{
			a0 = a0 * 3 + 1;
		}

		if(a0 > storage)
		{
			storage = a0;
		}
	}

	return storage;
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
	int storage = -1;
	int limit_value = 1;

	if(limit < 0)
	{
		return -1;
	}

	while(limit_value < limit)
	{
		if(ulam_max(limit_value) == ulam_max(limit_value + 1))
		{
			storage = limit_value;
		}
		limit_value = limit_value + 1;
	}

	return storage;
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
	int storage = -1;
	int storage_1;
	int storage_2;
	int value;
	int i;
	int j;

	// Äußere Schleife: Steuerung des Zählers
	for (i = 1; i < limit - number + 2; i++)
	{
		value = 1;
		// Innere Schleife: Prüfung der einzelnen Stellen und Speicherung wenn Anzahl korrekt
		for (j = 1; j < number; j++)
		{
			// Berechnung Start Max Wert
			storage_1 = ulam_max(i);
			// Berechnung benachbarter Max Wert
			storage_2 = ulam_max(i + j);

			// Prüfung ob Werte gleich und ob die Zahlen benachbart sind, wenn, ja dann Wert setzten
			if (storage_2 == storage_1)
			{
				// Zähler erhöhen für Vergleich mit number
				value = value + 1;
			}
			// Prüfung ob der Zähler gleich der eingegebenen Anzahl ist
			if (value == number)
			{
				// Wert für die Rückgabe ablegen
				storage = i;
			}
		}
	}
	// Rückgabe von a0
	return storage;
}



/**
 * Musterlösungen aus der Vorlesung
 */

int ulam_multiples_1(int limit, int number)
{
	int multiples_index = -1;
	int i;
	int j;
	int count;

	if(limit < 1 || number <= 1)
	{
		return -1;
	}

	for(i = 1; i < limit - number + 2; i++)
	{
		count = 1;
		for(j = 1; j < number; j++)
		{
			if(ulam_max(i) == ulam_max(i + j))
			{
				count++;
			}
		}
		if(count == number)
		{
			multiples_index = i;
		}
	}

	return multiples_index;
}

int ulam_multiples_2(int limit, int number)
{
	int ulam_max_1;
	int ulam_max_2;
	int count;
	int multiples_index;
	int i;

	if(number <= 1 || limit < number)
	{
		return -1;
	}

	multiples_index = -1;

	ulam_max_1 = ulam_max(limit);
	count = 1;
	for(i = limit - 1; i >= 0 && multiples_index == -1; i--)
	{
		ulam_max_2 = ulam_max(i);
		if(ulam_max_1 == ulam_max_2)
		{
			count += 1;
		}
		else
		{
			ulam_max_1 = ulam_max_2;
			count = 1;
		}

		if(count == number)
		{
			multiples_index = i;
		}
	}
	return multiples_index;
}