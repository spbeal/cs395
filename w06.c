/*********************************************
 * Id: beal6782
 * 
 * Tower of Hanoi 2
 * Solve the puzzle of the Tower of Hanoi
 * 
 * Obj is to move all disks to tower 3 from 1
 * 
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // exp2(value);

// void calculateRec(int disks, char aux_tower, char dest_tower, char src_tower);
void calculateRec(int disks, char src_tower, char aux_tower, char dest_tower);

int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s (int)", argv[0]);
      exit(1);
   }

   //int args = argc-1;
   int disks = atoi(argv[1]);
   
   calculateRec(disks, 'A', 'B', 'C');
   // printf("Move %s TO %s", curr, next);

}

// recursive function to solve tower of hanoi. 
// Help from geeksforgeeks.org on their twisted solution
void calculateRec(int disks, char src_tower, char aux_tower, char dest_tower)
{
   // move disks-1 from A to B using C
   // move disks-1 from B to C using A 

   if (disks == 0) return;
   if (disks == 1) 
   {
      printf("Move %c TO %c\n", src_tower, aux_tower);
      printf("Move %c TO %c\n", aux_tower, dest_tower);
      return;
   }

   // With the recursion, we cannot switch up the parameters we pass
   // the same way we did in w05. We must only swap first and last.

   // A to B to C
   calculateRec(disks-1, src_tower, aux_tower, dest_tower);
   // Recursion will print and solve all of these moves first
   // First to middle
   printf("Move %c TO %c\n", src_tower, aux_tower);
   
   // C to B to A
   calculateRec(disks-1, dest_tower, aux_tower, src_tower);
   // Recursion will print and solve all of these moves last.
   // Middle to last
   printf("Move %c TO %c\n", aux_tower, dest_tower);
   
   // A to B to C
   calculateRec(disks-1, src_tower, aux_tower, dest_tower);

}

// loop function to solve tower of hanoi
void calculateLoop(int disks)
{
   // char stack[disks];
   // char tower1[disks] = {1};
   // char tower2[disks] = {0};
   // char tower3[disks] = {0};
   // int top1 = 0;
   // int top2 = 0;
   // int top3 = 0;
   //char curr = 'A';
   //char next = 'A';
   // int move = 0;
   // int find = 0;
   // int prev = 0;
   //int i = 0;

   // while (i < (exp2(disks)-1))
   // {
   //    i++;
   //    printf("Move %s TO %s", curr, next);
   // }
   
   // Test with 4 disks
   // Move 1 to B
   // Move 2 to C
   // Move 1 on to C (2)
   // Move 3 onto B
   // Move 1 to A
   // Move 2 to B
   // Move 1 to B
   // Move 4 to C
   // ---- Final sequence once last disk is on C ----
   // Move 1 to C
   // Move 2 to A
   // Move 1 to A
   // Move 3 to C
   // Move 1 to B
   // Move 2 to C
   // Move 1 to C

   // Number 2, 4, 6, 8, etc.. will always move onto B first.
   // Numbers 1, 3, 5, 7, 9 etc.. will always move onto C first.
   // Start with 3. Stack 3 onto a section
   // Move next biggest off, and move the three onto it. 
   // Move next biggest off, and move the four onto it.
   // Move next biggest off, and move the five onto it. 
}