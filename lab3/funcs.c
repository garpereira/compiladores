#include "funcs.h"
#include <string.h>

void allocate_buffer(t_buffer *st_buffer){
    st_buffer->buffer = malloc(MAX_BUFFER*sizeof(char));
    if (st_buffer->buffer == NULL){
        perror("Error allocating memory for buffer.\nAborting...");
        exit(0);
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

void allocate_lex(t_lex *st_lex){
    st_lex->lexema = malloc(MAX_BUFFER_LEX*sizeof(char));
    if (st_lex->lexema == NULL){
        perror("Error allocating memory to lexema\nAborting...");
        exit(1);
    }
    st_lex->char_position = 0;
    st_lex->token = 0;
}

void deallocate_lex(t_lex *st_lex){
    free(st_lex->lexema);
}

void restart_lex(t_lex *st_lex){
    deallocate_lex(st_lex);
    allocate_lex(st_lex);
}

void insert_on_lex(t_lex *st_lex, char next_char){
    ((char*)st_lex->lexema)[st_lex->char_position++] = next_char;
}

char get_next_char(t_buffer *st_buffer){
    if (st_buffer->buffer[st_buffer->char_position] == '\0')// end of string
        return '\0';
    if (st_buffer->buffer[st_buffer->char_position] == '\n')// line break
        return '\n';
    return st_buffer->buffer[st_buffer->char_position++];
}

void is_reserved_word(t_lex *st_lex, t_buffer st_buffer){
    for(int i=IF; i < TOKEN_COUNT; i++){
        if(!strcmp(st_lex->lexema, reserved_words[i])){
            st_lex->token = i;
            break;
        }
    }
    st_lex->char_line_position = st_buffer.char_line_position;
}

void print_lex(t_lex *st_lex){
    printf("Linha: %d, Lexema: %s, Token: %d", st_lex->char_line_position, st_lex->lexema, st_lex->token);
    restart_lex(st_lex);
}