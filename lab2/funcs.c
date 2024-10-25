#include "funcs.h"

void allocate_buffer(t_buffer *st_buffer){
    st_buffer->buffer = malloc(MAX_BUFFER*sizeof(char));
    if (st_buffer->buffer == NULL){
        printf("Error allocating memory for buffer.\nAborting...");
        exit(1);
    }
    if (!st_buffer->char_line_position)
        st_buffer->char_line_position = 0;
    st_buffer->char_position = 0;
}

void deallocate_buffer(t_buffer *st_buffer){
    free(st_buffer->buffer);
}

void restart_buffer(t_buffer *st_buffer){
    deallocate_buffer(st_buffer);
    allocate_buffer(st_buffer);
}

char get_next_char(t_buffer *st_buffer){
    if (st_buffer->buffer[st_buffer->char_position] == '\0')// end of string
        return '\0';
    if (st_buffer->buffer[st_buffer->char_position] == '\n')// line break
        return '\n';
    return st_buffer->buffer[st_buffer->char_position++];
}