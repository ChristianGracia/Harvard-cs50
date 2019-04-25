//First attempt at the mario problem, starting with the easier one and then will attempt the harder one

#include <cs50.h>
#include <stdio.h>

int main(void) {
  int height;
  do 
  {
    printf("Enter a height; \n");
    scanf("%i", &height);
    for (int i = 0; i < height + 1; i++) {
    {
      char str[] = ".";
      printf("%s", str);
      for (int j = 0; j < i; j++) {

        printf("#");
      }
      printf("\n");
    }

  }  
      
  }
  while (height > 8 || height < 0);
  return height;
}