/*********************************************
 * Id: beal6782
 * 
 * Tower of Hanoi 3. Cyclic
 * Solve the puzzle of the Tower of Hanoi
 * 
 * Obj is to move all disks to tower 3 from 1
 * Using A to B, B to C, and C to A
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // exp2(value);
#include <stdbool.h>

void CyclicAgain(int n, char from, char to, char with);

int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s (int)", argv[0]);
      exit(1);
   }

   //int args = argc-1;
   int disks = atoi(argv[1]);
   CyclicAgain(disks, 'A', 'C', 'B');

}


void CyclicAgain(int n, char from, char to, char with) 
{
   if (n < 1) {    
      return;
   }
   // a c b
   CyclicAgain(n-1, from, to, with);
   // a b
   printf("Move %c TO %c\n", from, with);

// missing c to a and b to c at end middle for 3 disks
   if (n > 1)
   {
      // c b a, c a, b a c
      CyclicAgain(n-2, to, with, from);
      printf("Move %c to %c\n", to, from);
      CyclicAgain(n-2, with, from, to);
   }
   // c b
   printf("Move %c TO %c\n", with, to);
   // a c b 
   CyclicAgain(n-1, from, to, with);
}