#include "funcs.h"

int main(int argc, char const *argv[]){
	if(argc != 3)
		return 1;
	FILE *file = fopen(argv[1], "r");
	if (file == NULL){
		return 1;
	}

	t_buffer st_buffer;
	allocate_buffer(atoi(argv[2]), &st_buffer);
	replace_print(file, &st_buffer);
	deallocate_buffer(&st_buffer);
	fclose(file);
	return 0;
}