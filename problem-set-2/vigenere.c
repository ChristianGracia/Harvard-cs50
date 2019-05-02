#include <cs50.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int argExists(int);
int checkValid(string, int);
int shift(char c);

int main(int argc, string argv[])
{
    string key = argv[1];
    int argExists1 = argExists(argc);
    int valid = checkValid(key, argc);


    if (argc != 2 || argExists1 < 1 || valid < 1 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        printf("Sucess\n");
        printf("%s\n", key);

        //get string
        string text = get_string("Enter text here: ");
        int length = strlen(text);
        printf("plaintext: %s\n", text);


        char key1 = key[0];

        int keynum = shift(key1);


        printf("keynum is: %i\n", keynum);

        // for (int i = 0; i <= length; i++){

        //     if (isalpha(text[i]) == true)
        //     {
        //         printf("\n%c", text[i] + keynum);
        //     }
            // else {
            //     printf("%c\n", text[i]);
            // }

        // }

    }
}

int shift(char c){
    if (c > 96){
        return (c - 97);
    }
    else
    {
        return (c - 65);
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
int checkValid(string n, int b)
{
    if (b > 1)
    {
        for (int i = 0; i < strlen(n); i++)
        {
            if (isalpha(n[i]) == false)
            {
                return 0;
                break;
            }
        }
    }
    return 1;
}