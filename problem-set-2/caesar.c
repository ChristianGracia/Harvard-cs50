//Caesar cypher, user inputs an integer and then is prompted for text to be encrypted using the integer as a key
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    string key =  argv[1];
    int valid = 0;

    for (int i = 0; i < strlen(key); i++){
          if (isdigit(key[i]) == false){
            return 0;
        }
        else {
            valid = 1;
        }
    }

    if (argc != 2 || key < 0 || valid < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        printf("Sucess\n");
        printf("%s\n", key);
        string text = get_string("input text to be encrypted: ");
        int textToNumber = atoi(text);

        printf("%i\n", textToNumber);
    }


}