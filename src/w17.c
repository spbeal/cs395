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

   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   multiply(x,y);
}

/*
Modified Robot Coin Collecting

Consider thsi algorithm:

//Applies dynamic programming to compute the largest number of
//coins a robot can collect on an n × m board by starting at (1, 1)
//and moving right and down from upper left to down right corner
//Input: Matrix C[1..n, 1..m] whose elements are equal to 1 and 0
//for cells with and without a coin, respectively
//Output: Largest number of coins the robot can bring to cell (n, m)
RobotCoinCollection(C[1..n, 1..m])
   F[1, 1]←C[1, 1]; 
   for j ←2 to m do 
      F[1, j]←F[1, j − 1]+ C[1, j]
   for i ←2 to n do
      F[i, 1]←F[i − 1, 1]+ C[i, 1]
      for j ←2 to m do
         F[i, j ]←max(F [i − 1, j], F[i, j − 1]) + C[i, j ]
   return F[n, m]

Modify this algorithm so some cells on the board (indecated by and 'X' are inaccessible for the robot.

The input should be command line arguements in the format Columns Rows <Cell content>*
0 indicates the cell is empty. 1 indicates the cell has a coin in it. X indicates the cell is inexcessable.

for example
./robotCoin 5 6 0 X 0 1 0 0 1 0 0 X 1 0 0 1 0 X 1 0 0 0 0 1 0 1 X X X 0 1 0

Should produce this output:
Board Inputed:
0       X       0       1       0       0
1       0       0       X       1       0
0       1       0       X       1       0
0       0       0       1       0       1
X       X       X       0       1       0

Coin Collecting Table:
0       0       0       0       0       0
1       1       1       0       0       0
1       2       2       0       0       0
1       2       2       3       3       4
0       0       0       3       4       4

The optimal path with this board is: 4

Note: When you print the board, follow each value with a tab:
   printf("%d\t", board[i][j]);
Compile errors: 
0: file not recognized: File truncated
collect2: error: ld returned 1 exit status
*/