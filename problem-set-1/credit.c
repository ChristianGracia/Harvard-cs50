#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>

int firstDigit(int n)
{

    while
    (n >= 10)
    {
        n /= 10;
    }
    return n;
}
int first2Digit(int n)
{
    while
    (n >= 100)
    {
        n /= 10;
    }
    return n;

}
long long countCheck(long long num)
{
    int count = 0;
    while (num > 0)
    {
        num = num / 10;
        count = count + 1;
    }
    return count;
}

int main(void)
{
    long long credit = get_long_long("Enter Credit Card Number: ");
    long long n = credit;
    int first = firstDigit(credit / 1000000000);
    long long digits = countCheck(credit) + 1;
    long long cardDigits[digits];
    int first2 = first2Digit(credit / 100000000);

    for (int i = (digits - 1); i >= 0; i--)
    {
        cardDigits[i] = credit % 10;
        credit = floor(credit / 10);
    }


    long long doubleOdd[digits];


    for (int j = (digits - 2), l = 0; j >= 0; j -= 2, l++)
    {
        doubleOdd[l] = cardDigits[j] * 2;
    }

    int sum = 0;
    for (int m = 0; m <= ((digits - 2) / 2); m++)
    {
        if (doubleOdd[m] > 9)
        {
            sum = sum + ((floor(doubleOdd[m] / 10)) + (doubleOdd[m] % 10));
        }
        else
        {

            sum = sum + doubleOdd[m];
        }
    }

    int sumEven = 0;

    for (int k = digits - 1; k >= 0 ; k -= 2)
    {
        int evenDigit = cardDigits[k];
        sumEven = sumEven + evenDigit;
    }

    int check = (sumEven + sum) % 10;


    if (digits > 17 || digits < 12 || check >= 1)
    {
        printf("INVALID\n");
    }

    else if (check < 1)
    {
        if (first2 == 37 || first2 == 34)
        {
            printf("AMEX\n");
        }
        if (first2 == 51 || first2 == 51 || first2 == 52 || first2 == 53 || first2 == 54 || first2 == 55)
        {
            printf("MASTERCARD\n");
        }
        if (first == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

}