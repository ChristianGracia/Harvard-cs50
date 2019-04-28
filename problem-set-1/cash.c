#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int owed;

    owed = get_float("How much change is owed?");

    do
    {
        printf("%*d", 2, owed);

    }

    while (owed > 0 || owed < 1);


}