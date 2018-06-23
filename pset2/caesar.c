#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

  
    // checks for valid user input
    if (argc != 2)
    {
        printf("Enter a number as your encryption key: \n");
        return 1;
  }
  else
    {
        // converts string argv[1] to integer key
        int key = atoi(argv[1]);
        // gets the plain text which needs to be encrypted
        string plaintext = GetString();
        
        // encryption algorithm
        for (int i = 0, n = strlen(plaintext); i < n ; i++)
        {
            // checks if plain text is alphabetic
            if (isalpha(plaintext[i]))
            {
                // checks for capital keys
                if (isupper(plaintext[i]))
                {
                    printf("%c", ((((int) plaintext[i] - 65) + key) % 26 + 65));
        }
        // checks for lower keys
        else if (islower(plaintext[i]))
                {
                    printf("%c", ((((int) plaintext[i] - 97) + key) % 26 + 97));
        }
        
      }
      // if above conditions are not met, just prints the text
     else
            {
                printf("%c", plaintext[i]);
     }
     
    }
        printf("\n");
        return 0;
    }
}
