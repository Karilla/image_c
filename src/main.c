#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "fileUtils.h"
#include "png.h"

int main()
{
    uint8_t* buffer = fileToBuffer("./test.png");
    
    if(isPNGFile(buffer)){
        printf("C'est un png !!!\n");
        printf("%d\n",getHeight(buffer));
        getHeight(buffer);
    }
    else{
        printf("Ce n'est pas un png :(\n");
    }
    free(buffer);

    return 0;
}