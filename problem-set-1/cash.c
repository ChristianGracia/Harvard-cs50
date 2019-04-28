#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
    float owed;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int total;
    int total1;
    int total2;
    int total3;

    do
    {
        owed = get_float("How much change is owed?\n");
        int cents = round(owed * 100);

        if (cents > 25)
        {
        quarters = round(cents/25);
        total = cents - (quarters * 25);

        dimes = round(total/10);
        total1 = total - (dimes * 10);

        nickels = round(total1/5);
        total2= total1 - (nickels * 5);

        pennies = round(total2/1);
        total3 = quarters + nickels + dimes + pennies;
        printf("\nChange owed is: %i", total3);


        }

        else if( cents < 25)
        {
        dimes = round(total/10);
        total1 = total - (dimes * 10);
        nickels = round(total1/5);
        total2= total1 - (nickels * 5);
        pennies = round(total2/1);
        total3 = quarters + nickels + dimes + pennies -1;
        printf("\nChange owed is: %i", total3);
        }

        else if (cents < 10 )
        {

        nickels = round(total1/5);
        total2= total1 - (nickels * 5);
        pennies = round(total2/1);
        total3 = quarters + nickels + dimes + pennies -1;
        printf("\nChange owed is: %i", total3);


        }
        else if (cents < 5)
        {

        pennies = round(total2/1);
        total3 = quarters + nickels + dimes + pennies -1;
        printf("\nChange owed is: %i", total3);
        }

    }
    while (owed < 0);
}