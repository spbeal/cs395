/*********************************************
* Id: beal6782
* 
* Boyer-Moore algorithm
* 
* Implement an algorithm for Boyer-Moore
* Use w14 for ShiftTable
*********************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

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

// Horspools
int * ShiftTable(const char * needle, int m){
   int * Table = malloc(MAX_ALPHABET * sizeof(int));
   for (int i = 0; i < MAX_ALPHABET; i++) Table[i] = m;
   for (int j = 0; j < m-1; j++) Table[(unsigned char)needle[j]] = m - 1 - j;
   printShiftTable(Table);
   return Table;
}

////////////////////////////////
////////////////////////////////

bool equal(const char *pattern, int start1, int start2, int len) {
   for (int i = 0; i < len; i++) {
      if (pattern[start1 + i] != pattern[start2 + i]) return false;
   }
   return true;
}

int *GoodSuffixTable(const char *needle, int *gsuffix, int m) {
   for (int k = 1; k < m; k++) {
      bool found = false;
      for (int j = m - k - 1; j >= 0; j--) {
         if (equal(needle, j, m - k, k) && 
               (j == 0 || needle[j - 1] != needle[m - k - 1])) {
               gsuffix[k] = m - k - j;
               found = true;
               break;
         }
      }
      if (!found) {
         for (int l = k; l >= 1; l--) {
               if (equal(needle, 0, m - l, l)) {
                  gsuffix[k] = m - l;
                  break;
               }
               if (l == 1) gsuffix[k] = m;
         }
      }
   }
   for (int i = 1; i < m; i++) {
      printf("%d %*s %d\n", i, m, &needle[m - i], gsuffix[i]);
   }
   return gsuffix;
}

////////////////////////////////
////////////////////////////////

void boyer_moore_search(const char *haystack, const char *needle) {
   int n = strlen(haystack); int m = strlen(needle); if (m == 0) return;

   int * bad_symbol = ShiftTable(needle, m);
   int gsuffix[m]; GoodSuffixTable(needle, gsuffix, m);
   int matchNum = 0;
   int * matches = (int * )malloc(n*sizeof(int));

   printf("%s\n", haystack); // print out string

   /////////////////////
   // Engine
   int s = 0;
   while (s <= n - m) {
      int j = m - 1;
      while (j >= 0 && needle[j] == haystack[s + j]) j--;

      printf("%*s%s", s, "", needle);
      if (j < 0) {
         printf("---found");
         matches[matchNum++] = s;
         s += 1;
      } else {
         int k = m - 1 - j;
         char c = haystack[s + j];

         int d1 = bad_symbol[(unsigned char)c] - k; if (d1 < 1) d1 = 1;         
         int d2 = (k > 0) ? gsuffix[k] : 0;
         int d = (k == 0) ? d1 : (d1 > d2 ? d1 : d2);
         // d1, d2
         if (k > 0 && k < m)
            printf(" d1=%d d2=%d", d1, d2);
         s += d;
      }
      printf("\n");
   }
   /////////////////////

   printf("Matches found at locations:");
   for(int i = 0; i < matchNum; i++)
   {
      printf(" %d", matches[i]);
   }
   printf("\n");
}

////////////////////////////////
////////////////////////////////

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <pattern> <text>\n", argv[0]);
      return 1;
   }
   // Haystack, needle
   boyer_moore_search(argv[2], argv[1]);
   return 0;
}

/*
Boyer-Moore algorithm

The Boyer-Moore algorithm
Step 1 For a given pattern and the alphabet used in both the pattern and the
text, construct the bad-symbol shift table as described earlier.

   //Use the table creator function you creted for Horspool’s 

Step 2 Using the pattern, construct the good-suffix shift table as described
earlier.
int *GoodSuffixTable(char *needle, int *gsuffix)
{
   // Your code here
   for(i=1; i<m; i++)
   {
      printf("%d %*s %d\n", i, m, &needle[m-i], gsuffix[i]);
   }
   return gsuffix;
}

Step 3 Align the pattern against the beginning of the text.

Step 4 Repeat the following step until either a matching substring is found or
the pattern reaches beyond the last character of the text. Starting with
the last character in the pattern, compare the corresponding characters
in the pattern and the text until either allmcharacter pairs are matched
(then stop) or a mismatching pair is encountered after k ≥ 0 character
pairs are matched successfully. In the latter case, retrieve the entry
t1(c) from the c’s column of the bad-symbol table where c is the text’s
mismatched character. If k > 0, also retrieve the corresponding d2
entry from the good-suffix table. Shift the pattern to the right by the number of positions computed by the formula
   if k = 0
      d = d1 
   if m > k > 0
      d = max{d1, d2} 
   if k==m 
      match found!
      d=1

where d1 = max{t1(c) − k, 1}.
Shifting by the maximum of the two available shifts when k > 0 is quite logical.
The two shifts are based on the observations—the first one about a text’s
mismatched character, and the second one about a matched group of the pattern’s
rightmost characters—that imply that shifting by less than d1 and d2 characters, respectively,
cannot lead to aligning the pattern with a matching substring in the text.
Since we are interested in shifting the pattern as far as possible without missing a
possible matching substring, we take the maximum of these two numbers.

Your output should look like this:
./boyer   baobab bess_knew_about_baobabs
        !       "       #       $       %       &       '       (       )       *       +       ,       -       .       /
6       6       6       6       6       6       6       6       6       6       6       6       6       6       6       6

0       1       2       3       4       5       6       7       8       9       :       ;       <       =       >       ?
6       6       6       6       6       6       6       6       6       6       6       6       6       6       6       6

@       A       B       C       D       E       F       G       H       I       J       K       L       M       N       O
6       6       6       6       6       6       6       6       6       6       6       6       6       6       6       6

P       Q       R       S       T       U       V       W       X       Y       Z       [       \       ]       ^       _
6       6       6       6       6       6       6       6       6       6       6       6       6       6       6       6

`       a       b       c       d       e       f       g       h       i       j       k       l       m       n       o
6       1       2       6       6       6       6       6       6       6       6       6       6       6       6       3

p       q       r       s       t       u       v       w       x       y       z       {       |       }       ~
6       6       6       6       6       6       6       6       6       6       6       6       6       6       6       6

1      b 2
2     ab 5
3    bab 5
4   obab 5
5  aobab 5
bess_knew_about_baobabs
baobab
      baobab d1=4 d2=5
           baobab d1=5 d2=2
                baobab---found
                 baobab
Matches found at locations: 16
*/