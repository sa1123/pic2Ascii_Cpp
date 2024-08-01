#include <iostream>
#include <fstream>
#include <ctime>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("t5.jpg", &width, &height, &bpp, 3);

    //   ofstream MyFile("filename.txt");

    for(uint8_t* p = rgb_image, wc = 1; p <= rgb_image + (width * height * bpp); p+=6, wc+=2){
        int curr_pix_val = *p + *(p + 1) + *(p + 2);
        if(curr_pix_val < 80){
            std::cout<<1;
        }else if(curr_pix_val >= 80 && curr_pix_val < 180){
            std::cout<<0;
        }else{
            std::cout<<" ";
        }
        
        if(width == wc){
            std::cout<<"\n";
            wc = 0;
        }
    }

    // std::cout<<(*rgb_image + *(rgb_image + 1) + *(rgb_image + 2))/3;

    return 0;
}