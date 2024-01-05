#include "helpers.h"
#include <stdlib.h>
#include <time.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (image[i][k].rgbtRed == 00 && image[i][k].rgbtGreen == 00 && image[i][k].rgbtBlue == 00)
            {
                image[i][k].rgbtRed = rand() % 255;;
                image[i][k].rgbtGreen = rand() % 255;;
                image[i][k].rgbtBlue = rand() % 255;;
            }
        }
    }
}
