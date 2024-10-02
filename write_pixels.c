#include <stdio.h>
#include "pixel.h"


void write_flipped_data(const char *filename, Pixel *pixel_list, int num_pixels) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_pixels; i++) {
        fprintf(file, "%d,%d,%f,%f,%f\n",
                pixel_list[i].x,
                pixel_list[i].y,
                pixel_list[i].r,
                pixel_list[i].g,
                pixel_list[i].b);
    }

    fclose(file);
}

