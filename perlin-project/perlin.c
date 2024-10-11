#include "perlin.h"
#include <stdlib.h>
#include <time.h>

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
    //int p = M_Random();
    int p = rand();

    printf("%d", p);

    

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            
            output[i][j] = p;
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
    char array2[HEIGHT][WIDTH];
    
    gen_noise(array1);

    print_noise(array1);

    srand(time(NULL));
    

    while (1) 
    {
        clear_screen();


        /* Sleep before update */
        //usleep(200000);
    }

    return 0;
}
