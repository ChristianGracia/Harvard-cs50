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



        if (cents > 25) 
        {

            int quarters;
            int dimes;
            int nickels;
            int pennies;
            int total;
            int total1;
            int total2;
            int total3;

            quarters = round(cents/25);
            total = cents - (quarters * 25);

             if (total > 10) 
             {
                 dimes = round(total/10);

                 total1 = total - (dimes * 10);


                 if (total1 > 5)
                 {
                     nickels = round(total1/5);
                     total2= total1 - (nickels * 5);


                    if (total2 > 1)
                    {
                        pennies = round(total2/1);
                        total3 = quarters + nickels + dimes + pennies -1;
                        printf("\nChange owed is: %i", total3);
                        printf("quarters = %i \n dimes = %i \n nickels = %i \n pennies = %i", quarters, dimes, nickels, pennies);
                    }
                 }
             }
        }
    }
    while (owed < 0);
}