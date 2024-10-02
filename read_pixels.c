#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pixel.h"

#define MAX_PIXELS 131072  

int read_pixel_data(const char *filename, Pixel **pixel_list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return -1;
    }

    *pixel_list = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
    if (*pixel_list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return -1;
    }

    int x, y;
    float r, g, b;
    int i = 0;
    while (fscanf(file, "%d,%d,%f,%f,%f", &x, &y, &r, &g, &b) == 5) {
        (*pixel_list)[i].x = x;
        (*pixel_list)[i].y = y;
        (*pixel_list)[i].r = r;
        (*pixel_list)[i].g = g;
        (*pixel_list)[i].b = b;
        i++;
    }

    fclose(file);
    return i; 
}

