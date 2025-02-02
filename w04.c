/*********************************************
 * Id: beal6782
 * 
 * Implement Algorithm using Gaussian Elimination
 * To solve a system of linear equations
 *********************************************/ 

// VERSION 2
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, float A[n][n+1]);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s 3 2 3 4", argv[0]);
      exit(1);
   }

   //int args = argc-1;
   int n = atoi(argv[1]);
   // int equation = atoi(argv[1]);

   float A[n][n+1];
   int counter = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n+1; j++)
      {
         A[i][j] = atoi(argv[counter+2]);
         counter++;
      }
   }

   printMatrix(n, A);
   for (int i = 0; i <= n-2; i++)
   {
      for (int j=i+1; j <= n-1; j++){
         float tempji = A[j][i];
         for (int k=i; k<=n; k++)
         {
            A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
         }
      }
      printMatrix(n, A);
   }
   // printMatrix(n, A);
}

// Print out the matrix
void printMatrix(int n, float A[n][n+1])
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n+1; j++)
      {
         printf("%.2f ", A[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}