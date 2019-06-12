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
    
    while(fread(buffer, 512, 1, file) == 1)
    {
        
    }
    
    //close last image file
    fclose(outptr);
    
    //close argument file
    fclose(inptr);
    
    return 0;

}