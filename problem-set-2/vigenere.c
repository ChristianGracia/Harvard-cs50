#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int argExists(int);
int checkValid(string, int);

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
        string text = get_string("Enter text here: ");
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