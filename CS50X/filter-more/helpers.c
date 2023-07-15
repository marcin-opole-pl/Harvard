#include "helpers.h"
#include <math.h>
#include <string.h>


typedef struct
{
    int  rgbtBlue;
    int  rgbtGreen;
    int  rgbtRed;
}
TRIPLE;


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            int avr_val = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avr_val;
            image[i][j].rgbtGreen = avr_val;
            image[i][j].rgbtBlue = avr_val;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // Temp array to store reversed pixels
        RGBTRIPLE t_arr[width];
        for (int j = 0; j < width; j++)
        {
            t_arr[j] = image[i][width - 1 - j];
        }
        // Replace pixels with t_arr
        for (int k = 0; k < width; k++)
        {
            image[i][k] = t_arr[k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temp struct to hold modified pixels
    RGBTRIPLE t_struct[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Corner [0][0] case
            if (h == 0 && w == 0)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = 0; i <= 1; i++)
                {
                    for (int j = 0; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 4.0);
                t_struct[h][w].rgbtBlue = round(blue / 4.0);
                t_struct[h][w].rgbtGreen = round(green / 4.0);
            }
            // Corner [0][width] case
            else if (h == 0 && w == width - 1)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = 0; i <= 1; i++)
                {
                    for (int j = -1; j <= 0; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 4.0);
                t_struct[h][w].rgbtBlue = round(blue / 4.0);
                t_struct[h][w].rgbtGreen = round(green / 4.0);
            }
            // Corner [height][width] case
            else if (h == height - 1 && w == width -1)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 0; i++)
                {
                    for (int j = -1; j <= 0; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 4.0);
                t_struct[h][w].rgbtBlue = round(blue / 4.0);
                t_struct[h][w].rgbtGreen = round(green / 4.0);
            }
            // Corner [height][0] case
            else if (h == height -1 && w == 0)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 0; i++)
                {
                    for (int j = 0; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 4.0);
                t_struct[h][w].rgbtBlue = round(blue / 4.0);
                t_struct[h][w].rgbtGreen = round(green / 4.0);
            }
            // Row 0 case
            else if (h == 0)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = 0; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 6.0);
                t_struct[h][w].rgbtBlue = round(blue / 6.0);
                t_struct[h][w].rgbtGreen = round(green / 6.0);
            }
            // Row height case
            else if (h == height - 1)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 0; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 6.0);
                t_struct[h][w].rgbtBlue = round(blue / 6.0);
                t_struct[h][w].rgbtGreen = round(green / 6.0);
            }
            // Column 0 case
            else if (w == 0)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = 0; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 6.0);
                t_struct[h][w].rgbtBlue = round(blue / 6.0);
                t_struct[h][w].rgbtGreen = round(green / 6.0);
            }
            // Column width case
            else if (w == width - 1)
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 0; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 6.0);
                t_struct[h][w].rgbtBlue = round(blue / 6.0);
                t_struct[h][w].rgbtGreen = round(green / 6.0);
            }
            // The rest
            else
            {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        red += image[h + i][w + j].rgbtRed;
                        blue += image[h + i][w + j].rgbtBlue;
                        green += image[h + i][w + j].rgbtGreen;
                    }
                }
                t_struct[h][w].rgbtRed = round(red / 9.0);
                t_struct[h][w].rgbtBlue = round(blue / 9.0);
                t_struct[h][w].rgbtGreen = round(green / 9.0);
            }
        }
    }
    // Replace pixels with t_struct
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = t_struct[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Temp struct to hold modified pixels
    TRIPLE t_struct[height][width];
    // Temp struct to hold Gx values
    TRIPLE t_struct_x[height][width];
    // Temp struct to hold Gy values
    TRIPLE t_struct_y[height][width];
    // Gx calculation
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Corner [0][0] case
            if (h == 0 && w == 0)
            {
                int red_r = (2 * image[h][w + 1].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_r = (2 * image[h][w + 1].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_r = (2 * image[h][w + 1].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_r;
                t_struct_x[h][w].rgbtBlue = blue_r;
                t_struct_x[h][w].rgbtGreen = green_r;
            }
            // Corner [0][width] case
            else if (h == 0 && w == width - 1)
            {
                int red_l = ((-2) * image[h][w - 1].rgbtRed) + ((-1) * image[h + 1][w - 1].rgbtRed);
                int blue_l = ((-2) * image[h][w - 1].rgbtBlue) + ((-1) * image[h + 1][w - 1].rgbtBlue);
                int green_l = ((-2) * image[h][w - 1].rgbtGreen) + ((-1) * image[h + 1][w - 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l;
                t_struct_x[h][w].rgbtBlue = blue_l;
                t_struct_x[h][w].rgbtGreen = green_l;
            }
            // Corner [height][width] case
            else if (h == height - 1 && w == width - 1)
            {
                int red_l = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h][w - 1].rgbtRed);
                int blue_l = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h][w - 1].rgbtBlue);
                int green_l = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h][w - 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l;
                t_struct_x[h][w].rgbtBlue = blue_l;
                t_struct_x[h][w].rgbtGreen = green_l;
            }
            // Corner [height][0] case
            else if (h == height - 1 && w == 0)
            {
                int red_r = (1 * image[h - 1][w + 1].rgbtRed) + (2 * image[h][w + 1].rgbtRed);
                int blue_r = (1 * image[h - 1][w + 1].rgbtBlue) + (2 * image[h][w + 1].rgbtBlue);
                int green_r = (1 * image[h - 1][w + 1].rgbtGreen) + (2 * image[h][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_r;
                t_struct_x[h][w].rgbtBlue = blue_r;
                t_struct_x[h][w].rgbtGreen = green_r;
            }
            // Row 0 case
            else if (h == 0)
            {
                int red_l = ((-2) * image[h][w - 1].rgbtRed) + ((-1) * image[h + 1][w - 1].rgbtRed);
                int red_r = (2 * image[h][w + 1].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_l = ((-2) * image[h][w - 1].rgbtBlue) + ((-1) * image[h + 1][w - 1].rgbtBlue);
                int blue_r = (2 * image[h][w + 1].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_l = ((-2) * image[h][w - 1].rgbtGreen) + ((-1) * image[h + 1][w - 1].rgbtGreen);
                int green_r = (2 * image[h][w + 1].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l + red_r;
                t_struct_x[h][w].rgbtBlue = blue_l + blue_r;
                t_struct_x[h][w].rgbtGreen = green_l + green_r;
            }
            // Row height case
            else if (h == height - 1)
            {
                int red_l = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h][w - 1].rgbtRed);
                int red_r = (1 * image[h - 1][w + 1].rgbtRed) + (2 * image[h][w + 1].rgbtRed);
                int blue_l = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h][w - 1].rgbtBlue);
                int blue_r = (1 * image[h - 1][w + 1].rgbtBlue) + (2 * image[h][w + 1].rgbtBlue);
                int green_l = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h][w - 1].rgbtGreen);
                int green_r = (1 * image[h - 1][w + 1].rgbtGreen) + (2 * image[h][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l + red_r;
                t_struct_x[h][w].rgbtBlue = blue_l + blue_r;
                t_struct_x[h][w].rgbtGreen = green_l + green_r;
            }
            // Column 0 case
            else if (w == 0)
            {
                int red_r = (1 * image[h - 1][w + 1].rgbtRed) + (2 * image[h][w + 1].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_r = (1 * image[h - 1][w + 1].rgbtBlue) + (2 * image[h][w + 1].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_r = (1 * image[h - 1][w + 1].rgbtGreen) + (2 * image[h][w + 1].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_r;
                t_struct_x[h][w].rgbtBlue = blue_r;
                t_struct_x[h][w].rgbtGreen = green_r;
            }
            // Column width case
            else if (w == width - 1)
            {
                int red_l = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h][w - 1].rgbtRed) + ((-1) * image[h + 1][w - 1].rgbtRed);
                int blue_l = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h][w - 1].rgbtBlue) + ((-1) * image[h + 1][w - 1].rgbtBlue);
                int green_l = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h][w - 1].rgbtGreen) + ((-1) * image[h + 1][w - 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l;
                t_struct_x[h][w].rgbtBlue = blue_l;
                t_struct_x[h][w].rgbtGreen = green_l;
            }
            // The rest
            else
            {
                int red_l = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h][w - 1].rgbtRed) + ((-1) * image[h + 1][w - 1].rgbtRed);
                int red_r = (1 * image[h - 1][w + 1].rgbtRed) + (2 * image[h][w + 1].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_l = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h][w - 1].rgbtBlue) + ((-1) * image[h + 1][w - 1].rgbtBlue);
                int blue_r = (1 * image[h - 1][w + 1].rgbtBlue) + (2 * image[h][w + 1].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_l = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h][w - 1].rgbtGreen) + ((-1) * image[h + 1][w - 1].rgbtGreen);
                int green_r = (1 * image[h - 1][w + 1].rgbtGreen) + (2 * image[h][w + 1].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gx calc
                t_struct_x[h][w].rgbtRed = red_l + red_r;
                t_struct_x[h][w].rgbtBlue = blue_l + blue_r;
                t_struct_x[h][w].rgbtGreen = green_l + green_r;
            }
        }
    }
    // Gy calculation
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Corner [0][0] case
            if (h == 0 && w == 0)
            {
                int red_b = (2 * image[h + 1][w].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_b = (2 * image[h + 1][w].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_b = (2 * image[h + 1][w].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_b;
                t_struct_y[h][w].rgbtBlue = blue_b;
                t_struct_y[h][w].rgbtGreen = green_b;
            }
            // Corner [0][width] case
            else if (h == 0 && w == width - 1)
            {
                int red_b = (1 * image[h + 1][w - 1].rgbtRed) + (2 * image[h + 1][w].rgbtRed);
                int blue_b = (1 * image[h + 1][w - 1].rgbtBlue) + (2 * image[h + 1][w].rgbtBlue);
                int green_b = (1 * image[h + 1][w - 1].rgbtGreen) + (2 * image[h + 1][w].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_b;
                t_struct_y[h][w].rgbtBlue = blue_b;
                t_struct_y[h][w].rgbtGreen = green_b;
            }
            // Corner [height][width] case
            else if (h == height - 1 && w == width - 1)
            {
                int red_t = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h - 1][w].rgbtRed);
                int blue_t = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h - 1][w].rgbtBlue);
                int green_t = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h - 1][w].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t;
                t_struct_y[h][w].rgbtBlue = blue_t;
                t_struct_y[h][w].rgbtGreen = green_t;
            }
            // Corner [height][0] case
            else if (h == height - 1 && w == 0)
            {
                int red_t = ((-2) * image[h - 1][w].rgbtRed) + ((-1) * image[h - 1][w + 1].rgbtRed);
                int blue_t = ((-2) * image[h - 1][w].rgbtBlue) + ((-1) * image[h - 1][w + 1].rgbtBlue);
                int green_t = ((-2) * image[h - 1][w].rgbtGreen) + ((-1) * image[h - 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t;
                t_struct_y[h][w].rgbtBlue = blue_t;
                t_struct_y[h][w].rgbtGreen = green_t;
            }
            // Row 0 case
            else if (h == 0)
            {
                int red_b = (1 * image[h + 1][w - 1].rgbtRed) + (2 * image[h + 1][w].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_b = (1 * image[h + 1][w - 1].rgbtBlue) + (2 * image[h + 1][w].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_b = (1 * image[h + 1][w - 1].rgbtGreen) + (2 * image[h + 1][w].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_b;
                t_struct_y[h][w].rgbtBlue = blue_b;
                t_struct_y[h][w].rgbtGreen = green_b;
            }
            // Row height case
            else if (h == height - 1)
            {
                int red_t = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h - 1][w].rgbtRed) + ((-1) * image[h - 1][w + 1].rgbtRed);
                int blue_t = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h - 1][w].rgbtBlue) + ((-1) * image[h - 1][w + 1].rgbtBlue);
                int green_t = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h - 1][w].rgbtGreen) + ((-1) * image[h - 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t;
                t_struct_y[h][w].rgbtBlue = blue_t;
                t_struct_y[h][w].rgbtGreen = green_t;
            }
            // Column 0 case
            else if (w == 0)
            {
                int red_t = ((-2) * image[h - 1][w].rgbtRed) + ((-1) * image[h - 1][w + 1].rgbtRed);
                int red_b = (2 * image[h + 1][w].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_t = ((-2) * image[h - 1][w].rgbtBlue) + ((-1) * image[h - 1][w + 1].rgbtBlue);
                int blue_b = (2 * image[h + 1][w].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_t = ((-2) * image[h - 1][w].rgbtGreen) + ((-1) * image[h - 1][w + 1].rgbtGreen);
                int green_b = (2 * image[h + 1][w].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t + red_b;
                t_struct_y[h][w].rgbtBlue = blue_t + blue_b;
                t_struct_y[h][w].rgbtGreen = green_t + green_b;
            }
            // Column width case
            else if (w == width - 1)
            {
                int red_t = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h - 1][w].rgbtRed);
                int red_b = (1 * image[h + 1][w - 1].rgbtRed) + (2 * image[h + 1][w].rgbtRed);
                int blue_t = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h - 1][w].rgbtBlue);
                int blue_b = (1 * image[h + 1][w - 1].rgbtBlue) + (2 * image[h + 1][w].rgbtBlue);
                int green_t = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h - 1][w].rgbtGreen);
                int green_b = (1 * image[h + 1][w - 1].rgbtGreen) + (2 * image[h + 1][w].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t + red_b;
                t_struct_y[h][w].rgbtBlue = blue_t + blue_b;
                t_struct_y[h][w].rgbtGreen = green_t + green_b;
            }
            // The rest
            else
            {
                int red_t = ((-1) * image[h - 1][w - 1].rgbtRed) + ((-2) * image[h - 1][w].rgbtRed) + ((-1) * image[h - 1][w + 1].rgbtRed);
                int red_b = (1 * image[h + 1][w - 1].rgbtRed) + (2 * image[h + 1][w].rgbtRed) + (1 * image[h + 1][w + 1].rgbtRed);
                int blue_t = ((-1) * image[h - 1][w - 1].rgbtBlue) + ((-2) * image[h - 1][w].rgbtBlue) + ((-1) * image[h - 1][w + 1].rgbtBlue);
                int blue_b = (1 * image[h + 1][w - 1].rgbtBlue) + (2 * image[h + 1][w].rgbtBlue) + (1 * image[h + 1][w + 1].rgbtBlue);
                int green_t = ((-1) * image[h - 1][w - 1].rgbtGreen) + ((-2) * image[h - 1][w].rgbtGreen) + ((-1) * image[h - 1][w + 1].rgbtGreen);
                int green_b = (1 * image[h + 1][w - 1].rgbtGreen) + (2 * image[h + 1][w].rgbtGreen) + (1 * image[h + 1][w + 1].rgbtGreen);
                // Gy calc
                t_struct_y[h][w].rgbtRed = red_t + red_b;
                t_struct_y[h][w].rgbtBlue = blue_t + blue_b;
                t_struct_y[h][w].rgbtGreen = green_t + green_b;
            }
        }
    }
    // Sobel filter calc
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            t_struct[h][w].rgbtRed = round(sqrt(pow(t_struct_x[h][w].rgbtRed, 2) + pow(t_struct_y[h][w].rgbtRed, 2)));
            t_struct[h][w].rgbtGreen = round(sqrt(pow(t_struct_x[h][w].rgbtGreen, 2) + pow(t_struct_y[h][w].rgbtGreen, 2)));
            t_struct[h][w].rgbtBlue = round(sqrt(pow(t_struct_x[h][w].rgbtBlue, 2) + pow(t_struct_y[h][w].rgbtBlue, 2)));
            if (t_struct[h][w].rgbtRed > 255)
            {
                t_struct[h][w].rgbtRed = 255;
            }
            if (t_struct[h][w].rgbtGreen > 255)
            {
                t_struct[h][w].rgbtGreen = 255;
            }
            if (t_struct[h][w].rgbtBlue > 255)
            {
                t_struct[h][w].rgbtBlue = 255;
            }
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = t_struct[h][w].rgbtRed;
            image[h][w].rgbtGreen = t_struct[h][w].rgbtGreen;
            image[h][w].rgbtBlue = t_struct[h][w].rgbtBlue;
        }
    }
    return;
}
