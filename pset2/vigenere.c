#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// I have 2 bugs which I couldn't fix, unfortunately

int main(int argc, string argv[])
{

    // checks for valid user input
    if (argc != 2)
    {
        printf("Enter alphabetical characters as your encryption key: \n");
        return 1;
  }
  else
    {
        string key = argv[1];
      
        string plaintext = GetString();
        int keylenght = strlen(key);

        // encryption algorithm
        for (int i = 0, k = 0, n = strlen(plaintext);  i < n ; i++)
        {
            // checks for alphabetic characters
            if (isalpha(plaintext[i]))
            {
                // checks for upper case characters
                if (isupper(plaintext[i]))
                {
                    // encryption and printing of upper case characters
                    printf("%c", ((((plaintext[i] - 'A') + key[k % keylenght] - 'A') % 26) + 'A'));
                    k++;
         }
                // checks for lower case characters
                if (islower(plaintext[i]))
                {
                    // encryption and printing of lower case characters
                    printf("%c", ((((plaintext[i] - 'a') + key[k % keylenght] - 'a') % 26) + 'a'));
                    k++;
        }
       }

        else
            {
                // prints out other characters such as space and punctuation
                printf("%c", plaintext[i]);
        }
         
      }
        printf("\n");
        return 0;
  
  }
}
