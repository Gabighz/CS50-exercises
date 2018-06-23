/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n - 1;

    while (min <= max)
    {
        int middle = (max + min) / 2;
      
        if (values[middle] == value)
        {
            return true;
      }
      
      else if (values[middle] < value)
        {
            min = middle + 1;
      }
      else if (values[middle] > value)
        {
            max = middle - 1;
      }
  }
  
    return false;
  
}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n)
{

    bool swaps;
  
    do
    {
        for (int k = 0; k < n - 1; k++)
        {
            swaps = false;
            for (int i = 0; i < n - 1 - k; i++)
            {
                if (values[i] > values[i + 1])
                {
                    int tmp = values[i];
                    values[i] = values[i + 1];
                    values[i + 1] = tmp;
                    swaps = true;
        }

       }
       }
     }
     while (swaps);
    return;
  }
       

