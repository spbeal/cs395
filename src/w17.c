/*********************************************
 * Id: beal6782
 * 
 * Robot Coin Collecting
 * 
 * Implement an algorithm for Robot Coin Collecting
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void engine(int x, int y, char ** arr)
{
    int **board = (int**)malloc(x * sizeof(int*));
    if (!board) { perror("malloc failed"); exit(1); }

    for (int i = 0; i < x; i++) {
        board[i] = (int*)malloc(y * sizeof(int));
        if (!board[i]) { perror("malloc failed"); exit(1); }
        memset(board[i], 0, y * sizeof(int));  // Initialize with 0
    }

    board[0][0] = (arr[0][0] == '1') ? 1 : 0;
    board[1][1] = (arr[1][1] == '1') ? 1 : 0;

    for (int j = 1; j < y; j++) {
        if (arr[0][j] != 'X') {
            if (arr[0][j] == '1')
                board[0][j] = board[0][j - 1] + (arr[0][j] == '1' ? 1 : 0);
            else board[0][j] = (board[0][j - 1] == 0) ? 0 : board[0][j - 1] + (arr[0][j] == '1' ? 1 : 0);
        }
        else {
            break;
        }
    }
    for (int i = 1; i < x; i++) {
        if (arr[i][0] != 'X') {
            if (arr[i][0] == '1')
                board[i][0] = board[i - 1][0] + (arr[i][0] == '1' ? 1 : 0);
            else board[i][0] = (board[i - 1][0] == 0) ? 0 : board[i - 1][0] + (arr[i][0] == '1' ? 1 : 0);
        }
        else {
            break;
        }
    }

    // Fill in the rest of the board
    int k = 1;
    for (int i = 1; i < x; i++) {
        for (int j = k; j < y; j++) {
            int above = (board[i - 1][j]) == 'X' ? 0 : board[i-1][j];
            int left = (board[i][j - 1]) == 'X' ? 0 : board[i][j-1];
            if (arr[i][j] != 'X') {
                
                // If both paths are zero this cell remains zero
                if (above != 0 || left != 0) {
                    board[i][j] = MAX(above, left) + (arr[i][j] == '1' ? 1 : 0);
                }
            }
            // else
            // {
            //     // if (arr[i][j] == 'X') {
            //     //     //k++;
            //     //     //break;
            //     // }
            // }
        }
    }


   printf("Coin Collecting Table:\n");
   for (int i = 0; i < x; i++) {
       for (int j = 0; j < y; j++) 
           printf("%d\t", board[i][j]);
       printf("\n");
   }
   printf("\n");

   printf("The optimal path with this board is: %d\n", board[x - 1][y - 1]);

   for (int i = 0; i < x; i++) {
       free(board[i]);
   }
   free(board);
}

int main (int argc, char *argv[])
{
    if (argc < 3) {
        printf("%s <columns> <rows> <cell values>...\n", argv[0]);
        exit(1);
    }
//    printf("\n");
//    for (int i = 3; i < argc; i++)
//    {
//       printf("%s ", argv[i]);
//    }
//    printf("\n");

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if (x <= 0 || y <= 0) {
        printf("Error: Invalid dimensions.\n");
        exit(1);
    }

    char **arr = (char**)malloc(x * sizeof(char*)); 
    if (!arr) { perror("malloc failed"); exit(1); }  
    for (int i = 0; i < x; i++) {
      arr[i] = (char*)malloc(y * sizeof(char));
      if (!arr[i]) { perror("malloc failed"); exit(1); }
      memset(arr[i], 0, y * sizeof(char));
    }
    int k = 3;  
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (k < argc) {
                arr[i][j] = argv[k++][0];
            } else {
                printf("Error: Insufficient arguments for board values.\n");
                exit(1);
            }
        }
    }

    printf("Board Inputed:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

   engine(x,y,arr);
   
   for (int i = 0; i < x; i++)
   {
        free(arr[i]);
   }
   free(arr);
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