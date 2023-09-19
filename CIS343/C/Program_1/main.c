//test//the core file that will use the libraries I gave you and the
//one you created. The code for reversing the data samples
//should be in this file.////

#include <stdio.h>
#include <stdlib.h>

#include "file_lib.h"
#include "wav.h"

int main(int argc, char** argv) {
    
    //initializing filesize
    size_t size;

    //printing input file name
    printf("Input File: %s\n", argv[1]);

    //error checking for correct number of arguments
    if(argc != 3) {
        printf("Incorrect Number of Arguments.\n");
        exit(1);
    }


    //creating wav file pointer in memory
    //from disk
    wav_file* file_contents_p = load_wav_return_new_wav(argv[1], &size);


    //checks for file criteria

    //checks for 'RIFF' in bytes 0-3
    if( file_contents_p->header_p->bytes0to3[0] != 'R' ||
        file_contents_p->header_p->bytes0to3[1] != 'I' ||
        file_contents_p->header_p->bytes0to3[2] != 'F' ||
        file_contents_p->header_p->bytes0to3[3] != 'F') {
        printf("Incorrect File Type.\n");
        exit(1);
    }

    //checks for file size - 8 in bytes 4-7
    if(*(unsigned int *)(file_contents_p->header_p->bytes4to7) != (size - 8)) {
        printf("Incorrect File Size.\n");
        exit(1);
    } else {
        printf("File Size: %ld\n", size);
        }

    //checks for 'WAVE' in bytes 8-11
    if( file_contents_p->header_p->bytes8to11[0] != 'W' ||
        file_contents_p->header_p->bytes8to11[1] != 'A' ||
        file_contents_p->header_p->bytes8to11[2] != 'V' ||
        file_contents_p->header_p->bytes8to11[3] != 'E') {
        printf("Incorrect File Type.\n");
        exit(1);
    }

    //checks that the file has 2 channels(in bytes 22-23)
    if(*(unsigned short *)(file_contents_p->header_p->bytes22to23) != 2) {
        printf("Incorrect Channel Amount.\n");
        exit(1);
    } else {
        printf("Channel Amount: %d\n",
        *(unsigned short *)(file_contents_p->header_p->bytes22to23));
        }

    //check that the format type is 1(in bytes 20-21)
    if(*(unsigned short *)(file_contents_p->header_p->bytes20to21) != 1) {
        printf("Incorrect Format Type.\n");
        exit(1);
    }

    //print sample rate
    printf("Sample Rate: %d\n", *(unsigned int *)(file_contents_p->header_p->bytes24to27));

    
    //reversing 4 byte length samples/storing in holder

    //allocating memory for holder
    char* holder = malloc(size - 44);
    int i = 0;
    int j = size -1;

    //reversing samples and storing in holder
    while(i < size - 44) {
        holder[i] = file_contents_p->data_p[j-3]; 
        holder[i+1] = file_contents_p->data_p[j-2];
        holder[i+2] = file_contents_p->data_p[j-1];
        holder[i+3] = file_contents_p->data_p[j];
        i += 4;
        j -= 4;
    }
   
    //updating reversed samples in file_contents_p
    file_contents_p->data_p = holder;

    //printing output file name
    printf("Output File: %s\n", argv[2]);

    //writing reversed file to disk
    int error = write_wav_to_disk(*file_contents_p, argv[2]);
    if(error != 0) {
        printf("Error writing to file.\n");
        exit(1);
    }
    //write_wav_to_disk(*file_contents_p, argv[2]);

    //freeing memory
    //free(file_contents_p->data_p);
    free(file_contents_p->header_p);
    free(file_contents_p);
    free(holder);
    return 0;
}
