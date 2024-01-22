#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) // check usage
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *infile = fopen(argv[1], "r"); // open infile
    if (!infile) // check open
    {
        printf("Unable to open: %s \n", argv[1]);
        return 0;
    }
    FILE *outfile = NULL;
    BYTE buffer[512];
    int count = 0;
    char filename[8];
    while (fread(buffer, sizeof(BYTE), 512, infile) == 512) // read infile
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // check jpg
        {
            if (outfile != NULL) // check outfile existance
            {
                fclose(outfile);
            }
            sprintf(filename, "%03i.jpg", count); // open new file
            outfile = fopen(filename, "w"); // open new file
            if (outfile == NULL) // check create
            {
                printf("Unable to create: %s \n", filename);
                return 1;
            }
            count++;
        }
        if (outfile != NULL) // check outfile
        {
            fwrite(buffer, sizeof(BYTE), 512, outfile); // write new file
        }
    }
    if (outfile != NULL)
    {
        fclose(outfile);
    }
    fclose(infile);
    return 0;
}
