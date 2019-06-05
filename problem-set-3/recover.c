#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc == 2)
   {
       FILE *inptr = fopen(argv[1], "r");
       if (inptr == NULL)
       {
            fprintf(stderr, "Could not open %s.\n", argv[1]);
            return 2;
       }
       else
       {
           
           printf("file being read");
           for(int i = 0; i < 20; i++)
           {
              fread(buffer, 20, 1, inptr);
              if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 == 0xe0)){
                 fwrite();
              }
           }

       }

   }
   else
   {
       fprintf(stderr, "Usage: ./recover image");
       return 1;
   }
   return 0;
}
