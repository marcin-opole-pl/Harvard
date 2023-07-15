#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef uint8_t  BYTE;


typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
}
RGBTRIPLE;

void edges(int height, int width, RGBTRIPLE image[height][width]);


int main(void)
{
    RGBTRIPLE image[4][4];
    image[0][0].rgbtRed = 10;
    image[0][0].rgbtGreen = 10;
    image[0][0].rgbtBlue = 10;
    image[0][1].rgbtRed = 10;
    image[0][1].rgbtGreen = 10;
    image[0][1].rgbtBlue = 10;
    image[0][2].rgbtRed = 10;
    image[0][2].rgbtGreen = 10;
    image[0][2].rgbtBlue = 10;
    image[0][3].rgbtRed = 10;
    image[0][3].rgbtGreen = 10;
    image[0][3].rgbtBlue = 10;

    image[1][0].rgbtRed = 10;
    image[1][0].rgbtGreen = 10;
    image[1][0].rgbtBlue = 10;
    image[1][1].rgbtRed = 10;
    image[1][1].rgbtGreen = 10;
    image[1][1].rgbtBlue = 10;
    image[1][2].rgbtRed = 10;
    image[1][2].rgbtGreen = 10;
    image[1][2].rgbtBlue = 10;
    image[1][3].rgbtRed = 10;
    image[1][3].rgbtGreen = 10;
    image[1][3].rgbtBlue = 10;

    image[2][0].rgbtRed = 10;
    image[2][0].rgbtGreen = 10;
    image[2][0].rgbtBlue = 10;
    image[2][1].rgbtRed = 10;
    image[2][1].rgbtGreen = 10;
    image[2][1].rgbtBlue = 10;
    image[2][2].rgbtRed = 10;
    image[2][2].rgbtGreen = 10;
    image[2][2].rgbtBlue = 10;
    image[2][3].rgbtRed = 10;
    image[2][3].rgbtGreen = 10;
    image[2][3].rgbtBlue = 10;

    image[3][0].rgbtRed = 10;
    image[3][0].rgbtGreen = 10;
    image[3][0].rgbtBlue = 10;
    image[3][1].rgbtRed = 10;
    image[3][1].rgbtGreen = 10;
    image[3][1].rgbtBlue = 10;
    image[3][2].rgbtRed = 10;
    image[3][2].rgbtGreen = 10;
    image[3][2].rgbtBlue = 10;
    image[3][3].rgbtRed = 10;
    image[3][3].rgbtGreen = 10;
    image[3][3].rgbtBlue = 10;

    printf("ROW:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i %i %i  ", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
        printf("\n");
    }

    edges(4, 4, image);
    printf("DONE:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%i %i %i  ", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
        }
        printf("\n");
    }
    int z = -2 * 10 + -1 * 10;
    printf("z: %i\n", z);
}


void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Temp struct to hold modified pixels
    //RGBTRIPLE t_struct[height][width];
    RGBTRIPLE(*t_struct)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    // Temp struct to hold Gx values
   // RGBTRIPLE t_struct_x[height][width];
    RGBTRIPLE(*t_struct_x)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    // Temp struct to hold Gy values
    //RGBTRIPLE t_struct_y[height][width];
    RGBTRIPLE(*t_struct_y)[width] = calloc(height, width * sizeof(RGBTRIPLE));
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
                t_struct_x[0][3].rgbtRed = -10;
                int blue_l = ((-2) * image[h][w - 1].rgbtBlue) + ((-1) * image[h + 1][w - 1].rgbtBlue);
                int green_l = ((-2) * image[h][w - 1].rgbtGreen) + ((-1) * image[h + 1][w - 1].rgbtGreen);
                // Gx calc
                printf("rgbred02: %i\n", image[0][2].rgbtRed);
                printf("rgbred12: %i\n", image[1][2].rgbtRed);
                printf("rgbred03: %i\n", t_struct_x[0][3].rgbtRed);
                t_struct_x[h][w].rgbtBlue = blue_l;
                t_struct_x[h][w].rgbtGreen = green_l;
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
            if (image[h][w].rgbtRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            if (image[h][w].rgbtGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            if (image[h][w].rgbtBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
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
    int tempx = (t_struct_x[0][3].rgbtRed);
    int tempy = (t_struct_y[0][3].rgbtRed);
    int temp2 = round(sqrt(pow(t_struct_x[0][3].rgbtRed, 2) + pow(t_struct_y[0][3].rgbtRed, 2)));
    printf("temp x03: %i\n", tempx);
    printf("temp y03: %i\n", tempy);
    printf("sqrt: %i\n", temp2);
    printf("Red03: %i\n", image[0][3].rgbtRed);
    return;
}

