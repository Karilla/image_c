#ifndef _PNG_H_
#define _PNG_H_
#include <stdint.h>
#include <stdio.h>

typedef struct pngFile{
    char* name;
    uint32_t width;
    uint32_t height;
}pngFile;

typedef uint8_t* pngBuffer;

uint32_t getWidth(pngBuffer buffer);

uint32_t getHeight(pngBuffer buffer);

#endif