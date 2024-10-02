#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"
#include "read_pixels.c"
#include "average_colors.c"
#include "flip_vertically.c"
#include "write_pixels.c"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = "flipped.dat";


    Pixel *pixel_list;
    int num_pixels = read_pixel_data(input_file, &pixel_list);
    if (num_pixels < 0) {
        return 1;
    }

    average_colors(pixel_list, num_pixels);

    flip_vertically(pixel_list, num_pixels);

    write_flipped_data(output_file, pixel_list, num_pixels);

    free(pixel_list);

    return 0;
}

