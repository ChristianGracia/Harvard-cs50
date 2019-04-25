//First attempt at the mario problem, starting with the easier one and then will attempt the harder one

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("Enter a height; \n");
    scanf("%d", &height);
    printf("hello, %d\n", height);
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
        {
             char str [] = ".";
            
             printf("%s#", str);
        } 
        printf("\n");   
    }
}