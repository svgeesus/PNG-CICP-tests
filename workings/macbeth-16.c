#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "rec2020.h"

const uint8_t square = 32;
const uint8_t separator = 4;
const uint8_t rows = 4;
const uint8_t columns = 6;

const double bits = 16.0;
// 10, 12, or 16


uint16_t quantize (double value) 
{
    double maxval = pow(2.0, bits) - 1.0;
    return (uint16_t) round(value * maxval);
}

uint16_t background[3];
double bgcolor[3] = {0.126475, 0.126475, 0.126475};

uint16_t coords[4][6][3];

FILE *fptr;

void main() 
{
    // convert floating point component values to quantized integer
    for (uint8_t i = 0; i < rows; i++){
        for (uint8_t j = 0; j < columns; j++){
            for (uint8_t k = 0; k < 3; k++){
                coords[i][j][k] = quantize(colors[i][j][k]);
            }
        }
    }
    // same for background
    for (uint8_t i = 0; i < 3; i++){
        background[i] = quantize(bgcolor[i]);
    }

    fptr = fopen("tmp.ppm", "w");
    fprintf (fptr, "P3\n");
    fprintf (fptr, "%u\n", square * 6 + separator * 7);
    fprintf (fptr, "%u\n", square * 4 + separator * 5);

    fprintf (fptr, "%u\n", (uint16_t)(pow(2.0, bits) - 1.0));
    // top separator
    for (uint8_t i = 0; i < (square * columns + separator * 7); i++){
        for (uint8_t j = 0; j < separator; j++){
            fprintf (fptr, "%u %u %u\n", background[0], background[1], background[2]);
        }
    }
    for (uint8_t row = 0; row < rows; row ++){
        for (uint8_t sq = 0; sq < square; sq ++) {
            // left separator
            for (uint8_t j = 0; j < separator; j++){
                fprintf (fptr, "%u %u %u\n", background[0], background[1], background[2]);
            }   
            for (uint8_t col = 0; col < columns; col ++) {
                for (uint8_t sq2 = 0; sq2 < square; sq2 ++) {
                        fprintf (fptr, "%u %u %u\n", coords[row][col][0], coords[row][col][1], coords[row][col][2]);
                }
                // inter-square separator, to right
                for (uint8_t j = 0; j < separator; j++){
                    fprintf (fptr, "%u %u %u\n", background[0], background[1], background[2]);
                };
            };
            
            fprintf(fptr, "\n");
        };
        // row separator
        for (uint8_t i = 0; i < (square * columns + separator * 7); i++){
            for (uint8_t j = 0; j < separator; j++){
                fprintf (fptr, "%u %u %u\n", background[0], background[1], background[2]);
            };
        };
        fprintf(fptr, "\n");
    };

    fprintf(fptr, "\n");
    fclose(fptr);
}