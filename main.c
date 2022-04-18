#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    FILE* fileHandler;

    fileHandler = fopen("test.png", "r");

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

    uint8_t pngFileDesc[8] = {137,80,78,71,13,10,26,10};
    if(memcmp(buffer,pngFileDesc,8) == 0){
        printf("C'est un png !!!\n");
    }
    else{
        printf("Ce n'est pas un png :(\n");
    }

    fclose(fileHandler);
    free(buffer);

    return 0;
}