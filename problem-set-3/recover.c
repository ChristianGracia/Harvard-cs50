#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc = 2)
   {
       FILE *fopen(argv[1], "r");


       for (int i = 0; i < 20; i++)
       {
           fread(&argv[1], 512, 1, inptr);
           fwrite(900 + i".jpeg", 512, 1, inptr);
       }


   }
   else
   {
       printf("Usage: ./recover image");
       return 1;
   }
}
