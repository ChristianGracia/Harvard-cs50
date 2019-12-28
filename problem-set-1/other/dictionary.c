// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
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
        node *hashNode = malloc(sizeof(node));
        
        //copy word into hashNode
        strcpy(hashNode->word, word);
        
        //checks if there is a pointer at index(key) of the hash table
        if (hashtable[key] == NULL) 
        {
            hashtable[key] = hashNode;
            hashNode->next = NULL;
        }
        //hashNode's next pointer goes to the table and its current pointer goes to the node
        else 
        {
            hashNode->next = hashtable[key];
            hashtable[key] = hashNode;
        }
        //increment words loaded in counter
        wordCounter++;
    }
    
    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

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
    //create temp variable
    char temp[strlen(word) + 1];
    
    //copy string from word to temp variable
    strcpy(temp, word);

    //get table index from hash
    int key = hash(word);
    
    //create trav
    node *trav = hashtable[key];

    while (trav != NULL)
    {
        if (strcasecmp(trav->word, temp) == 0)
        {
            return true;
        }
        trav = trav->next;
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N;)
    {
        while (hashtable[i])
        {
            node *trav = hashtable[i];
            hashtable[i] = trav->next;
            free(trav);
        }
        i++;
    }
    return true;
}
