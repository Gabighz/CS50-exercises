#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // initialize height
    int height;
  
  // prompts the user for the height; rejects if the height is 0
    do
    {
        printf("Height of half-pyramid: ");
        height = GetInt();
        if ( height == 0 )
        {
            return 0;
     }
    }
    // parameters for height
   while ( height > 23 || height < 0);
    
   // main loop for the height of half-pyramid
    for(int row = 0; row < height; row++)
    {
        { 
            // loop for creating space
            for(int space = 0; space < (height - row - 1) ; space++)
            {
                printf(" "); 
   }
            // loop for creating blocks
            for(int column = 0; column < (row + 2); column++)
            {            
                printf("#");
  
   }
            // prints a new line
            printf("\n"); 
  }  
 }     
        // closes the loop
        return 0;
 
}  
