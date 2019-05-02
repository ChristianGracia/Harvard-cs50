//vigenere cipher
//user inputs a word that is used as a key to shift letters up and will repeat itself if key length < message length
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



    if (argc != 2 || argExists1 < 1 || valid < 1)
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        int keylength = strlen(key);
        printf("Success\n");
        printf("%s\n", key);

        string text = get_string("Enter text here: ");
        int length = strlen(text);
        printf("ciphertext: ");

        for (int i = 0, j = 0; i < length; i++)
        {
            if (isalpha(text[i]))
            {
                int index = j % keylength;
                int keynum = shift(key[index]);
                if islower(text[i])
                {
                    printf("%c", (((text[i] + keynum) - 97) % 26) + 97);
                }
                else if isupper(text[i])
                {
                    printf("%c", (((text[i] + keynum) - 65) % 26) + 65);
                }
                    j++;
            }
            else
            {
                printf("%c", text[i]);
            }

        }
        printf("\n");

    }
}

int shift(char c)
{
    // printf("char c = %c\n", c);
    if (c > 96)
    {
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