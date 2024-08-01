#include <iostream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int width, height, bpp;

    char const* img_f_name = "r1.png";

    uint8_t* rgb_image = stbi_load(img_f_name, &width, &height, &bpp, 3);

    // char* output_f_name = img_f_name;
    // std::strcat(output_f_name, ".txt");

    std::ofstream MyFile("output.txt");

    for(uint8_t* p = rgb_image, wc = 1; p <= rgb_image + (width * height * bpp); p+=3, wc+=1){
        int curr_pix_val = *p + *(p + 1) + *(p + 2);
        if(curr_pix_val < 80){
            MyFile<<1;
            std::cout<<1;
        }else if(curr_pix_val >= 80 && curr_pix_val < 180){
            MyFile<<0;
            std::cout<<0;
        }else{
            MyFile<<" ";
            std::cout<<" ";
        }
        
        if(width == wc){
            std::cout<<"\n";
            MyFile<<"\n";
            wc = 0;
        }
    }

    MyFile.close();

    return 0;
}