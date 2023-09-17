//the core file that will use the libraries I gave you and the
//one you created. The code for reversing the data samples
//should be in this file.////

#include <stdio.h>
#include <stdlib.h>

#include "file_lib.h"

/*int main(int argc, char** argv) {
    size_t size;
    char* contents = read_file(argv[1], &size);
    if(contents == NULL) {
        printf("Sorry yo.\n");
        exit(1);
    }
    //printf("%s\n", contents);
    char* reversed = malloc(size);

    size_t count = 0;
    for(int i=size - 1; i > 0; --i){
        // *(reversed + count++) = *(contents + i)
        // same as below
        reversed[count++] = contents[i];
    }

    /*for(beginning; end; ++4){
        for(0; <4; ++1){

        }
    }*/

   /* int success = write_file(argv[2], reversed, size);

    //file_lib_cleanup()
    free(contents);
    free(reversed);
}*/