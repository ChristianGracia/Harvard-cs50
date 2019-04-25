//First attempt at the mario problem, starting with the easier one and then will attempt the harder one

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("Enter a height; \n");
    scanf("%i", &height);
    printf("hello, %i\n", height);
    if (height > 0 && height <9)
    {
       for (int i = 0; i < height + 1; i++)
       {
          char str [] = ".";
          printf("%s", str);
          for (int j = 0; j < i +1; j++)
          {
            
             printf("#");
          } 
        printf("\n");   
       }
    }
    else {
        printf("Enter a height; \n");
    }
}