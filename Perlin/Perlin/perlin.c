#include "perlin.h"
#include <stdlib.h>

/* Loop through output in correct order and output index */
void print_noise(char output[HEIGHT][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            putchar(output[y][x]);
        }
        putchar('\n');
    }
}

/* Smooth the noise map by averaging neighbors and applying a decay factor */
void smooth_noise(uint8_t noise_map[HEIGHT][WIDTH], uint8_t smoothed_map[HEIGHT][WIDTH])
{
}

/* Generate initial random noise and smooth it */
void gen_noise(char output[HEIGHT][WIDTH]) //, uint8_t noise_map[HEIGHT][WIDTH]
{
    char symbols[] = {' ', '.', ':', '-', '+', '*', '&', '#', '@'};
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int randomNum = M_Random();
            if (randomNum >= 0 && randomNum < 28) {
                output[i][j] = symbols[0];

            } else if(randomNum >= 28 && randomNum < 56) {
                output[i][j] = symbols[1];

            } else if(randomNum >= 56 && randomNum < 84) {
                output[i][j] = symbols[2];

            } else if (randomNum >= 84 && randomNum < 112) {
                output[i][j] = symbols[3];

            } else if (randomNum >= 112 && randomNum < 140) {
                output[i][j] = symbols[4];

            } else if (randomNum >= 140 && randomNum < 168) {
                output[i][j] = symbols[5];

            } else if (randomNum >= 168 && randomNum < 196) {
                output[i][j] = symbols[6];

            } else if (randomNum >= 196 && randomNum < 224) {
                output[i][j] = symbols[7];

            } else if (randomNum >= 224 && randomNum < 255) {
                output[i][j] = symbols[8];
            }
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
    char array1[HEIGHT][WIDTH];

    gen_noise(array1);

    print_noise(array1);



    while (1)
    {
        //clear_screen();


        /* Sleep before update */
        //usleep(200000);
    }

    return 0;
}
