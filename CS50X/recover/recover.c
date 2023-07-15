#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int block_size = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("File name please\n");
        return 1;
    }
    // Open input file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        fclose(inptr);
        return 1;
    }
    // Define block
    BYTE block[block_size];
    // Set counter
    int counter = 0;
    // Define filename
    char filename[8];
    // Open output file
    FILE *outptr = NULL;
    // Itoration
    while (fread(block, sizeof(BYTE), block_size, inptr) == block_size)
    {
        // Check if block is a jpeg
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // First jpeg
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                outptr = fopen(filename, "w");
                fwrite(block, sizeof(block), 1, outptr);
                counter++;
            }
            // Next jpegs
            else if (counter > 0)
            {
                fclose(outptr);
                sprintf(filename, "%03i.jpg", counter);
                outptr = fopen(filename, "w");
                fwrite(block, sizeof(block), 1, outptr);
                counter++;
            }
        }
        // Rest of started JPEG
        else if (counter > 0)
        {
            fwrite(block, sizeof(block), 1, outptr);
        }
    }
    fclose(inptr);
    fclose(outptr);
    return 0;
}