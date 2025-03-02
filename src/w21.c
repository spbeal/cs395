/*********************************************
 * Id: beal6782
 * 
 * Permutations
 * 
 * Implement to find all permutations up to n
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
// #include <bits/stdc++.h>


void swap(int * arr, int i, int j)
{
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

// heap algorithm, O(n*n!)
void permutations(int * a, int size, int n)
{
    /*
    123
    each iteration produces all permutation that end with current last element. 
    */
    if (size == 1) 
    {
        printArr(a, n);
        return;
    }

    // this loop runs n times and then n-1 times n times each time. 
    for (int i = 0; i < size; i++)
    {
        permutations(a, size-1, n);
        if (size % 2 == 1) swap(a, 0, size-1); // odd swap start
        else swap(a, i, size-1); //even swap curr index
    }
}


int main (int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("%s n", argv[0]);
      exit(1);
   }

   const int n = atoi(argv[1]);
   int * a;
   a = (int *)malloc(n*sizeof(int));

   for (int i = 0; i < n; i++)
   {
        a[i] = i+1;
   }
   //printf("end of a: %d \n", a[n-1]);
   permutations(a, n, n);
}

/*
Permutations.

Write a program that takes a single integer as input (n) and returns all 
permutations of the characters from 1 to n each on its own line. 

For example:
./permutations 3
123
132
213
231
312
321

The order of your output is up to to you, but you must print all n! permutations
without repeting any.

*/