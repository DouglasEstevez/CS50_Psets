// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <cs50.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (LENGTH * 'z') ;

// Hash table
node *table[N];

//Count the number of words
int contador = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to abotain the value
    int tabela = hash(word);

    //Creating a cursor
    node *cursor = table[tabela];

    //Loop to find the word
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //variable to add each letter
    int sum = 0;
    int div = 0;
    int y = 0;

    //Loop to pass for each latter
    for (int i = 0, x = strlen(word); i < x; i++)
    {
        sum += tolower(word[i]); //* i);
        //Do not know why dividingto make less pointers in the same position makes case sensitive?
        //div += tolower(word[i]);
        //y = sum / div;
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Fist open the dictionary
    FILE *file = fopen(dictionary, "r");
    //check if is relly open
    if (file == NULL)
    {
        return false;
    }

    //Loop to read and copy the dictionary
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        //Alocate memory to save the words
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        //copy the words to the node
        strcpy(new_node->word, word);
        new_node->next = NULL;

        //obtain hash value
        int tabela = hash(word);

        //Insert node into hash table in the location
        if (table[tabela] == NULL)
        {
            table[tabela] = new_node;
        }
        else
        {
            new_node->next = table[tabela];
            table[tabela] = new_node->next;
        }
        contador++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //Contador stored the total os words
    return contador;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *header = table[i];
        node *cursor = header;
        node *tmp = header;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
