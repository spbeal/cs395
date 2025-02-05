/*********************************************
 * Id: beal6782
 * 
 * Quick Sort. w10
 * 
 * Implement quick sort using Hoare Partition
 * Sort a subarray of an array of integers.
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void quick_sort(int n, int * arr, int l, int r);
void printArray(int n, int * arr, int l, int r);
int HoarePartition(int * arr, int l, int r);

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
      //printf("%d ", arr[i]);
   }
   //printf("\n\n");
   int l = 0;
   int r = n-1;
   quick_sort(n, arr, l, r);
   printArray(n, arr, l, r);
   // if (n < 2 && n > 0)
   // {
   //    //printf("[%d]", arr[0]);
   // }
   // else
   // {
   //    int l = 0;
   //    int r = n-1;
   //    quick_sort(n, arr, l, r);
   // }
}

void swap(int * arr, int i, int j)
{
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}

void quick_sort(int n, int * arr, int l, int r)
{
   if (l < r)
   {
      int s = HoarePartition(arr, l, r);
      quick_sort(n,arr, l, s-1);
      quick_sort(n,arr, s+1, r);
      printArray(n, arr, l, r);
   }
}

int HoarePartition(int * arr, int l, int r)
{
   int p = arr[l];
   int i = l;
   int j = r + 1;

   while (i < j){
      do {
         //printf("i: %d ", i);
         i++;
      } while (i<= r && arr[i] < p);
      do {
         //printf("j: %d ", j);
         j--;
      } while (j >= l && arr[j] > p);
      if (i >= j) break;
      
      swap(arr, i, j);
   }
   //swap(arr, i, j);
   swap(arr, l, j);
   return j;
}

void printArray(int n, int * arr, int l, int r)
{
   for (int i = 0; i < n; i++)
   {
      if (i == l)
      {
         printf("[%d ", arr[i]);
      }
      else if (i == r)
      {
         printf("%d]  ", arr[i]);
      }
      else
      {
         printf("%d ", arr[i]);
      }
   }
   printf("\n");
}


/*
Implement the following algorithm for using Quick Sort to sort an array of elemnts.

//Sorts a subarray by quicksort
//Input: Subarray of array A[0..n − 1], of integers defined by its left and right
// indices l and r
//Output: Subarray A[l..r] sorted in nondecreasing order
Quicksort(A[l..r])
   if l < r
      s ← HoarePartition(A[l..r]) //s is a split position
      Quicksort(A[l..s − 1])
      Quicksort(A[s + 1..r])
      printSubArray

//Partitions a subarray by Hoare’s algorithm, using the first element
// as a pivot
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r (l<r)
//Output: Partition of A[l..r], with the split position returned as
// this function’s value
HoarePartition(A[l..r])
   p←A[l]
   i ←l; 
   j ←r + 1
   repeat
      repeat i ←i + 1 until A[i]≥ p
      repeat j ←j − 1 until A[j ]≤ p
      swap(A[i], A[j ])
   until i ≥ j
   swap(A[i], A[j ]) //undo last swap when i ≥ j
   swap(A[l], A[j ])
   return j

Print out the subarray at each step. Enclose the active portion in []. For example:
.QuickSort 3 4 5 2 3 4
[2 3]  3 5 4 4
2 3 3 [4 4]  5
2 3 3 [4 4 5]
[2 3 3 4 4 5]
[2 3 3 4 4 5]
*/