/*********************************************
 * Id: beal6782
 * 
 * Russian Peasant Multiplication
 * 
 * Implement an algorithm for russian peasant multiplcation
 * n/2 * 2m for even
 * n-1/2 * 2m + m for odd
 *********************************************/ 
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void multiply(int n, int m);
void printMul(int n, int m);

int main (int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("%s 1 2 3 4 5 6 7 8", argv[0]);
      exit(1);
   }

   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   multiply(x,y);
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