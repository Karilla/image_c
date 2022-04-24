#include "png.h"

uint32_t getWidth(pngBuffer buffer){
//16 17 18 19
    uint32_t width = 0;
    for(int i = 0; i < 4; i++){
        width = width | buffer[16 + i];
        if(i != 3){
            width = width << 8;
        }
    }
    return width;
}

uint32_t getHeight(pngBuffer buffer){
//20 21 22 23
    uint32_t height = 0;
    for(int i = 0; i < 4; i++){
        height |= buffer[20 + i];
        if(i != 3){
            height = height << 8;
        }
    }
    return height;
}