#include "pixel.h"

void flip_vertically(Pixel *pixel_list, int num_pixels) {
    int max_y = 255;  

    for (int i = 0; i < num_pixels; i++) {
        pixel_list[i].y = max_y - pixel_list[i].y;
    }
}

