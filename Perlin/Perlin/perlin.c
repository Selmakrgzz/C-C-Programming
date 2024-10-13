#include "perlin.h"
#include <stdlib.h>
#include <math.h>


char symbols[] = { ' ', '.', ':', '-', '+', '*', '&', '#', '@' };

/* Loop through output in correct order and output index */
void print_noise(uint8_t smoothed_map[HEIGHT][WIDTH], char output[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (smoothed_map[i][j] >= 0 && smoothed_map[i][j] < 28) {
                output[i][j] = symbols[0];

            }
            else if (smoothed_map[i][j] >= 28 && smoothed_map[i][j] < 56) {
                output[i][j] = symbols[1];

            }
            else if (smoothed_map[i][j] >= 56 && smoothed_map[i][j] < 84) {
                output[i][j] = symbols[2];

            }
            else if (smoothed_map[i][j] >= 84 && smoothed_map[i][j] < 112) {
                output[i][j] = symbols[3];

            }
            else if (smoothed_map[i][j] >= 112 && smoothed_map[i][j] < 140) {
                output[i][j] = symbols[4];

            }
            else if (smoothed_map[i][j] >= 140 && smoothed_map[i][j] < 168) {
                output[i][j] = symbols[5];

            }
            else if (smoothed_map[i][j] >= 168 && smoothed_map[i][j] < 196) {
                output[i][j] = symbols[6];

            }
            else if (smoothed_map[i][j] >= 196 && smoothed_map[i][j] < 224) {
                output[i][j] = symbols[7];

            }
            else if (smoothed_map[i][j] >= 224 && smoothed_map[i][j] < 255) {
                output[i][j] = symbols[8];
            }
            //printf("%c", output[i][j]);
            putchar(output[i][j]);
        }
        putchar('\n');
    }
}

/* Smooth the noise map by averaging neighbors and applying a decay factor */
void smooth_noise(uint8_t noise_map[HEIGHT][WIDTH], uint8_t smoothed_map[HEIGHT][WIDTH])
{
    uint8_t sum = 0;
    
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {            
            //Neighbor over
            if (i > 0) {
                sum += noise_map[i - 1][j];
            } 
            //Neighbor under
            if (i < HEIGHT - 1) {
                sum += noise_map[i + 1][j];
            }
            //Neighbor right
            if (i > 0) {
                sum += noise_map[i][j - 1];
            }
            //Neighbor left
            if (j < WIDTH - 1) {
                sum += noise_map[i][j + 1];
            }
            sum += noise_map[i][j];

            float average = (float)sum / 5;

            smoothed_map[i][j] = (uint8_t)(average + (noise_map[i][j] * DECAY_FACTOR));
            sum = 0;
            average = 0;
        }
    }
}

/* Generate initial random noise and smooth it */
void gen_noise(uint8_t noise_map[HEIGHT][WIDTH]) //, char output[HEIGHT][WIDTH], 
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            noise_map[i][j] = M_Random();
        }
    }
}

void clear_screen()
{
#if WINDOWS
    system("cls");

#elif LINUX
    system("clear");

#elif MAC
    system("clear");

#endif
}



int main()
{
    uint8_t noise_map[HEIGHT][WIDTH];
    uint8_t smoothed_map[HEIGHT][WIDTH];
    char output[HEIGHT][WIDTH];

    gen_noise(noise_map);
    smooth_noise(noise_map, smoothed_map);

    while (1)
    {
        clear_screen();

        print_noise(smoothed_map, output);

        /* Sleep before update */
        //usleep(200000);
    }

    return 0;
}