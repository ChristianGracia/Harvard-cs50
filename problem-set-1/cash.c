#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
    float owed;



    do
    {
        owed = get_float("How much change is owed?\n");

        int cents = round(owed * 100);




        printf("\nChange owed is: %i", cents);

    }

    while (owed > 0);


}