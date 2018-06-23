#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{

    float quarter = 25, dime = 10, nickle = 5, penny = 1, dollar;

    int coins = 0;
    int cents;
  
    // prompts the user for the value of change in valid parameters
    do
    {
        printf("How much change is owed?\n");
        dollar = GetFloat();
        if (dollar == 0)
        {
            return 0;
   }
  }
    while (dollar <= 0);
  
    // conversion from dollar to cents
    cents = (int) roundf(dollar * 100);
  
    // takes as many quarters as possible from the value of cents
    while( quarter <= cents )
    {
        cents = cents - quarter;
        coins++; 
   }
  
    // takes as many dimes as possible from the value of cents
    while( dime <= cents )
    {
        cents = cents - dime;
        coins++; 
   }
    
    // takes as many nickles as possible from the value of cents
    while( nickle <= cents )
    {
        cents = cents - nickle;
        coins++; 
   }
   
   // takes as many pennies as possible from the value of cents
    while( penny <= cents )
    {
        cents = cents - penny;
        coins++; 
   }


   // prints how many coins were used
    printf("%d\n",coins);
   
    return 0; 
}
