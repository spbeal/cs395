/*********************************************
 * Id: beal6782
 * 
 * Brute Force String Matching.
 * 
 * Keep track of indices, modified sliding window technique
 * One index goes up to how long the pattern is ahead
 *********************************************/ 

#include <stdio.h>
#include <stdlib.h>

void string_match(char * p, char * str);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s abc abcabcabcabcbcabcbabc\n", argv[0]);
      exit(1);
   }

   char * pattern = argv[1];
   char * string = argv[2];
   //printf("Argc: %d Pattern: %s String: %s\n", argc, pattern, string);

   string_match(pattern, string);
}

void string_match(char * p, char * str)
{
   printf("Matches found at locations:");
   int len_p = 0;
   int len_str = 0;
   for (int i = 0; p[i] != '\0'; i++) len_p++;
   for (int i = 0; str[i] != '\0'; i++) len_str++;

   // actual algorithm
   int j = 0;
   for (int i = 0; i <= len_str-len_p; i++)
   {
      j = 0;
      while (str[i+j] == p[j] && j < len_p)
      {
         j++;
      }
      if (j == len_p) printf(" %d", i);
   }
   printf("\n");
   //return - 1;
}

/*
//Input: An array T [0..n − 1] of n characters representing a text and
// an array P[0..m − 1] of m characters representing a pattern
//Output: The index of the first character in the text that starts a
// matching substring or −1 if the search is unsuccessful
BruteForceStringMatch(T [0..n − 1], P[0..m − 1])
   for i ←0 to n − m do
      j ←0
      while j <mand P[j ]= T [i + j ] do
         j ←j + 1
      if j = m return i
   return −1

Your output should look like this:
./search abc abaabcbabcbabcbabbbabcbaabbcbabcabc
Matches found at locations: 3 7 11 19 29 32
*/
