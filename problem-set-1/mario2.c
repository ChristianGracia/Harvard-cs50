//more challenging mario problem
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int height;

    do
    {
        height = get_int("Enter a height: ");
        if (height <= 8 && height > 0)
        {
            for (int i = 1; i < height + 1; i++)
            {
                {
                    int m = height - i;
                    printf("%*s", m, "");
                    for (int j = 0; j < i; j++)
                    {
                        printf("#");
                    }
                    printf("  ");

                    for (int l = 0; l < i; l++)
                    {
                        printf("#");
                    }


                    printf("\n");
                }

            }
        }
    }
    while (height > 8 || height <= 0);
}