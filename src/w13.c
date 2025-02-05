/*********************************************
 * Id: beal6782
 * 
 * Russian Peasant Multiplication
 * 
 * Implement an algorithm for russian peasant multiplcation
 * n/2 * 2m for even
 * n-1/2 * 2m + m for odd
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void multiply(int n, int m);
void printMul(int n, int m);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int n = argc-1;
   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   multiply(x,y);
}

void multiply(int n, int m)
{
   int sum = 0;
   if (n % 2 == 0) sum = (n/2) * 2 * m;
   else if (n % 2 != 0) sum = ((n-1)/2) * 2 * m + m;

   while (n >= 1)
   {
      if (n % 2 == 0)
      {
         printf("%6d %6d\n", n,m);
         n /= 2;
         m *= 2;
         //printf("%6d %6d\n", n,m);
      }
      else
      {
         printf("%6d %6d %6d\n", n,m,m);
         n = n-1;
         n /= 2;
         //int tmp = m;
         m *= 2;
      }
   }
   printf("%20s\n", "------");
   printf("%20d\n", sum);

}

/*
Russian Peasant Multiplication

Implement the Russian Peasant Multiplication

Print every integer as 6 digits. I.e.:
   printf("%6d %6d\n", n,m);
   printf("%6d %6d %6d\n", n,m,m);

The last lines should be 20 chars. I.e.:
   printf("%20s\n", "------");
   printf("%20d\n", sum);

The two numbers to be multiplied togetehr should be command line arguements.

For example:
./w12 50 65
    50     65
    25    130    130
    12    260
     6    520
     3   1040   1040
     1   2080   2080
              ------
                3250

*/