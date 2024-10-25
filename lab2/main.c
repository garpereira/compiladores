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
    char next_char;
    t_buffer st_buffer;
    allocate_buffer(&st_buffer);
    
    while(fgets(st_buffer.buffer, MAX_BUFFER, file)){
        next_char = get_next_char(&st_buffer);
        do{
            printf("\nO que deseja fazer com o char (%c)?\n", next_char);
            printf("1 - Printar\n2 - Nada\nR: ");
            scanf("%d", &option);
            switch (option){
                case 1:
                    printf("PRINTOU -> %c\n", next_char);
                    break;
                case 2:
                    st_buffer.char_position--;
                    break;
                default:
                    printf("Digite uma opcao valida\n");
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