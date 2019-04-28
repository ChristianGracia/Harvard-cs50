//program checks if inputted credit card value is valid
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>

int numPlaces(long n)
{
    if (n < 0)
    {
        n = (n == LONG_MIN) ? LONG_MAX : -n;
    }
    if (n < 10)
    {
        return 1;
    }

    if (n < 100)
    {
        return 2;
    }
    if (n < 1000)
    {
        return 3;
    }
    if (n < 10000)
    {
        return 4;
    }
    if (n < 100000)
    {
        return 5;
    }
    if (n < 1000000)
    {
        return 6;
    }
    if (n < 10000000)
    {
        return 7;
    }
    if (n < 100000000)
    {
        return 8;
    }
    if (n < 1000000000)
    {
        return 9;
    }
    if (n < 10000000000)
    {
        return 10;
    }
    if (n < 100000000000)
    {
        return 11;
    }
    if (n < 1000000000000)
    {
        return 12;
    }
    if (n < 10000000000000)
    {
        return 13;
    }
    if (n < 100000000000000)
    {
        return 14;
    }
    if (n < 1000000000000000)
    {
        return 15;
    }
    if (n < 10000000000000000)
    {
        return 16;
    }
    if (n < 100000000000000000)
    {
        return 17;
    }

    return false;

}

int firstDigit(int n)
{

    while
    (n >= 10)
    {
        n /= 10;
    }
    return n;
}

bool checkSum(credit)
{
    return true;
}

int main(void)
{


    long long credit = get_long_long("Enter Credit Card Number: ");
    long long n = credit;
    int digits = numPlaces(credit);
    int first = firstDigit(credit / 10000000);
    bool check = checkSum(credit);

    if (first == 3 && check == true)
    {
        printf("AMEX\n");
    }
    if (first == 5 && check == true)
    {
        printf("MASTERCARD\n");
    }
    if (first == 4 && check == true)
    {
        printf("VISA\n");
    }

    else if (digits > 16 || digits < 12)
    {
        printf("INVALID\n");
    }
}