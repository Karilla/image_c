#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Table of CRCs of all 8-bit messages. */
unsigned long crc_table[256];
   
/* Flag: has the table been computed? Initially false. */
extern int crc_table_computed;

unsigned long update_crc(unsigned long crc, unsigned char *buf,
                            int len);

unsigned long crc(unsigned char *buf, int len);

void make_crc_table(void);

uint8_t* fileToBuffer(char* fileName);

bool isPNGFile(uint8_t* buffer);

#endif