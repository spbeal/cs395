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

void calculateRecCyclic(int disks, char src_tower, char aux_tower, char dest_tower, bool special);
void disk1(char src_tower, char aux_tower, char dest_tower);
void disk2(char src_tower, char aux_tower, char dest_tower);
void disk3(char src_tower, char aux_tower, char dest_tower);
void patternACB(char src_tower, char aux_tower, char dest_tower);
void Cyclic(int disks, char src_tower, char aux_tower, char dest_tower);
void Cyclic2(int disks, char src_tower, char aux_tower, char dest_tower);
void CyclicAgain(int n, char from, char to, char with);
void CyclicHanoi(int disks, char src, char aux, char dest);

int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s (int)", argv[0]);
      exit(1);
   }

   //int args = argc-1;
   int disks = atoi(argv[1]);
   
   //CyclicHanoi(disks, 'A', 'B', 'C');
   // a c b
   //Cyclic(disks, 'A', 'B', 'C');
   CyclicAgain(disks, 'A', 'C', 'B');
   //printf("\n\n\n\n\n\n");
   //Cyclic2(disks, 'A', 'B', 'C');
  // printf("\n\n\n\n\n\n");
   //CyclicAgain(disks, 'A', 'C', 'B');
   //calculateRecCyclic(disks, 'A', 'B', 'C', false);
   // printf("Move %s TO %s", curr, next);

}

void Cyclic(int disks, char src_tower, char aux_tower, char dest_tower) {
   if (disks == 0) return;
   // if (disks == 1)
   // {
   //    disk1(src_tower, aux_tower, dest_tower);
   //    return;
   // }
   // if (disks == 2)
   // {
   //    disk2(src_tower, aux_tower, dest_tower);
   //    return;
   // }
   // if (disks == 3)
   // {
   //    disk3(src_tower, aux_tower, dest_tower);
   //    return;
   // }
      // a to b (3)
      // c to a (1)

      // a to b (1)
      // c to a (2)
      // b to c (3)

      // c to a (1)
      // b to c (3)

   Cyclic(disks-1, src_tower, aux_tower, dest_tower);
   printf("Move %c TO %c\n", src_tower, aux_tower);
   if (disks > 1)
   {
      // c to a
      if (disks == 3) {
         printf("Move %c to %c\n", dest_tower, src_tower);
      }
      
      Cyclic(disks-1, src_tower, aux_tower, dest_tower);
      printf("Move %c to %c\n", dest_tower, src_tower);
      Cyclic(disks-1, aux_tower, dest_tower, src_tower);

      if (disks == 3) {
         printf("Move %c to %c\n", dest_tower, src_tower);
      }
      // c to a
   }
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   Cyclic(disks-1, src_tower, aux_tower, dest_tower);

    // if n = 0 then 0
    // Qn + Qn-1 + 2
    // Qn = 2Rn-1 + 2
}

// 
void Cyclic2(int disks, char src_tower, char aux_tower, char dest_tower) 
{
   if (disks < 1)
   {
      return;
   }
   if (disks == 1) {    
      //disk1(src_tower, aux_tower, dest_tower);
   }

   Cyclic(disks-1, src_tower, aux_tower, dest_tower);
   printf("Move %c TO %c\n", src_tower, aux_tower);
   if (disks > 1)
   {
      Cyclic(disks-2, src_tower, aux_tower, dest_tower);
      printf("Move %c to %c\n", dest_tower, src_tower);
      Cyclic(disks-2, aux_tower, dest_tower, src_tower);
   }
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   Cyclic(disks-1, src_tower, aux_tower, dest_tower);
   return;
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
      Cyclic(n-2, to, with, from);
      printf("Move %c to %c\n", to, from);
      Cyclic(n-2, with, from, to);
   }
   // c b
   printf("Move %c TO %c\n", with, to);
   // a c b 
   CyclicAgain(n-1, from, to, with);
}

// psuedocode
void calculateCyclic(int disks, char src_tower, char aux_tower, char dest_tower)
{
   if (disks == 1)
   {
      // a to b
      // b to c
   }
   if (disks == 2)
   {
      /* disks == 1 or: */
      // a to b
      // b to c

      // a to b
      // c to a
      // b to c

      /* disks == 1 or: */
      // a to b
      // b to c
   }
   if (disks == 3)
   {
      // repeat disks == 2

      // a to b (3)
      // c to a (1)

      // a to b (1)
      // c to a (2)
      // b to c (3)

      // c to a (1)
      // b to c (3)

      // repeat disk == 2
   }
}
// pattern a to b, c to a, b to c
void patternACB(char src_tower, char aux_tower, char dest_tower)
{
   printf("Move %c TO %c\n", src_tower, aux_tower);
   printf("Move %c TO %c\n", dest_tower, src_tower);
   printf("Move %c TO %c\n", aux_tower, dest_tower);
}
// disk 1 print
void disk1(char src_tower, char aux_tower, char dest_tower)
{
   printf("Move %c TO %c\n", src_tower, aux_tower);
   printf("Move %c TO %c\n", aux_tower, dest_tower);
}
// disk 2 print
void disk2(char src_tower, char aux_tower, char dest_tower)
{
   disk1(src_tower, aux_tower, dest_tower);
   patternACB(src_tower, aux_tower, dest_tower);
   disk1(src_tower, aux_tower, dest_tower);
}
// disk 3 print
void disk3(char src_tower, char aux_tower, char dest_tower)
{
   disk2(src_tower, aux_tower, dest_tower);
   // a to b, c to a
   printf("Move %c TO %c\n", src_tower, aux_tower);
   printf("Move %c TO %c\n", dest_tower, src_tower);
   patternACB(src_tower, aux_tower, dest_tower);
   // c to a, b to c
   printf("Move %c TO %c\n", dest_tower, src_tower);
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   disk2(src_tower, aux_tower, dest_tower);

}

void calculateRecCyclic(int disks, char src_tower, char aux_tower, char dest_tower, bool special)
{
   if (disks == 0) return;
   if (disks == 1)
   {
      disk1(src_tower, aux_tower, dest_tower);
      return;
   }
   if (disks == 2)
   {
      disk2(src_tower, aux_tower, dest_tower);
      return;
   }
   if (disks == 3)
   {
      disk3(src_tower, aux_tower, dest_tower);
      return;
   }
   // if (disks == 2)
   // {
   //    disk2(src_tower, aux_tower, dest_tower);
   //    return;
   // }
   // if (disks == 3)
   // {
   //    disk3(src_tower, aux_tower, dest_tower);
   //    return;
   // }

   // Sol 2
   // ----------------------   
   // calculateRecCyclic(disks-1, src_tower, dest_tower, aux_tower, special);
   // printf("Move %c TO %c\n", src_tower, dest_tower);
   // calculateRecCyclic(disks-1, aux_tower, src_tower, dest_tower, special);

   // ----------------------

   // Sol 1
   // ----------------------
   calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower, special);
   printf("Move %c TO %c\n", src_tower, aux_tower);
   calculateRecCyclic(disks-1, dest_tower, src_tower, aux_tower, special);
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower, special);
   // ----------------------
   
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower, special);
   // printf("Move %c TO %c\n", src_tower, aux_tower);
   // printf("Move %c TO %c\n", dest_tower, src_tower);
   // //patternACB(src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower, special);
   // // c to a, b to c
   // printf("Move %c TO %c\n", dest_tower, src_tower);
   // printf("Move %c TO %c\n", aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower, special);


   // a to b, c to a, b to c, c to a
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);
   // printf("Move %c TO %c\n", src_tower, aux_tower);
   // printf("Move %c TO %c\n", aux_tower, dest_tower);
   // patternACB(src_tower, aux_tower, dest_tower);
   // printf("Move %c TO %c\n", src_tower, aux_tower);
   // printf("Move %c TO %c\n", aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);

   // calculateRecCyclic(disks-2, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-2, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-2, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-2, src_tower, aux_tower, dest_tower);
   // calculateRecCyclic(disks-2, src_tower, aux_tower, dest_tower);

   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);
   // printf("Move %c TO %c\n", src_tower, aux_tower);
   // printf("Move %c TO %c\n", dest_tower, src_tower);
   // printf("Move %c TO %c\n", aux_tower, dest_tower);
   // calculateRecCyclic(disks-1, src_tower, aux_tower, dest_tower);


}