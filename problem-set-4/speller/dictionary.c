// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

//counter for words loaded into dictionary
int wordCounter = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        //get index of hashtable to put word in
        int key = hash(word);
        
        //create node for word and allocate memory
        node* hashNode = malloc(sizeof(node));
        
        //copy word into hashNode
        strcpy(hashNode->word, word);
        
        //checks if there is a pointer at index(key) of the hash table
        if (hashtable[key] == NULL) {
            
            hashtable[key] = hashNode;
            hashNode->next = NULL;
        }
        //hashNode's next pointer goes to the table and its current pointer goes to the node
        else 
        {
            hashNode->next = hashtable[key];
            hashtable[key] = hashNode;
        }
        
        //increment word loaded in counter
        wordCounter++;
    }
    
    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}
bool unload(void); 
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (wordCounter > 0)
    {
        return wordCounter;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    
    
    //find length of word for memory allocation of temp variable
    int letters = strlen(word);
    
    //convert word to lower case using a temp variable to store
    char *tempWord = malloc(4*letters);
    
    //make all letters lowercase with a loop
    for (int i = 0; i < letters; i++)
    {
        tempWord[i] = tolower(word[i]);
    }
    
    //add \0 to end to signal end of word
    tempWord[letters] = '\0';
    
    //find key of table using hash function
    int key = hash(tempWord);
    
    //check if table even has indices filled with the corresponding letter
    if (hashtable[key] == NULL)
    {
        return false;
    }
    if (strcmp(hashtable[key]->word, word) == 0)
    {
            return true;
    }
    
    else {
        
        while(1)
            {
                node* trav = hashtable[key];
                hashtable[key] = trav->next;
                if (strcmp(hashtable[key]->word, word) == 0)
                {
                    break;
                    return true;
                }
                else {
                    trav = hashtable[key]->next;
                }
            }
            return false;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N;)
    {
        while (hashtable[i]->next != NULL)
        {
            node* trav = hashtable[i];
            hashtable[i] = trav->next;
            free(trav);
        }
            i++;
    }
    return true;
}
