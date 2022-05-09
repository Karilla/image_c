#include "bitmap.h"

void readFormat(bmpFile* file, uint8_t* buffer){
    memcpy(file->format,buffer,2);
    file->format[2] = '\0';
}

bool isBmpFile(bmpFile* file){
    return !strcmp("BM", (char*)file->format);
}