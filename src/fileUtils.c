#include "fileUtils.h"

uint8_t* fileToBuffer(char* fileName){
    FILE* fileHandler;
    fileHandler = fopen(fileName, "r");

    uint8_t* buffer;

    if(fileHandler == NULL)
    {
        printf("ERROR OPENING IMAGE\n");
        exit(EXIT_FAILURE);
    }
    
    fseek(fileHandler, 0l, SEEK_END);
    int size = ftell(fileHandler);
    rewind(fileHandler);

    buffer = (uint8_t*)malloc(size * sizeof(uint8_t) + 2);
    if(buffer == NULL){
        printf("Error on memory allocation\n");
        exit(EXIT_FAILURE);
    }
 
    for (int i = 0; i < size; i++) buffer[i] = fgetc(fileHandler);
    fclose(fileHandler);
    return buffer;
}

bool isPNGFile(uint8_t* buffer){
    uint8_t pngFileDesc[8] = {137,80,78,71,13,10,26,10};
    return (memcmp(buffer,pngFileDesc,8) == 0);
}