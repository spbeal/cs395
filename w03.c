/*********************************************
 * Id: beal6782
 * 
 * Extremely inefficient algrorithm for 2^n
 *********************************************/ 

// VERSION 2
#include <stdio.h>
#include <stdlib.h>

int calculateExpoRec(int value);
int calculateExpoLoop(int value);


int main (int argc, char *argv[])
{
   if (argc < 2 && argc > 2)
   {
      printf("%s 1 2 3 4", argv[0]);
      exit(1);
   }

   // int n = argc-1;
   int value;
   value = atoi(argv[1]);

   int output = 0;
   output = calculateExpoRec(value);
   printf("%d\n", output);
}

// Function to find 2^n, value = n;
// 2^n = (2^n-1) + 2^(n-1)
int calculateExpoRec(int value)
{
   if (value < 1)
   {
      return 1;
   }

   return calculateExpoRec(value-1) + calculateExpoRec(value-1); 

   // Efficient
   //return 2 * calculateExpoRec(--value);
   // Worse
   //return 2 * calculateExpoRec(value-2) + 2 * calculateExpoRec(value-2);
}
