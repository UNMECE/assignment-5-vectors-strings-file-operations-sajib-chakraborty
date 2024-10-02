#include <stdio.h>
#include "pixel.h"


void average_colors(Pixel *pixel_list, int num_pixels) {
    float r_sum = 0.0, g_sum = 0.0, b_sum = 0.0;

    for (int i = 0; i < num_pixels; i++) {
        r_sum += pixel_list[i].r;
        g_sum += pixel_list[i].g;
        b_sum += pixel_list[i].b;
    }

    float r_avg = r_sum / num_pixels;
    float g_avg = g_sum / num_pixels;
    float b_avg = b_sum / num_pixels;

    printf("Average R: %f\n", r_avg);
    printf("Average G: %f\n", g_avg);
    printf("Average B: %f\n", b_avg);
}

