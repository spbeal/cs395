/*********************************************
 * Id: beal6782
 * 
 * MinDistance program for finding distance between elements in an array.
 * More efficient than w01
 *********************************************/ 

// VERSION 2
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Fib(int n);

int main (int argc, char *argv[])
{
   if (argc < 1)
   {
      printf("%s 1 2 3 4", argv[0]);
      exit(1);
   }

   int n = atoi(argv[1]);


   int dmin = Fib(n);
   printf("%d\n", dmin);
}

// Function to find min distance, n^2 big(O)
int Fib(int n)
{
   if (n == 0) return 0;
   if (n == 1) return 1;


   return MinDistance(n-1) + MinDistance(n-2);
}


// VERSION 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int MinDistance(int values[], int dmin);

// int main (int argc, char *argv[])
// {
//    if (argc < 2)
//    {
//       printf("%s 1 2 3 4", argv[0]);
//       exit(1);
//    }

//    int n = argc-1;
//    int values[n];

//    for (int i = 0; i < n; i++) {
//       values[i] = atoi(argv[i+1]);
//    }

//    int dmin = MinDistance(values, n);
//    printf("%d\n", dmin);
// }

// // Function to find min distance, n^2 big(O)
// int MinDistance(int values[], int len)
// {
//    int dmin = abs(values[0] - values[len-1]);
//    for (int i = 0; i<len-1; i++)
//    {
//       for (int j = i+1; j<len; j++)
//       {
//          if (abs(values[i]-values[j]) < dmin)
//          {
//             dmin = abs(values[i]-values[j]);
//          }
//       }
//    }
//    return dmin;
// }
