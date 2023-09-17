//a library for working with wave files. It will have the
//code for the functions declared in the wav.h header////

#include "wav.h"


int header(char* file_contents_p) {
    /*struct wav_header header = {
        .bytes0to3 = {'R','I','F','F'},
        .bytes4to7 = {},
        .bytes8to11 = {'W','A','V','E'},
        .bytes12to15 = {'f','m','t',' '},
        .bytes16to19 = {},
        .bytes20to21 = {00000001,00000000},
        .bytes22to23 = {00000010,00000000},
        .bytes24to27 = {},
        .bytes28to31 = {},
        .bytes32to33 = {},
        .bytes34to35 = {},
        .bytes36to39 = {},
        .bytes40to43 = {}
    };*/
    wav_header header = {
        .bytes0to3 = {'R','I','F','F'},
        .bytes4to7 = {},
        .bytes8to11 = {'W','A','V','E'},
        .bytes12to15 = {'f','m','t',' '},
        .bytes16to19 = {},
        .bytes20to21 = {00000001,00000000},
        .bytes22to23 = {00000010,00000000},
        .bytes24to27 = {},
        .bytes28to31 = {},
        .bytes32to33 = {},
        .bytes34to35 = {},
        .bytes36to39 = {},
        .bytes40to43 = {}
    }

    
    
    //scrap all this, just add the proper verification checks
      //and then copy the header from the file s
    //header.bytes0to3 = {'R','I','F','F'};
    //wav_header.bytes0to3[] = {'R','I','F','F'};
    //wav_header.bytes4to7 =
    //int i = 0;
    //char* header_template[44];
    /*while(i < 44) {
        *file_contents_p = 
    }*/
}