
/*********************************************
 * Id: beal6782
 * 
 * Insertion Sort. w11
 * 
 * Implement insertion sort
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void insertion_sort(int n, int * a);
void printArray(int n, int * a);
void swap(int * arr, int i, int j);

int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int n = argc-1;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      arr[i] = atoi(argv[i+1]);
   }

   insertion_sort(n, arr);
   printArray(n, arr);
}


void swap(int * arr, int i, int j)
{
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}

void insertion_sort(int n, int * a)
{
   printArray(n, a);
   for (int i = 1; i < n; i++)
   {
      int v = a[i];
      int j = i-1;
      while (j >= 0 && a[j]>v)
      {
         a[j+1] = a[j];
         j--;
      }
      a[j+1] = v;
      printArray(n, a);
   }
}

void printArray(int n, int * a)
{
   static int pivot = 0;
   for (int i = 0; i < n; i++)
   {
      if (i == pivot && i != 0)
      {
         printf("| %d ", a[i]);
      }
      else
         printf("%d ", a[i]);
   }
   printf("\n");
   pivot++;
}
/*W
Insertion sort

Assume that A[n-2] elements are already sorted. All we need is to find an appropriate position for A[n − 1] among the sorted elements and insert it there.
 This is usually done by scanning the sorted subarray from right to left until the first element smaller than or equal 
 to A[n − 1] is encountered to insert A[n − 1] right after that element. 
 The resulting algorithm is called straight insertion sort or simply insertion sort.

Though insertion sort is clearly based on a recursive idea, it is more efficient to implement this algorithm bottom up, i.e., iteratively. 
Starting with A[1]and ending with A[n − 1],A[i]is inserted in its appropriate place among the first i elements of the array that 
have been already sorted (but, unlike selection sort, are generally not in their final positions). 

Here is pseudocode of this algorithm.

//Sorts a given array by insertion sort
//Input: An array A[0..n − 1] of integers given as command line arguements
//Output: Array A[0..n − 1] sorted in nondecreasing order
ALGORITHM   InsertionSort(A[0..n − 1])
   printArray
   for i ← 1 to n − 1 do 
      v ← A[i] 
      j ← i − 1
      while j ≥ 0 and A[j]> v do 
         A[j + 1]← A[j] 
         j ← j − 1
      A[j + 1] ← v
      printArray
 
FIGURE 4.3 Iteration of insertion sort: A[i] is inserted in its proper position among the preceding elements previously sorted.
   4.1   Insertion Sort
   89  | 45 68 90 29 34 17
   45 89  | 68 90 29 34 17
   45 68 89  | 90 29 34 17
   45 68 89 90  | 29 34 17
   29 45 68 89 90  | 34 17
   29 34 45 68 89 90  | 17
   17 29 34 45 68 89  90
Example of sorting with insertion sort. A vertical bar separates the sorted part of the array from the remaining elements; the element being inserted is in bold.
*/