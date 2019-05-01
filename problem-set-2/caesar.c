//Caesar cypher, user inputs an integer and then is prompted for text to be encrypted using the integer as a key
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int checkValid(string, int);
int argExists(int);

int main(int argc, string argv[])
{
    string key = argv[1];
    int argExists1 = argExists(argc);
    int valid = checkValid(key, argc);

    if (argc != 2 || key < 0 || valid < 1 || argExists1 < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        printf("Sucess\n");
        printf("%s\n", key);
        string text = get_string("input text to be encrypted: ");
        int textToNumber[strlen(text)];
        for (int i = 0; i < strlen(text); i++)
        {
            textToNumber[i] += atoi(text);
            printf("%d", textToNumber[i]);

        }
    }
}

int argExists (int c){
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
        if (isdigit(n[i]) == false)
        {
            return 0;
            break;
        }
    }
    }
    return 1;
}
