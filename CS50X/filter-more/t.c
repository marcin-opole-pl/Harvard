#include <stdio.h>

int main(void)
{
    // Normal case
    int red = 0;
    int green = 0;
    int blue = 0;
    for (int i = -1; i == 1; i++)
    {
        for (int j = -1; j == 1; j++)
        {
        red += image[h + i][w + j].rgbtRed;
        blue += image[h + i][w + j].rgbtBlue;
        green += image[h + i][w + j].rgbtGreen;
        }
    }
    t_struct[h][w].rgbtRed = round(red / 9.0);
    t_struct[h][w].rgbtBlue = round(blue / 9.0);
    t_struct[h][w].rgbtGreen = round(green / 9.0);

    // Edge

}

// GX
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








// GY
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