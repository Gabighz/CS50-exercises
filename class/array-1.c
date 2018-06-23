#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
     // print arguments
     for (int i = 0; i < argc; i++)
     {
          for (int j = 0, n = strlen(argv[i]); j < n; j++)
          {
               printf("%c\n", argv[i][j]); // [i] = i'th string in argv; [j] = get the j'th char in that string (strings are arrays of chars)
          }
          printf("\n");
     }
}
