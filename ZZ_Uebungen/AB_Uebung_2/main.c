#include <stdio.h>

int main(void)
{
	unsigned char uc = 153;
	char c = uc; // -103
	unsigned int ui = c; // 4294967193
	int i = ui; // -103

	// %d = signed integer (Dezimalzahl)
	// %u = unsigned integer (Dezimalzahl)
	// %x = Hexadezimal

	// %d = signed int (-2^31, 2^31 - 1) 	Ausgabe 153 im Wertebereich (Von unsigned zu signed umgewandelt)
	printf("unsigned char (%%d) : %d\n", uc);
	// %u = unsigned int (0 - 255)	Ausgabe 153 im Wertebereich
	printf("unsigned char (%%u) : %u\n", uc);
	// %x = hexadezimal (binär: 1001 1001) Hex = 99  (unsigned int = 0 - 255, 1 Byte)
	printf("unsigned char (%%x) : %x\n", uc);
	printf("\n");

	// unsigned char 153 (0, 255) zu signed char (-128, 127)		Rechnung: 127 - 153 überlauf in negativ Bereich + 25 = -103
	printf(" signed char (%%d) : %d\n", c);
	// signed int nach unsigned int 	Rechnung: -103 + 4295967295 = 4294967193
	printf(" signed char (%%u) : %u\n", c);
	// signed int nach unsigned int 	Ausgabe in Hexadezimal: FF FF FF 99
	// 11111111 11111111 11111111 10011001
	printf(" signed char (%%x) : %x\n", c);
	printf("\n");

	// c = -103 durch Umwandlung 	Ausgabe: als signed int = -103
	printf("unsigned int (%%d) : %d\n", ui);
	// Umwandlung von char in int	Ausgabe: als unsigned int = 4294967193
	printf("unsigned int (%%u) : %u\n", ui);
	// Umwandlung von char in int	Ausgabe: als Hexadezimal: FF FF FF 99
	printf("unsigned int (%%x) : %x\n", ui);
	printf("\n");

	// ui = -103 durch Umwandlung	Ausgabe: als signed int = -103
	printf(" signed int (%%d) : %d\n", i);
	// Umwandlung von signed int in unsigned int	Ausgabe: als unsigned int = 4294967193
	printf(" signed int (%%u) : %u\n", i);
	// Umwandlung von signed int in unsigned int	Ausgabe: als Hexadezimal: FF FF FF 99
	printf(" signed int (%%x) : %x\n", i);
	printf("\n");

	/*
	 * 153	Datentyp signed int, 4 Bytes, Wertebereich 	[-2^31, 2^31 - 1]
	 * 00000000 00000000 00000000 10011001
	 *
	 * uc	Datentyp unsigned char, 1 Byte, Wertebereich  [0, 255]
	 * 						   	  10011001
	 *
	 * c	Datentyp signed char, 1 Byte, Wertebereich   [-128, 127]
	 * 							  10011001
	 *
	 * ui 	Datentyp unsigned int, 4 Bytes, Wertebereich   [0, 2^32 - 1]
	 * 11111111 11111111 11111111 10011001
	 *
	 * i	Datentyp signed int, 4 Bytes, Wertebereich   [-2^31, 2^31 - 1]
	 * 11111111 11111111 11111111 10011001
	 *
	 */
}

