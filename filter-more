#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float gray = (float) (image[i][k].rgbtRed + image[i][k].rgbtGreen + image[i][k].rgbtBlue) / 3; // average
            image[i][k].rgbtRed = round(gray);
            image[i][k].rgbtGreen = round(gray);
            image[i][k].rgbtBlue = round(gray);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width / 2; k++)
        {
            RGBTRIPLE temp = image[i][k]; // temporary for swap
            image[i][k] = image[i][width - k - 1];
            image[i][width - k - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            temp[i][k] = image[i][k]; // copy image
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float blurRed = 0;
            float blurGreen = 0;
            float blurBlue = 0;
            int count = 0;
            for (int a = i - 1; a <= i + 1; a++) // left pixel
            {
                for (int b = k - 1; b <= k + 1; b++) // right pixel
                {
                    if (a >= 0 && a < height && b >= 0 && b < width) // inside the image
                    {
                        blurRed += temp[a][b].rgbtRed;     // add to total
                        blurGreen += temp[a][b].rgbtGreen; // add to total
                        blurBlue += temp[a][b].rgbtBlue;   // add to total
                        count++;                           // add count
                    }
                }
            }
            image[i][k].rgbtRed = round(blurRed / count);     // average total
            image[i][k].rgbtGreen = round(blurGreen / count); // average total
            image[i][k].rgbtBlue = round(blurBlue / count);   // average total
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            temp[i][k] = image[i][k]; // copy image
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float gxRed = 0;
            float gxGreen = 0;
            float gxBlue = 0;
            float gyRed = 0;
            float gyGreen = 0;
            float gyBlue = 0;
            int gxKernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int gyKernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            for (int a = i - 1, x = 0; a <= i + 1; a++, x++)
            {
                for (int b = k - 1, y = 0; b <= k + 1; b++, y++)
                {
                    if (a >= 0 && a < height && b >= 0 && b < width) // inside the image
                    {
                        gxRed += temp[a][b].rgbtRed * gxKernel[x][y];
                        gxGreen += temp[a][b].rgbtGreen * gxKernel[x][y];
                        gxBlue += temp[a][b].rgbtBlue * gxKernel[x][y];
                        gyRed += temp[a][b].rgbtRed * gyKernel[x][y];
                        gyGreen += temp[a][b].rgbtGreen * gyKernel[x][y];
                        gyBlue += temp[a][b].rgbtBlue * gyKernel[x][y];
                    }
                }
            }
            float channelRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            float channelGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            float channelBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            if (channelRed > 255) // cap
            {
                channelRed = 255;
            }
            if (channelGreen > 255) // cap
            {
                channelGreen = 255;
            }
            if (channelBlue > 255) // cap
            {
                channelBlue = 255;
            }
            if (channelRed != 0 || channelGreen != 0 || channelBlue != 0)
            {
                image[i][k].rgbtRed = channelRed;
                image[i][k].rgbtGreen = channelGreen;
                image[i][k].rgbtBlue = channelBlue;
            }
        }
    }
}
