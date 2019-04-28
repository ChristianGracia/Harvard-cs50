#include <cs50.h>
#include <stdio.h>

int main (void)
{
    float owed;



    do
    {
        owed = get_float("How much change is owed?");
        printf("%.2f", owed);

    }

    while (owed > 0 || owed < 1);


}