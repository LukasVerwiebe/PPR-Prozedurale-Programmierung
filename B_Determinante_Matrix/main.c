/*
 * PPR-Praktikum: Aufgabe 2 (Determinante)
 * Programm zur Berechnung der Determinante einer Matrix
 * Autor: Lukas Verwiebe
 */
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

/*
 * Funktionsdefinitionen:
 */
// Teilaufgabe 2.1: Berechnung der Determinante
double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size);
// Teilaufgabe 2.2: Ausgabe der Matrix
void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size);
// Hilfsfunktion für Teilaufgabe 2.2:
void gib_Kofaktor(double matrix[MAX_SIZE][MAX_SIZE], double temp[MAX_SIZE][MAX_SIZE], int p, int q, int size);

/**
 * Der Wert der Determinante einer Matrix wird nach folgendem Verfahren berechnet:
 * - Für jedes Element der ersten Zeile oder ersten Spalte muss der Kofaktor dieser Elemente ermittelt werden
 * - Das Element muss mit der Determinante des entsprechenden Kofaktors Multipliziert werden
 * - Danach werden diese wieder hinzugefügt
 */

 /** Rekursive Funktion zum finden der determinante der matrix.
 * size ist die größe von matrix[][].
 * @param matrix
 * @param size
 * @return
 */
double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
	double temp[MAX_SIZE][MAX_SIZE]; // Temp Array
	double ergebnis = 0.0; // Ausgabe Variable
	int i; // Variable der for Schleife
	int multi = 1; // Multiplikator

	//if(size <= 1)
	//{
	//	printf("Die Größe der Matrix ist zu klein es kann keine Berechnung durchgeführt werden.");
	//	return 0;
	//}

	// Wenn die Matrix nur ein Element enthält
	if (size == 1) {
		return matrix[0][0];
	}

	// Schleife für das erste Element der Zeile
	for (i = 0; i < size; i++)
	{
		// Ermittlung des Kofaktor von matrix[0][i] (p und q Angabe der aktuellen Position)
		gib_Kofaktor(matrix, temp, 0, i, size);
		// Berechnung der Determinante mit Rekursiven Aufruf der Funktion
		ergebnis += multi * matrix[0][i] * get_determinant(temp, size - 1);

		// Vorzeichen Änderung des Multiplikators
		multi = -multi;
	}
	return ergebnis;
}

/**
 * Funktion um den Kofaktor von matrix[p][q] in temp[][] zu finden.
 * size ist die größe von matrix[][]
 * @param matrix
 * @param temp
 * @param p
 * @param q
 * @param size
 */
void gib_Kofaktor(double matrix[MAX_SIZE][MAX_SIZE], double temp[MAX_SIZE][MAX_SIZE], int p, int q, int size)
{
	int zeile;
	int spalte;
	int i = 0;
	int j = 0;

	// Durchlauf der einzelnen Elemente der Matrix
	for (zeile = 0; zeile < size; zeile++)
	{
		for (spalte = 0; spalte < size; spalte++)
		{
			/* Die Werte welche nicht in der aktuellen zeile und Spalte vorhanden sind, werden in eine
			 * Temp Matrix abgelegt */
			if (zeile != p && spalte != q)
			{
				temp[i][j++] = matrix[zeile][spalte];
				// Der Zeilen index wird erhöht und der Spalten index wieder zurückgesetzt
				if (j == size - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

/**
 * Funktion zur Ausgabe der Matrix
 * @param matrix
 * @param size
 */
void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
	int i;
	int j;

	// Äußere Schleife für durchlauf der Spalten
	for(i = 0; i < size; i++) {
		// Innere Schleife für durchlauf der Zeilen und der Ausgabe der Matrix
		for(j = 0; j < size; j++) {
			// Ausgabe der Matrix mit einer Nachkommastelle
			printf("%6.1f ", matrix[i][j]);

			// Zeilenumbruch am Ende einer Matrix Zeile
			if(j == size - 1){
				printf("\n");
			}
		}
	}
}

/**
 * Main Funktion zur Eingabe und Ausgabe von Werten in die Funktionen
 * @return
 */
int main(void)
{
	// Testmatrix:
	//double matrix[MAX_SIZE][MAX_SIZE] = {{0.0, 1.0, 2.0}, {3.0, 2.0, 1.0}, {1.0, 1.0, 0.0}};

	// Test: Berechnung der Determinante
	//printf("Determinante: %6.1f\n\n",get_determinant(matrix, 3));

	// Test: Ausgabe der Matrix
	//print_matrix(matrix, 3);

	return 0;
}
