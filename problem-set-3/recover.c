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

       }

   }
   else
   {
       printf("Usage: ./recover image");
       return 1;
   }
}