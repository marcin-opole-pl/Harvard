#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Two arguments required\n");
        return 1;
    }
    // Open input file for reading
    char *ifile = argv[1];
    FILE *infile = fopen(ifile, "r");
    if (infile == NULL)
    {
        printf("Could not open %s\n", ifile);
        fclose(infile);
        return 1;
    }
    // Read header
    WAVHEADER head;
    fread(&head, sizeof(WAVHEADER), 1, infile);
    // Use check_format to ensure WAV format
    if (check_format(head) == 1)
    {
        printf("Unsupported file type\n");
        fclose(infile);
        return 1;
    }
    // Open output file for writing
    char *ofile = argv[2];
    FILE *outfile = fopen(ofile, "w");
    if (outfile == NULL)
    {
        printf("Out of memory");
        fclose(outfile);
        return 1;
    }
    // Write header to file
    fwrite(&head, sizeof(WAVHEADER), 1, outfile);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(head);

    // Write reversed audio to file
    if (fseek(infile, block_size, SEEK_END))
    {
        return 1;
    }
    BYTE t_arr[block_size];
    while (ftell(infile) - block_size > sizeof(head))
    {
        if (fseek(infile, -2 * block_size, SEEK_CUR))
        {
            return 1;
        }
        fread(t_arr, block_size, 1, infile);
        fwrite(t_arr, block_size, 1, outfile);
    }

    fclose(infile);
    fclose(outfile);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] != 'W' && header.format[1] != 'A' && header.format[2] != 'V' && header.format[3] != 'E')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}