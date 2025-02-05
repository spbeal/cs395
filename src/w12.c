
/*********************************************
 * Id: beal6782
 * 
 * Compare sorts
 * 
 * Compare Insertion, Quick, and Selection sort speeds
 *********************************************/ 

/*

+-----------------------+-----------------+----------------+------------+
|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
+-----------------------+-----------------+----------------+------------+
|                   5000|               50|              30|           1|
|                  10000|              184|             121|           2|
|                  20000|              742|             478|           4|
+-----------------------+-----------------+----------------+------------+

+-----------------------+-----------------+----------------+------------+
|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
+-----------------------+-----------------+----------------+------------+
|                   5000|               48|              31|           1|
|                  10000|              188|             123|           2|
|                  20000|              755|             479|           4|
+-----------------------+-----------------+----------------+------------+

+-----------------------+-----------------+----------------+------------+
|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
+-----------------------+-----------------+----------------+------------+
|                   5000|               50|              33|           1|
|                  10000|              184|             127|           2|
|                  20000|              792|             493|           4|
+-----------------------+-----------------+----------------+------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int n, int * arr, int l, int r);
int HoarePartition(int * arr, int l, int r);
void selection_sort(int n, int * arr);
void insertion_sort(int n, int * a);

void printArray(int n, int * a);
void swap(int * arr, int i, int j);

int main (int argc, char *argv[])
{
   // Initalize
   if (argc < 2)
   {
      printf("%s size(int)", argv[0]);
      exit(1);
   }
   srand (time(NULL));
   // ------------------------------------------
   //int args = argc-1;
   int small = atoi(argv[1]);
   int arrSmall[small];
   int arrSmall2[small];
   int arrSmall3[small];
   for (int i = 0; i < small; i++)
   {
      arrSmall[i] = rand() % 100;
   }
   memcpy(arrSmall2, arrSmall, small * sizeof(int));
   memcpy(arrSmall3, arrSmall, small * sizeof(int));
   // ------------------------------------------
   int medium = 10000;
   int arrMed[medium];
   int arrMed2[medium];
   int arrMed3[medium];
   for (int i = 0; i < medium; i++)
   {
      arrMed[i] = rand() % 100;
   }
   memcpy(arrMed2, arrMed, medium * sizeof(int));
   memcpy(arrMed3, arrMed, medium * sizeof(int));
   // ------------------------------------------
   int large = 20000;
   int arrLarge[large];
   int arrLarge2[large];
   int arrLarge3[large];
   for (int i = 0; i < large; i++)
   {
      arrLarge[i] = rand() % 100;
   }
   memcpy(arrLarge2, arrLarge, large * sizeof(int));
   memcpy(arrLarge3, arrLarge, large * sizeof(int));

   // SELECTION SORT
   // ------------------------------------------
   struct timeval start, stop;
   gettimeofday(&start, NULL);
      selection_sort(small, arrSmall);
   gettimeofday(&stop, NULL);
   double selection1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      selection_sort(medium, arrMed);
   gettimeofday(&stop, NULL);
   double selection2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      selection_sort(large, arrLarge);
   gettimeofday(&stop, NULL);
   double selection3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   // ------------------------------------------
   // INSERTION SORT
   // ------------------------------------------
   gettimeofday(&start, NULL);
      insertion_sort(small, arrSmall2);
   gettimeofday(&stop, NULL);
   double insertion1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      insertion_sort(medium, arrMed2);
   gettimeofday(&stop, NULL);
   double insertion2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      insertion_sort(large, arrLarge2);
      //printArray(large, arrLarge2);
   gettimeofday(&stop, NULL);
   double insertion3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   // ------------------------------------------
   // QUICK SORT
   // ------------------------------------------
   gettimeofday(&start, NULL);
      quick_sort(small, arrSmall3, 0, small-1);
   gettimeofday(&stop, NULL);
   double quick1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      quick_sort(medium, arrMed3, 0, medium-1);
   gettimeofday(&stop, NULL);
   double quick2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);
      quick_sort(large, arrLarge3, 0, large-1);
   gettimeofday(&stop, NULL);
   double quick3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   // ------------------------------------------

   // AI GENERATED FORMATTING
   // Print the table header and separators
   printf("+-----------------------+-----------------+----------------+------------+\n");
   printf("|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |\n");
   printf("+-----------------------+-----------------+----------------+------------+\n");
   
   // Print data rows with right-aligned numbers
   // printf("|%23d|%17f|%16f|%12f|\n", small, selection1Time, insertion1Time, quick1Time);
   // printf("|%23d|%17f|%16f|%12f|\n", medium, selection2Time, insertion2Time, quick2Time);
   // printf("|%23d|%17f|%16f|%12f|\n", large, selection3Time, insertion3Time, quick3Time);
   printf("|%23d|%17.0f|%16.0f|%12.0f|\n", small, selection1Time, insertion1Time, quick1Time);
   printf("|%23d|%17.0f|%16.0f|%12.0f|\n", medium, selection2Time, insertion2Time, quick2Time);
   printf("|%23d|%17.0f|%16.0f|%12.0f|\n", large, selection3Time, insertion3Time, quick3Time);
   
   // Print the closing separator
   printf("+-----------------------+-----------------+----------------+------------+\n");
}

void printArray(int n, int * arr)
{
   //static int pivot = 0;
   for (int i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
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
      //printArray(n, arr, l, r);
   }
}

int HoarePartition(int * arr, int l, int r)
{
   int p = arr[l];
   int i = l;
   int j = r + 1;

   while (i < j){
      do {
         i++;
      } while (i<= r && arr[i] < p);
      do {
         j--;
      } while (j >= l && arr[j] > p);
      if (i >= j) break;
      
      swap(arr, i, j);
   }
   swap(arr, l, j);
   return j;
}

void insertion_sort(int n, int * arr)
{
   //printArray(n, a);
   for (int i = 0; i < n; i++)
   {
      int v = arr[i];
      int j = i-1;
      while (j >= 0 && arr[j]>v)
      {
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = v;
      //printArray(n, a);
   }
}

void selection_sort(int n, int * arr)
{
   //printArray(n, arr);
   int min = 0;
   for (int i = 0; i <= n-2; i++)
   {
      min = i;
      for (int j = i+1; j <= n-1; j++)
      {
         if (arr[j] < arr[min])
            min = j;
      }
      // swap
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
      //printArray(n, arr);
   }
}