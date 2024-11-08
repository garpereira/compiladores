#ifndef FUNCS_H
#define FUNCS_H
#define MAX_BUFFER 256
#define MAX_BUFFER_LEX 64
#include <stdio.h>
#include <stdlib.h>

// https://www.ibm.com/docs/pt-br/debug-for-zos/16.0?topic=programs-c-reserved-keywords
enum tokens{
    ID, // variables names, functions, etc
    NUM, // any number
    COMPARACAO, // < or > or <= or >= or == or !=
    LITERAL, // palavras entre "" ou ''
    IF, ELSE, WHILE, DO, FOR, SWITCH, CASE, BREAK, CONTINUE, RETURN, // reserved words
    INT, CHAR, FLOAT, DOUBLE, LONG, AUTO, EXTERN, REGISTER, STATIC, SIGNED, UNSIGNED, SHORT, // variables types
    CONST, VOLATILE, // variables modifiers
    SIZEOF, //unary operator
    GOTO, // command
    STRUCT, UNION, ENUM, // structs types
    TYPEDEF, // type definer
    VOID, // empty type
    EOF_TOKEN, // end of file
    PERROR, // error
    PACKED, //_Packed
    ASM, // assembly instructions
    TOKEN_COUNT, // total tokens
};

char *reserved_words[TOKEN_COUNT] = {
    [IF]           = "if",
    [ELSE]         = "else",
    [WHILE]        = "while",
    [DO]           = "do",
    [FOR]          = "for",
    [SWITCH]       = "switch",
    [CASE]         = "case",
    [BREAK]        = "break",
    [CONTINUE]     = "continue",
    [RETURN]       = "return",
    [INT]          = "int",
    [CHAR]         = "char",
    [FLOAT]        = "float",
    [DOUBLE]       = "double",
    [LONG]         = "long",
    [AUTO]         = "auto",
    [EXTERN]       = "extern",
    [REGISTER]     = "register",
    [STATIC]       = "static",
    [SIGNED]       = "signed",
    [UNSIGNED]     = "unsigned",
    [SHORT]        = "short",
    [CONST]        = "const",
    [VOLATILE]     = "volatile",
    [SIZEOF]       = "sizeof",
    [GOTO]         = "goto",
    [STRUCT]       = "struct",
    [UNION]        = "union",
    [ENUM]         = "enum",
    [TYPEDEF]      = "typedef",
    [VOID]         = "void",
    [EOF_TOKEN]    = "EOF",
    [PERROR]       = "perror",
    [PACKED]       = "_Packed",
    [ASM]          = "asm"
};

typedef struct{
    char *buffer; 
    int char_position;
    int char_line_position;
}t_buffer;

typedef struct{
    void *lexema;
    int char_position;
    int char_line_position;
    enum tokens token;
}t_lex;

void allocate_buffer(t_buffer *st_buffer);
void deallocate_buffer(t_buffer *st_buffer);
char get_next_char(t_buffer *st_buffer);
void restart_buffer(t_buffer *st_buffer);
void allocate_lex(t_lex *st_lex);
void restart_lex(t_lex *st_lex);
void insert_on_lex(t_lex *st_lex, char next_char);
void is_reserved_word(t_lex *st_lex);
void print_lex(t_lex *st_lex);

#endif