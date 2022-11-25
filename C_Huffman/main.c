/**
 * Praktikumsaufgabe 4: Huffman - Module
 */

#include <stdio.h>
#include "huffman_common.h"
#include "io.c"
#include "huffman.c"


int main()
{
	unsigned char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char test[] = "";
	char out[50] = {0};
	//test_rd_chars_wr_bits(in, out);
	//strcmp(out, "UUUUUU");

	/*
	for(int i = 0; i < n; i++)
	{
		printf("%c", in[i]);
		test[i] = in[i];
	}
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		printf("%c", test[i]);
	}
	*/

	init_in(in);
	//get_out_buffer(in);
	printf("%c",read_char());

	return 0;
}
