//
// Created by Lukas on 22.11.2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "huffman_common.h"

#define  GET_BIT(BYTE, POS)
#define PUT_BIT(BYTE, BIT, POS)

static unsigned char in_buffer[BUFSIZ];
static unsigned char out_buffer[BUFSIZ];

static int in_lese;
static int in_schreib;
static int out_lese;
static int out_schreib;

static size_t n;
static size_t m;

static void init_in(char text[]);
static void init_out();
static void get_out_buffer(char text[]);



static void init_in(char text[])
{
	n = strlen(text);
	int i;
	for(i = 0; i < n; i++)
	{
		text[i] = in_buffer[i];
		in_schreib = in_schreib + 1;
	}
	in_lese = 0;
}

static void init_out()
{
	m = 0;
	out_lese = 0;
	out_schreib = 0;
}

static void get_out_buffer(char text[])
{
	int i;
	n = strlen(text);
	for(i = 0; i < n; i++)
	{
		printf("%c", text[i]);
	}
}


bool has_next_char(void)
{
	bool next = false;
	if(out_lese < n)
	{
		next = true;
	}
	return next;
}

unsigned char read_char(void)
{
	char position = 0;
	if(has_next_char()) {
		in_lese = in_lese + 1;
		in_buffer[in_lese] = position;
	}
	return position;
}

void write_char(unsigned char c)
{
	if(m <= out_schreib)
	{
		out_buffer[out_schreib] = c;
		out_schreib = out_schreib + 1;
	}
}


