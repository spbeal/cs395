/*********************************************
 * Id: beal6782
 * 
 * Tower of Hanoi 3. Cyclic
 * Solve the puzzle of the Tower of Hanoi
 * 
 * Obj is to move all disks to tower 3 src_tower 1
 * Using A to B, B to C, and C to A
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <stdbool.h>

void Cyclic(int disks, char src_tower, char dest_tower, char aux_tower);

int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s (int)", argv[0]);
      exit(1);
   }

   //int args = argc-1;
   int disks = atoi(argv[1]);
   Cyclic(disks, 'A', 'C', 'B');

}

void Cyclic(int disks, char src_tower, char dest_tower, char aux_tower) 
{
   if (disks == 0) {    
      return;
   }
   // Movement requirements: 2, 7, 7*3, etc...

   // a c b
   Cyclic(disks-1, src_tower, dest_tower, aux_tower);
   // a b
   printf("Move %c TO %c\n", src_tower, aux_tower);

   // missing c to a and b to c at end middle for 3 disks
   if (disks >= 2)
   {
      // c b a, c a, b a c
      Cyclic(disks-2,  dest_tower, aux_tower, src_tower);
      // C to A
      printf("Move %c to %c\n", dest_tower, src_tower);
      Cyclic(disks-2, aux_tower, src_tower, dest_tower);
   }
   // b c
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   // a c b 
   Cyclic(disks-1, src_tower, dest_tower, aux_tower);
}