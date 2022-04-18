#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t* fileToBuffer(char* fileName);

bool isPNGFile(uint8_t* buffer);

#endif