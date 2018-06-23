#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{

 

    string name = GetString();
  
    // makes sure the string is not null
    if (name != NULL)
    {
 
        // capitalization of the first name
        for (int j = 0; j < 1; j++)
        {
    
            printf("%c", toupper(name[0]));
    
   }
        // capitalization of the last name
        for (int i = 0; i < strlen(name); i++)
        {
            // I've learnt about isblank() from cs50.stackexchange.com
            if (isblank(name[i]))
            {
  
                printf("%c", toupper(name[i + 1]));
 
  }
  
 } 
        printf("\n");
 }
    return 0;
}
