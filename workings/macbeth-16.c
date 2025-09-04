#include <stdio.h>
#include rec2020.h

const uint8_t square = 32;
const uint8_t separator = 4;
const uint8_t rows = 4;
const uint8_t columns = 6;

uint8_t background[3] = {20, 20, 20};
// color(rec2020 0.126475 0.126475 0.126475)

FILE *fptr;

void main() 
{
    fptr = fopen("tmp.ppm", "w");
    fprintf (fptr, "P3\n");
    fprintf (fptr, "%u\n", square * 6 + separator * 7);
    fprintf (fptr, "%u\n", square * 4 + separator * 5);

    fprintf (fptr, "%u\n", 255);
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
                        fprintf (fptr, "%u %u %u\n", colors[row][col][0], colors[row][col][1], colors[row][col][2]);
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