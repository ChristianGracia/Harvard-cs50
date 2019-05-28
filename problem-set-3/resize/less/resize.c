// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    // ensure proper usage
    int n = atoi(argv[1]);

    if (argc != 4 || n > 100 || n < 0)
    {
        fprintf(stderr, "Usage: n infile outfile\n");
        return 1;
    }


    printf("%i", n);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


     //new width and height
    //pixel = 3 bytes, 1 byte per rgb value
    //3 by 3 = 9 pixels = 27 bytes = need 1 padding for 28 which is divisible by 4
    //new width and height

    int height = bi.biHeight;
    int width = bi.biWidth;
    int largerHeight = height * n;
    int largerWidth = width * n;

    //new and old padding

    int smallerPadding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;
    int largerPadding = (4 - (largerWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //new headers

    bi.biHeight = largerHeight;
    bi.biWidth = largerWidth;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * largerWidth) + largerPadding) * abs(largerHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    
    
    //datatype id[size] / (size * size of datatype) = bytes needed, return starting address
    //addres + (sizeof(type) * i) using i to get to next memory
    //0x123 +(sizeof(int) * i) to get memory address
    //0x123 +(4*1) gets the next memory address after
    //100100x100100x100100x
     // 0x123    0x127   0x131
    
    //row scan array
    RGBTRIPLE rowScan[largerWidth * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
