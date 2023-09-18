//a library for working with wave files. It will have the
//code for the functions declared in the wav.h header////

#include "wav.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "file_lib.h"
#include <string.h>

//"a function that takes the first 44 bytes of a file's
//contents and creates a header from it"
wav_header* header(char* file_contents_p) {

    //allocating memory for header
    wav_header* header_p = malloc(44);

    //copying bytes
    //brute forced after having issues
    //too lazy to change back to memcpy

    //copying memory
    //memcpy(header_p, file_contents_p, 44);

    //setting RIFF section of header with memcpy
    memcpy(header_p->bytes0to3, file_contents_p, 4);
    
    //setting file size - 8 section of header with memcpy
    memcpy(header_p->bytes4to7, file_contents_p + 4, 4);
    
    //setting WAVE section of header
    memcpy(header_p->bytes8to11, file_contents_p + 8, 4);
    
    //setting fmt section of header
    memcpy(header_p->bytes12to15, file_contents_p + 12, 4);
    
    //setting length of format data section of header
    memcpy(header_p->bytes16to19, file_contents_p + 16, 4);
    
    //setting format type section of header
    memcpy(header_p->bytes20to21, file_contents_p + 20, 2);
    
    //setting number of channels section of header
    memcpy(header_p->bytes22to23, file_contents_p + 22, 2);
    
    //setting sample rate section of header
    memcpy(header_p->bytes24to27, file_contents_p + 24, 4);
    
    //setting sample rate * bits per sample section of header
    memcpy(header_p->bytes28to31, file_contents_p + 28, 4);
    
    //setting bits per sample section of header
    memcpy(header_p->bytes32to35, file_contents_p + 32, 4);
    
    //setting data header section of header
    memcpy(header_p->bytes36to39, file_contents_p + 36, 4);
    
    //setting data size section of header
    memcpy(header_p->bytes40to43, file_contents_p + 40, 4);
    return header_p;
}

//"a function that loads a wave file by calling the read_file
//function from the file library, then takes the returned
///bytes and creates a new wav_file. It must then set the
//header, data size, and pointer to the data section.
//It will then return a pointer to the new wav_file"
wav_file* load_wav_return_new_wav(char* path, size_t* size) {
    //loading file via read_file
    //in file_lib
    char* file_contents = read_file(path, size);

    //error checking
    //checking for null file
    if(file_contents == NULL) {
        printf("NULL FILE\n");
        exit(1);
    }
    //checking for correct file size
    if(*size < 44) {
        printf("FILE TOO SMALL\n");
        exit(1);
    }
    //checking for post header data
    if(*size - 44 == 0) {
        printf("NO POST HEADER DATA\n");
        exit(1);
    }


    //allocating memory for new wav_file
    wav_file* new_wav = malloc(*size);

    //copying memory from file_contents to new_wav
    memcpy(new_wav, file_contents, *size);


    //setting header, filesize, and data

    //setting header pointer
    new_wav->header_p = header(file_contents);


    //more error checking
    //checking for correct amount of data after header
    if(*size - 44 != *(unsigned int *)(new_wav->header_p->bytes40to43)) {
        printf("INCORRECT DATA SECTION SIZE\n");
        exit(1);
    }

    //setting filesize pointer
    new_wav->filesize_p = size;
    //setting data pointer to data section without file_contents
    new_wav->data_p = (char *)new_wav->header_p + 44;

    

    //freeing
    free(file_contents);
    return new_wav;
}

//"a function that takes a wav_file and a file path, and
//prepares a byte array of the file. It then calls
//upon our write_file function to write the new audio file
//to disk."
int write_wav_to_disk(wav_file wav_file, char* path) {

    //allocating memory for byte array
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