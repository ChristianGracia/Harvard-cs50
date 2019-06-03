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

    //creating array to store pixels from first image
    RGBTRIPLE rowScan[largerWidth * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines
    for (int i = 0; i < abs(height); i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < width; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // add what is read to array
            for (int k = 0; k < n; k++)
            {
                rowScan[(j * n) + k] = triple;
            }
        }
        // skip over padding, if any
        fseek(inptr, smallerPadding, SEEK_CUR);

        //writing new pixels and padding
        for (int j = 0; j < n; j++)
        {
            fwrite(rowScan, sizeof(RGBTRIPLE), largerWidth, outptr);
            
            for (int k = 0; k < largerPadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }
    fclose(inptr);

    fclose(outptr);

    return 0;
}
