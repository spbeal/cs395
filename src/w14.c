
/*********************************************
 * Id: beal6782
 * 
 * Horspool's Algorithm
 * 
 * String matching
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_match(char * p, char * str);

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
//Print out the shift table starting at the first writable character (space)
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH && i < MAX_ALPHABET; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH && i < MAX_ALPHABET; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");

   }
}

int * ShiftTable(char * needle, int m){

   //int * Table = new int[MAX_ALPHABET];
   int * Table = malloc(MAX_ALPHABET * sizeof(int));
   for (int i = 0; i < MAX_ALPHABET; i++) 
      Table[i] = m;
   for (int j = 0; j < m-1; j++) 
      Table[(unsigned char)needle[j]] = m - 1 - j;
      //Table[(unsigned char)needle[j]] = m - 1 - j;
   printShiftTable(Table);
   return Table;
}

void HorspoolMatching(char * needle, char * haystack, int m, int n)
{
   int * Table = ShiftTable(needle, m); //generate Table of shifts
   printf("%s\n", haystack);

   int matchNum = 0;
   int * matches = (int * )malloc(n*sizeof(int));
   int i = m-1;
   while (i<n)
   {
      int k = 0;
      while (k < m && needle[m-1-k] == haystack[i-k])
      {
         k++;
      }
      if (k == m)
      {
         int match = i - m + 1;
         //int match = k;
         printf("%*s%s---found\n", i-m+1,"", needle);
         matches[matchNum++] = match;
         //return i - m + 1; // Except for your code, do not return. Start looking for the next occurance from here.
      }
      else
      {
         printf("%*s%s\n", i-m+1, "", needle); 
      }
      i = i + Table[(unsigned char)haystack[i]];
      //i += Table[(unsigned char)haystack[i]];
   }

   printf("Matches found at locations:");
   for(i = 0; i < matchNum; i++)
   {
      printf(" %d", matches[i]);
   }
   printf("\n");
   free(Table);
   free(matches);
   //return matchNum;
   //return -1;
}


int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s abc abcabcabcabcbcabcbabc\n", argv[0]);
      exit(1);
   }
   
   char * pattern = argv[1];
   char * string = argv[2];
   int m = strlen(pattern);
   int n = strlen(string);
   //printf("Argc: %d Pattern: %s String: %s\n", argc, pattern, string);

   HorspoolMatching(pattern, string, m, n);
}

/*
Horspool’s algorithm

//Fills the shift table used by Horspool’s and Boyer-Moore algorithms
//Input: Pattern P[0..m − 1] and an alphabet of possible characters
//       For your assignment the set of characters are the ASCII characters 0-127
//Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
ShiftTable(needle [0..m − 1])
   for i ←0 to size − 1 do Table[i]←m
   for j ←0 to m − 2 do Table[needle[j ]]←m − 1− j
   printShiftTable
   return Table

//Implements Horspool’s algorithm for string matching
//Input: Pattern needle[0..m − 1] and text haystack[0..n − 1]
//Output: The index of the left end of the first matching substring
// or −1 if there are no matches
HorspoolMatching(needle[0..m − 1], haystack[0..n − 1])
   ShiftTable(needle[0..m − 1]) //generate Table of shifts
   printf("%s\n", haystack);
   i ←m − 1 //position of the pattern’s right end
   while i ≤ n − 1 do
      k←0 //number of matched characters
      while k ≤ m − 1 and needle[m − 1− k]= haystack[i − k] do
         k←k + 1
      if k = m
         printf("%*s%s---found\n", i-m+1,"", needle);
         return i − m + 1 // Except for your code, do not return. Start looking for the next occurance from here.
      else
         printf("%*s%s\n", i-m+1, "", needle); 
      i ←i + Table[haystack[i]]

   printf("Matches found at locations:");
   for(i = 0; i < matchNum; i++)
   {
      printf(" %d", matches[i]);
   }
   printf("\n");
   return −1


#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32
//Print out the shift table starting at the first writable character (space)
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");

   }
}



Your output should look like this:
./horspool abc abaabcbabcbabcbabbbabcbaabbcbabcabc
        !       "       #       $       %       &       '       (       )       *       +       ,       -       .       /
3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3

0       1       2       3       4       5       6       7       8       9       :       ;       <       =       >       ?
3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3

@       A       B       C       D       E       F       G       H       I       J       K       L       M       N       O
3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3

P       Q       R       S       T       U       V       W       X       Y       Z       [       \       ]       ^       _
3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3

`       a       b       c       d       e       f       g       h       i       j       k       l       m       n       o
3       2       1       3       3       3       3       3       3       3       3       3       3       3       3       3

p       q       r       s       t       u       v       w       x       y       z       {       |       }       ~
3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3

abaabcbabcbabcbabbbabcbaabbcbabcabc
abc
  abc
   abc---found
      abc
       abc---found
          abc
           abc---found
              abc
               abc
                abc
                 abc
                   abc---found
                      abc
                        abc
                         abc
                            abc
                             abc---found
                                abc---found
Matches found at locations: 3 7 11 19 29 32
*/