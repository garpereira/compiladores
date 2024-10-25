#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void allocate_buffer(int tamanho_buffer, t_buffer *st_buffer){
	st_buffer->buffer = malloc(tamanho_buffer * sizeof(char));
	st_buffer->tam = tamanho_buffer;
	return;
}

void deallocate_buffer(t_buffer *st_buffer){
	free(st_buffer->buffer);
	return;
}

void replace_print(FILE *file, t_buffer *st_buffer){
	int caractere, i=0;
	while((caractere = fgetc(file)) != EOF){
		if(caractere != '\n'){
			// Se eh vogal então transforma
			// se eh minuscula então maiuscula
			if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u')
				caractere = caractere - 32;
			else if(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U')
				caractere = caractere + 32;

			st_buffer->buffer[i] = caractere;
			i++;
			if(i >= st_buffer->tam){
				i = 0;
				printf("%s", st_buffer->buffer);
				deallocate_buffer(st_buffer);
				allocate_buffer(st_buffer->tam, st_buffer);
			}
		}
	}
	printf("%s", st_buffer->buffer);
}
