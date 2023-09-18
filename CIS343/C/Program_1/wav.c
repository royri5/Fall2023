//a library for working with wave files. It will have the
//code for the functions declared in the wav.h header////

#include "wav.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "file_lib.h"
#include <string.h>

//a function that takes the first 44 bytes of a file's
//contents and creates a header from it////
wav_header* header(char* file_contents_p) {
    //step through file_contents_p and set the header
    //to the first 44 bytes of the file
    wav_header* header_p = malloc(44);
    //copying bytes
    //brute forced after having issues
    //too lazy to change back to memcpy
    header_p->bytes0to3[0] = file_contents_p[0];
    header_p->bytes0to3[1] = file_contents_p[1];
    header_p->bytes0to3[2] = file_contents_p[2];
    header_p->bytes0to3[3] = file_contents_p[3];
    header_p->bytes4to7[0] = file_contents_p[4];
    header_p->bytes4to7[1] = file_contents_p[5];
    header_p->bytes4to7[2] = file_contents_p[6];
    header_p->bytes4to7[3] = file_contents_p[7];
    header_p->bytes8to11[0] = file_contents_p[8];
    header_p->bytes8to11[1] = file_contents_p[9];
    header_p->bytes8to11[2] = file_contents_p[10];
    header_p->bytes8to11[3] = file_contents_p[11];
    header_p->bytes12to15[0] = file_contents_p[12];
    header_p->bytes12to15[1] = file_contents_p[13];
    header_p->bytes12to15[2] = file_contents_p[14];
    header_p->bytes12to15[3] = file_contents_p[15];
    header_p->bytes16to19[0] = file_contents_p[16];
    header_p->bytes16to19[1] = file_contents_p[17];
    header_p->bytes16to19[2] = file_contents_p[18];
    header_p->bytes16to19[3] = file_contents_p[19];
    header_p->bytes20to21[0] = file_contents_p[20];
    header_p->bytes20to21[1] = file_contents_p[21];
    header_p->bytes22to23[0] = file_contents_p[22];
    header_p->bytes22to23[1] = file_contents_p[23];
    header_p->bytes24to27[0] = file_contents_p[24];
    header_p->bytes24to27[1] = file_contents_p[25];
    header_p->bytes24to27[2] = file_contents_p[26];
    header_p->bytes24to27[3] = file_contents_p[27];
    header_p->bytes28to31[0] = file_contents_p[28];
    header_p->bytes28to31[1] = file_contents_p[29];
    header_p->bytes28to31[2] = file_contents_p[30];
    header_p->bytes28to31[3] = file_contents_p[31];
    header_p->bytes32to35[0] = file_contents_p[32];
    header_p->bytes32to35[1] = file_contents_p[33];
    header_p->bytes32to35[2] = file_contents_p[34];
    header_p->bytes32to35[3] = file_contents_p[35];
    header_p->bytes36to39[0] = file_contents_p[36];
    header_p->bytes36to39[1] = file_contents_p[37];
    header_p->bytes36to39[2] = file_contents_p[38];
    header_p->bytes36to39[3] = file_contents_p[39];
    header_p->bytes40to43[0] = file_contents_p[40];
    header_p->bytes40to43[1] = file_contents_p[41];
    header_p->bytes40to43[2] = file_contents_p[42];
    header_p->bytes40to43[3] = file_contents_p[43];
    return header_p;
}

//a function that loads a wave file by calling the read_file
//function from the file library, then takes the returned
///bytes and creates a new wav_file. It must then set the
//header, data size, and pointer to the data section.
//It will then return a pointer to the new wav_file////
wav_file* load_wav_return_new_wav(char* path, size_t* size) {
    char* file_contents = read_file(path, size);
    if(file_contents == NULL) {
        printf("NULL FILE\n");
        exit(1);
    }
    wav_file* new_wav = malloc(*size);
    new_wav->header_p = header(file_contents);
    new_wav->filesize_p = size;
    new_wav->data_p = file_contents + 44;
    return new_wav;
}

//"a function that takes a wav_file and a file path, and
//prepares a byte array of the file. It then calls
//upon our write_file function to write the new audio file
//to disk."////
int write_wav_to_disk(wav_file wav_file, char* path) {
    //preparing byte array
    char* byteArray = malloc(*(wav_file.filesize_p));

    //setting header

    memcpy(byteArray, wav_file.header_p, 44);

    //setting data
    
    memcpy(byteArray + 44, wav_file.data_p, *(wav_file.filesize_p) - 44);
    

    //writing to disk
    write_file(path, byteArray, *(wav_file.filesize_p));

    //freeing
    free(byteArray);

    return 0;
    
}