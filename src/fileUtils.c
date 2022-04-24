#include "fileUtils.h"

int crc_table_computed = 0;

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

   
/* Make the table for a fast CRC. */
void make_crc_table(void)
{
  unsigned long c;
  int n, k;
   
    for (n = 0; n < 256; n++) {
      c = (unsigned long) n;
      for (k = 0; k < 8; k++) {
        if (c & 1)
          c = 0xedb88320L ^ (c >> 1);
        else
          c = c >> 1;
      }
      crc_table[n] = c;
    }
    crc_table_computed = 1;
  }
   
   /* Update a running CRC with the bytes buf[0..len-1]--the CRC
      should be initialized to all 1's, and the transmitted value
      is the 1's complement of the final running CRC (see the
      crc() routine below)). */
   
   unsigned long update_crc(unsigned long crc, unsigned char *buf,
                            int len)
   {
     unsigned long c = crc;
     int n;
   
     if (!crc_table_computed)
       make_crc_table();
     for (n = 0; n < len; n++) {
       c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
     }
     return c;
   }
   
   /* Return the CRC of the bytes buf[0..len-1]. */
   unsigned long crc(unsigned char *buf, int len)
   {
     return update_crc(0xffffffffL, buf, len) ^ 0xffffffffL;
   }