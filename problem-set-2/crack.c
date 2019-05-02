#include <cs50.h>
//init of password cracking program that deciphers passwords that are hashed with C's DES-based hashing system

#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int argExists(int);

int main (int argc, string argv[])
{
    int argExists1 = argExists(argc);


    if (argc != 2)
    {
        printf("Usage: ./crack key\n");
        return 1;
    }
    else
    {
        printf("Sucess!");
    }

}

int argExists(int c)
{
    if (c > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}