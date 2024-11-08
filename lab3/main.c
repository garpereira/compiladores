#include "funcs.h"

int main(int argc, char **argv){
    if(argc != 2){
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Error loading file!\nAborting...");
        return 1;
    }

    int option;
    char *next_char;
    t_buffer st_buffer;
    t_lex st_lex;
    allocate_buffer(&st_buffer);
    allocate_lex(&st_lex);
    
    while(fgets(st_buffer.buffer, MAX_BUFFER, file)){
        next_char = get_next_char(&st_buffer);
        do{
            // lí o char, agora preciso ir lendo enquanto eu não identificar um char que quebre(espaço, \n, ;)
            printf("\nO que deseja fazer com o char (%c)?\n", next_char);
            printf("1 - Printar\n2 - Nada\nR: ");
            scanf("%d", &option);
            // preciso verificar se o char é algum tipo de quebra, se for, então eu vou verificar o buffer outro
            // e identificar a qual token o lexema encontrado pertence, jogar ele na struct e imprimir
            // se não for, então vou atribuir ele em um outro buffer
            switch (*next_char){
                case ';':
                case ',':
                case '=':
                case '+':
                case '-':
                case '/':
                case ' ':
                case '<':
                case '>':
                case '!':
                case '|':
                case ':': 
                case '{':
                case '}':
                case '(':
                case ')':
                case '[':
                case ']':// vou pegar a string que esta acumulada no buffer e vou ver se é palavra reservada
                    if(st_lex.char_position)
                        is_reserved_word(&st_lex);
                    break;
                case '\'':
                    do{
                        next_char = get_next_char(&st_buffer);
                        insert_on_lex(&st_lex, next_char);
                    }while(next_char != '\'');
                    break;
                case '"': 
                    do{
                        next_char = get_next_char(&st_buffer);
                        insert_on_lex(&st_lex, next_char);
                    }while(next_char != '"');
                    break;
                default: // se nao for nenhuma quebra, então o padrao vai ser atribuir a letra no buffer
                    insert_on_lex(&st_lex, next_char);
                    break;
            }
            next_char = get_next_char(&st_buffer);
            // filled the buffer, but doesn't reach the end of the line
            if (next_char == '\0'){
                restart_buffer(&st_buffer);
                if (!fgets(st_buffer.buffer, MAX_BUFFER, file))
                    break;
                next_char = get_next_char(&st_buffer);
            }

        }while(next_char != '\n'); // reach the end of the line

        st_buffer.char_line_position++;
        restart_buffer(&st_buffer);
    }
    deallocate_buffer(&st_buffer);
    fclose(file);
    return 0;
}