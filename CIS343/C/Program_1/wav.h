//a header for the wave file library that includes:////

//a struct for a wave file header/////
#include <stddef.h>
typedef struct wav_header {
    //byte segments in header

    //RIFF section of header
    char bytes0to3[4];
    //file size - 8
    char bytes4to7[4];
    //WAVE section of header
    char bytes8to11[4];
    //fmt section of header(unchecked)
    char bytes12to15[4];
    //length of format data(unchecked)
    char bytes16to19[4];
    //format type(should be 1)
    char bytes20to21[2];
    //number of channels(should be 2)
    char bytes22to23[2];
    //sample rate(unchecked but printed)
    char bytes24to27[4];
    //sample rate * bits per sample(unchecked)
    char bytes28to31[4];
    //bits per sample(unchecked)
    char bytes32to35[4];
    //data header(unchecked)
    char bytes36to39[4];
    //data section size(unchecked except for errors)
    char bytes40to43[4];

} wav_header;

//a struct for a wav_file that has a pointer to the header,
//file size, and a pointer to the data////
typedef struct wav_file {
    //pointer to header
    wav_header* header_p;

    //pointer to file size
    size_t* filesize_p;

    //pointer to data section
    char* data_p;
} wav_file;

//a function that takes the first 44 bytes of a file's
//contents and creates a header from it////
wav_header* header(char* file_contents_p);

//a function that loads a wave file by calling the read_file
//function from the file library, then takes the returned
///bytes and creates a new wav_file. It must then set the
//header, data size, and pointer to the data section.
//It will then return a pointer to the new wav_file////
wav_file* load_wav_return_new_wav(char* path, size_t* size);

//a function that takes a wav_file and a file path, and
//prepares a byte array of the file. It then calls
//upon our write_file function to write the new audio file
//to disk.////
int write_wav_to_disk(wav_file wav_file, char* path);