#ifndef _BITMAP_H_
#define _BITMAP_H_
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct bmpFile{
    int size;
    int height;
    int width;
    char format[3];
    uint8_t* buffer;
}bmpFile;

void readFormat(bmpFile* file, uint8_t* buffer);

bool isBmpFile(bmpFile* file);

#endif