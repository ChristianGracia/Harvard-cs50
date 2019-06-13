#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    //check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Could not open %s. Please only use one argument.\n", argv[1]);
        return 1;
    }

    //open file to be read
    FILE *inptr = fopen(argv[1], "r");

    //checks if file exists
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s. Incorrect file name.\n", argv[1]);
        return 2;
    }

    //create output file
    FILE *outptr = NULL;

    //create buffer for image data to be collected
    unsigned char buffer[512];

    //creating array to store img names
    char fileNames[8];

    //create counter to increment file name starting at 001
    int counter = 0;

    //flag to signal if image is done
    int nextPic = 0;

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {


            if (nextPic == 1)
            {
                //close the current image because a new image is found
                fclose(outptr);
            }
            else
            {
                //image is found and can be written
                nextPic = 1;
            }

            //create image name
            sprintf(fileNames, "%03i.jpg", counter);

            //open file to be write
            outptr = fopen(fileNames, "w");

            //increase counter for file names
            counter++;

        }
        if (nextPic == 1)
        {
            //write found image data to file
            fwrite(&buffer, 512, 1, outptr);
        }

    }

    //close last image file
    fclose(outptr);

    //close argument file
    fclose(inptr);

    return 0;

}