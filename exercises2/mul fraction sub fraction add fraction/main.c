#include <stdio.h>

int simplifier (char *name, int lower, int upper);
int
addFraction (int a, int c, int b, int d)
{
  char name[25] = "addFraction";
  int upper = ((a * d) + (b * c));
  int lower = (b * d);
  simplifier (name, lower, upper);
  // printf("%d/%d\n",upper, lower );
  return 1;
}

int
subFraction (int a, int c, int b, int d)
{
  char name[25] = "subFraction";
  int upper = ((a * d) - (b * c));
  int lower = (b * d);
  simplifier (name, lower, upper);
  // printf("%d/%d\n",upper, lower );
}

int
mulFraction (int a, int c, int b, int d)
{
  char name[25] = "mulFraction";
  int upper = (a * c);
  int lower = (b * d);
  simplifier (name, lower, upper);

  // printf("%d/%d\n",upper, lower );
}

int
simplifier (char name[25], int lower, int upper)
{
  int gcd;
  for (int i=1; i <= lower; i++)
    {
      if (lower % i == 0 && upper % i == 0)
        {
          gcd = i;
        }

    }
  lower /= gcd;
  upper /= gcd;
  printf ("%s: %d/%d\n", name, upper, lower);
}

int
main ()
{
  subFraction (1, 3, 3, 5);
  subFraction (3, 1, 5, 3);
  subFraction (3, 2, 4, 3);
  subFraction (6, 4, 5, 10);
  subFraction (2, 5, 3, 7);
  return 0;
}