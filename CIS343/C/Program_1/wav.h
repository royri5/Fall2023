//a header for the wave file library that includes:////

//a struct for a wave file header/////
typedef struct wav_header {
    char header[44];
    char bytes0to3[4];
    char bytes4to7[4];
    char bytes8to11[4];
    char bytes12to15[4];
    char bytes16to19[4];
    char bytes20to21[2];
    char bytes22to23[2];
    char bytes24to27[4];
    char bytes28to31[4];
    char bytes32to33[2];
    char bytes34to35[2];
    char bytes36to39[4];
    char bytes40to43[4];
} wav_header;

//struct wav_header

//a struct for a wav_file that has a pointer to the header,
//file size, and a pointer to the data////
struct wav_file {
    char* header_p;
    char* filesize_p;
    char* data_p;
    //
};

//a function that takes the first 44 bytes of a file's
//contents and creates a header from it////
int header(char*);
    //file_contents_p

//a function that loads a wave file by calling the read_file
//function from the file library, then takes the returned
///bytes and creates a new wav_file. It must then set the
//header, data size, and pointer to the data section.
//It will then return a pointer to the new wav_file////
char* load_wav_return_new_wav(char*);
    //file_path

//a function that takes a wav_file and a file path, and
//prepares a byte array of the file. It then calls
//upon our write_file function to write the new audio file
//to disk.////
int write_wav_to_disk(char*, char*);
    //wav_file
    //file_path

//