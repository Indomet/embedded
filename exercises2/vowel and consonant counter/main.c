/******************************************************************************
Write a program in C to count the number of vowels and consonants in a string using a pointer.
Test Data :
Input a string: string
Expected Output :
Number of vowels : 1
Number of consonants : 5
*******************************************************************************/
#include <stdio.h>
#include <ctype.h> // tolower
#include <string.h> //strlen
void vovelChecker (char *input, int *vovel);
int
main ()
{
  char input[1000];
  int vovel;
  // scanf("%s", &input);
  fgets (input, sizeof (input), stdin);
  vovelChecker (input, &vovel);
  printf ("%d\n", vovel);
  
  int consonants =strlen(input)- 1 -vovel;
  printf("%d", consonants);
  return 0;
}

void
vovelChecker (char *input, int *vovel)
{
  *vovel = 0;
  while (*input != '\0')
	{
	  char str = tolower (*input);
	  if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u')
		{
		  (*vovel)++;
		}
	  *input++;
	}

}

