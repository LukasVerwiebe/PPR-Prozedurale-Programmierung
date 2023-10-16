#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

// Aufgabe: 3.1: Lösung
#define ULAM_MAX ((INT_MAX - 1)/3)

// Aufgabe: 3.1
int ulam_max(int a0);
// Aufgabe: 3.3
void print_binary(unsigned char byte);
bool is_set(unsigned char byte, short pos);
unsigned char set_bit(unsigned char byte, short pos);
unsigned char delete_bit(unsigned char byte, short pos);
unsigned char invert_bits(unsigned char byte, short pos);
unsigned char rotate_bits(unsigned char byte, short count);
bool is_power_of_two(unsigned  int n);


int test(void);


int main()
{
	// Aufgabe: 3.1
	//printf("%i\n", ulam_max(62270208007));
	printf("%i\n", ulam_max(5));

	// Aufgabe: 3.2 a)
	int v1[][3] = {1, 3, 5, 2, 4};
	/*
	 * Größe des Speicherbereichs des Mehrdimensionalen Vektors:
	 * sizeof(int) = 4 Byte
	 * 4 Byte * 3 Anzahl Spalten * 2 Anzahl Zeilen = 24 Bytes (+ 4 Bytes für die Startadresse)
	 *
	 * anzahl_bytes=sizeof(array_typ)*array_laenge
	 *
	 * Die 1 Dimension kann weggelassen werden, weil bei der Initialisierung so viele Zeilen
	 * (mit der angegebenen Spaltenzahl) gefüllt werden wie nötig.
	 * Ein Vektor kann bei seiner Definition explizit initialisiert werden.
	 *
	 * vector[i][j]
	 * Adresse = Startadresse von vector + i * Spaltenanzahl * sizeof(Typ) + j * sizeof(Typ)
	 */

	// Aufgabe: 3.2 b)
	int v2[2][3][4];
	/*
	 * 96 aufeinander folgende Bytes
	 *
	 *	V2[1][2][2] |++++||++++||++++|  |++++||++++||++++|
	 * 	V2[1][2]	|----------------| 	|----------------|
	 *	v2[1]		|------------------------------------|
	 */

	// Aufgabe: 3.2 c)
	// typ v[d1][d2][d3];
	// 	   v[i1][i2][i3];
	/*
	 * Rechteckformel: (d1 wird in der Rechteckformel nicht benötigt
	 * Startadresse von v
	 * + i1 * d2 * d3 * sizeof(typ)
	 * + i2 	 * d3 * sizeof(typ)
	 * + i3 	 	  * sizeof(typ)
	 *
	 * Überprüfung mit v2[1][2][2]
	 * Startadresse von v
	 * + 1 * 3 * 4 * sizeof(int)	= 48
	 * + 2     * 4 * sizeof(int)	= 32
	 * + 2		   * sizeof(int)	= 8
	 * 								-----
	 * 								  88
	 */

	// Aufgabe: 3.3 a)
	print_binary(22);
	print_binary('A');
	// Aufgabe: 3.3 b)
	printf("%s\n", is_set(22, 2) ? "true" : "false");
	// Aufgabe: 3.3 c)
	set_bit(22, 4);
	print_binary(set_bit(22, 0));
	print_binary(set_bit(22, 3));
	// Aufgabe: 3.3 d)
	delete_bit(22, 2);
	print_binary(delete_bit(22, 2));
	// Aufgabe: 3.3 e)
	invert_bits(22, 1);
	print_binary(invert_bits(22, 1));


	// Aufgabe: 3.3 g)
	printf("%s\n", is_power_of_two(32) ? "true" : "false");
	printf("%s\n", is_power_of_two(31) ? "true" : "false");
	printf("\n");

	char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
	char **cp[] = {c+3, c+2, c+2, c};
	char ***cpp = cp;

	printf("**++cpp: %s\n", **++cpp);
	printf("\n");
	//printf("*--cpp: %s\n", *--cpp);
	//printf("*--*cpp: %s\n", *--*cpp);
	//printf("**++cpp: %s\n", **++cpp);
	//printf("*--*cpp: %s\n", *--*cpp);
	//printf("*--*++cpp: %s\n", *--*++cpp);
	printf("*--*++cpp+3: %s\n", *--*++cpp+3);
	printf("\n");
	//printf("*cpp: %s\n", **cpp);
	printf("*cpp[-2]: %s\n", *cpp[1]);
	printf("*cpp[-2]+3: %s\n", *cpp[-2]+3);
	printf("\n");
	//printf("cpp[-1]: %s\n", cpp[-1]);
	//printf("cpp[-1][-1]: %s\n", cpp[-1][-1]);
	printf("cpp[-1][-1]+1: %s\n", cpp[-1][-1]+1);

	printf("%d", test());

	return 0;
}

// Aufgabe: 3.1
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
			// Aufgabe: 3.1: Lösung
			if(a0 <= ULAM_MAX)
			{
				a0 = a0 * 3 + 1;
			}
			else
			{
				return -1;
			}
		}

		if(a0 > storage)
		{
			storage = a0;
		}
	}

	return storage;
}

// Aufgabe: 3.3 a)
void print_binary(unsigned char byte)
{
	// Hexadezimale Darstellung: 0x80 = 8 Bit Ausgabe (8 Bit = 1 Byte)
	// Bit-Verschiebung nach rechts um ein 1 Bit
	// 128	/200	0x80	1 0 0 0   0 0 0 0
	for(unsigned char mask = 0x80u; mask > 0; mask = mask >> 1)
	{
		// byte(22) =  0 0 0 1   0 1 1 0   mask = 1 0 0 0   0 0 0 0
		// 1 Bit & 1 = 1 Bit, 1 Bit & 0 = 0
		// 4 Durchlauf: byte(22) =  0 0 0 1   0 1 1 0  &  mask = 0 0 0 1   0 0 0 0 = 0 0 0 1   0 0 0 0 | Ausgabe: 1
		printf("%d", ((byte & mask) == mask) ? 1 : 0);
	}
	printf("\n");

	/*
	a: 10 dez => 1010 binär
	b:  7 dez => 0111 binär

				1010
	      UND   0111
	          -----------
			    0010

	c: 10 binär => 2 dezimal
	*/
}

// Aufgabe: 3.3 b)
bool is_set(unsigned char byte, short pos)
{
	return ((0x01 << pos) & byte) > 0;
	/*
	 * (0x01 << pos)
	 * erzeugt eine Maske mit lauter Nullen und einer Eins an der Position pos (von rechts)
	 *
	 * ((0x01 << pos) & byte)
	 * VerUNDung liefert die Maske, wenn das Bit an der Position pos gesetzt ist
	 */
}

// Aufgabe: 3.3 c)
unsigned char set_bit(unsigned char byte, short pos)
{
	// Bitweise "oder": 0101 | 0011 = 0111
	// 0x01 = 0 0 0 0   0 0 0 1 | byte(22) 0 0 0 1   0 1 1 0
	// pos(0) = 0 0 0 1    0 1 1 1
	// pos(3) = 0 0 0 1    1 1 1 0
	return (0x01 << pos) | byte;
}

// Aufgabe: 3.3 d)
unsigned char delete_bit(unsigned char byte, short pos)
{
	// ~ Bitweises Komplement (~ 0101 = 1010)
	// 0x01 = 0 0 0 0   0 0 0 1     byte(22) 0 0 0 1   0 1 1 0
	// pos(2) = 0 0 0 0    0 1 0 0
	// ~ 0 0 0 0    0 1 0 0 = 1 1 1 1    1 0 1 1
	// 1 1 1 1    1 0 1 1 	& 	 0 0 0 1   0 1 1 0 	  = 	0 0 0 1   0 0 1 0
	return ~(0x01 << pos) & byte;
}

// Aufgabe: 3.3 e)
unsigned char invert_bits(unsigned char byte, short pos)
{
	/* XOR-Gatter
	 *  A B |
	 *  0 0 | 0
	 *  0 1 | 1
	 *  1 0 | 1
	 *  1 1 | 0
	 *
	 *  0x01 = 0 0 0 0   0 0 1 0 ^ byte(22) 0 0 0 1   0 1 1 0   =   0 0 0 1   0 1 0 0
	 *  invertiert: 1 1 1 0   1 0 1 1
	 */
	return ~((0x01 << pos) ^ byte);
}

// Aufgabe: 3.3 f)
unsigned char rotate_bits(unsigned char byte, short count)
{

	return (byte >> count) | (byte << (8 - count));
}

// Aufgabe: 3.3 g)
bool is_power_of_two(unsigned  int n)
{
	/*	n(32) = 0 0 1 0   0 0 0 0
	 * 	n-1   = 0 0 0 1   1 1 1 1
	 *
	 *  n & n-1 = 0 0 0 0   0 0 0 0
	 *
	 *  8 = 0 0 0 0   1 0 0 0
	 *  7 = 0 0 0 0   0 1 1 1
	 *  & = 0 0 0 0   0 0 0 0
	 *
	 *  7 = 0 0 0 0   0 1 1 1
	 *  6 = 0 0 0 0   0 1 1 0
	 *  & = 0 0 0 0   0 1 1 0
	 */
	return n != 0 && ((n & (n - 1)) == 0x00);
}

int test()
{
	return -1;
}