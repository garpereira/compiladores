#ifndef FUNCS_H
#define FUNCS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int tam;
	char *buffer;
} t_buffer;

void allocate_buffer(int tamanho_buffer, t_buffer *st_buffer);
void deallocate_buffer(t_buffer *st_buffer);
void replace_print(FILE *file, t_buffer *st_buffer);

#endif