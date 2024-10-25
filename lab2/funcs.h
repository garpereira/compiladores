#ifndef FUNCS_H
#define FUNCS_H
#define MAX_BUFFER 256

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *buffer;
    int char_position;
    int char_line_position;
}t_buffer;

void allocate_buffer(t_buffer *st_buffer);
void deallocate_buffer(t_buffer *st_buffer);
char get_next_char(t_buffer *st_buffer);
void restart_buffer(t_buffer *st_buffer);

#endif