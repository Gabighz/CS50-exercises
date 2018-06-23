/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "dictionary.h"

#define lenght 45
#define hashtable_size 65536

char word[lenght+1];
int count = 0;

char *strdup (const char *s)
{
 char *d = malloc(strlen(s) + 1);
 if(d != NULL)
 {
  strcpy(d,s);
 }
 return d;
}

/**
 * Hash function. Thanks to Brenda from cs50 reddit.
 */
 int hash_it(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % hashtable_size;
}

typedef struct node
{
 char* word;
 struct node* next;
}node;

node* previous;
node* hashtable[hashtable_size];


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
   char line[256];
   FILE *dict = fopen(dictionary,"r");
   
   if (!dict)
   {
    return false;
   }
   
   while(fgets(line, sizeof(line), dict) !=NULL)
   {
    char* p = line + strspn(line, " \t");
    
    p[strcspn(p, " \t\r\n")] = '\0';
    
    if(*p == '\0' || *p == '#' || *p == ';')
    {
     continue;
    }
    
    count++;
    
    int hashvalue = hash_it(p);
    node *np = malloc(sizeof(node));
    
    np -> word = strdup(p);
    np -> next = hashtable[hashvalue];
    hashtable[hashvalue] = np;
   }
   fclose(dict);
   return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
 
 char tmp[lenght + 1];
 int lenghtw = strlen(word);
 for (int i = 0; i < lenghtw; i++)
 {
  tmp[i] = tolower(word[i]);  
 } 
 tmp[lenghtw] = '\0';
 
 int index = hash_it(tmp);
 
 if (hashtable[index] == NULL)
 { 
   return false;
 }

 node* cursor = hashtable[index];
 
 while(cursor != NULL)
 {
  if(strcmp(tmp, cursor -> word) == 0)
  {
   return true;
  }
  cursor = cursor -> next;
 }

 return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    int index = 0;
    
    while(index < hashtable_size)
    {
     if(hashtable[index] == NULL)
     {
       index++;
     }
     else
     {
      while(hashtable[index] != NULL)
      {
       node* cursor = hashtable[index];
       hashtable[index] = cursor -> next;
       free(cursor);
      }
      index++;
     }
    }
    return true;
}
