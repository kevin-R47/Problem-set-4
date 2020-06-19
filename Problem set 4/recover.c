#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE; //def data type BYTE

int main(int argc, char *argv[])
{
    //check for ONE command-line argument
    if (argc != 2)
    {
        printf("Usage: Enter file name\n");
        return 1;
    }

    //open the memory card file
    FILE *card = fopen(argv[1], "r");
    //check if it can find the file
    if (card == NULL)
    {
        printf("Could not read file\n");
        return 2;
    }

    //variables
    int count = 000; //counts JPGs
    FILE *image = NULL; //iniciates a file call image
    BYTE buffer[512]; //512bytes into a buffer
    char name[10]; //file name

    do
    {
        //checks if it is the beginning of a JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (image) //if isn't the firt JPG
            {
                fclose(image);
            }
            count++;
            sprintf(name, "%03i.jpg", count);
            image = fopen(name, "w");
            fwrite(buffer, 512, 1, image);

        }
        if (image != NULL) //if isn't the beginning of a JPG
        {
            fwrite(buffer, 512, 1, image);
        }
    }
    while (fread(buffer, sizeof(BYTE), 1, card));
    fclose(card);
}