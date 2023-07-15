#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

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
    BYTE block[512];
    // Set counter
    int counter = 0;
    // Define filename
    char filename[8] = {0};
    // Itoration
    while (fread(block, sizeof(block), 1, inptr) == sizeof(block))
        {
            // Check if block is a jpeg
            if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
            {
                sprintf(filename, "%03i.jpg", counter);
                FILE *outptr = fopen(filename, "w");
                fwrite(block, sizeof(block), 1, outptr);
                counter++;
                fclose(outptr);
            }
            // continue with next jpeg block
            else if (counter != 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                FILE *outptr = fopen(filename, "a");
                fwrite(block, sizeof(block), 1, outptr);
                fclose(outptr);
            }
            else
            {
                // end no images found
            }
        }
    fclose(inptr);
}