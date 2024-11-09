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

    char *next_char;
    t_buffer st_buffer;
    t_lex st_lex;
    allocate_buffer(&st_buffer);
    allocate_lex(&st_lex);
    
    while(fgets(st_buffer.buffer, MAX_BUFFER, file)){
        next_char = get_next_char(&st_buffer);
        do{
            switch (*next_char){
                case 'a' ... 'z': // palavras reservadas são sempre em minúsculo
                    insert_on_lex(&st_lex, next_char);
                    next_char = get_next_char(&st_buffer);
                    automate_reserved_word(&st_lex, &st_buffer, &next_char);
                    break;
                case 'A' ... 'Z':
                    insert_on_lex(&st_lex, next_char);
                    break;
                case '\'': // literal
                    next_char = get_next_char(&st_buffer);
                    automate_literal_single_word(&st_lex, &st_buffer, &next_char);
                    break;
                case '"': // literal
                    next_char = get_next_char(&st_buffer);
                    automate_literal_mult_word(&st_lex, &st_buffer, &next_char);
                    break;
                default:
                    if(st_lex.char_position){
                        is_reserved_word(&st_lex, st_buffer);
                        print_lex(&st_lex);
                    }
                    break;
            }
            // filled the buffer, but doesn't reach the end of the line
            if (next_char == '\0'){
                restart_buffer(&st_buffer);
                if (!fgets(st_buffer.buffer, MAX_BUFFER, file))
                    break;
                next_char = get_next_char(&st_buffer);
            }
            else
                next_char = get_next_char(&st_buffer);

        }while(next_char != '\n'); // reach the end of the line

        st_buffer.char_line_position++;
        restart_buffer(&st_buffer);
    }
    deallocate_buffer(&st_buffer);
    deallocate_lex(&st_lex);
    free(next_char);
    fclose(file);
    return 0;
}