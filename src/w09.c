/*********************************************
 * Id: beal6782
 * 
 * Selection Sort. w09
 * 
 * Implement selection sort.
 * Sort an array of integers
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>

int * selection_sort(int n, int * arr);
void printArray(int n, int * arr);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int n = argc-1;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      arr[i] = atoi(argv[i+1]);
      printf("%d: %d", i, arr[i]);
   }
   int * sorted_arr;
   sorted_arr = selection_sort(n, arr);
}

int * selection_sort(int n, int * arr)
{
   printArray(n, arr);
   int min = 0;
   for (int i = 0; i <= n-2; i++)
   {
      min = i;
      for (int j = i+1; j <= n-1; j++)
      {
         if (arr[j] < arr[min])
            min = arr[j];
      }
      // swap
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
      printArray(n, arr);
   }
   return arr;
}

void printArray(int n, int * arr)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
}

/*
Implement the following algorithm for using Selection Sort to sort an arrya of elemnts.

SS(A[0..n-1]) {
   // Sorts a given array by selection sort
   // Input: Array of A[0,n-1]) of integers given as command line arguements
   // Output: The integers sorted
   printArray();
   for i<-0 to n-2 do
   {
      min <- i
      for j<-i+1 to n-1 do 
         if A[j] < A[Min]
            min <- j
      swap A[i] and A[min]
      printArray();
   }

Note: in printArray, print each value as an integer places followed by space:
   printf("%d ", A[i]);
*/
