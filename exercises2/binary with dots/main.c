/******************************************************************************

Write a function
uint16_t make_16bit(uint8_t least_significant, uint8_t
most_significant);
that combines the given bytes into a 16-bit integer and returns it as the result.
Note: In practice, the first argument contains 8 least significant bits of an unsigned 16-bit integer and
the second contains the 8 most significant bits.
Example:
print_bin(1) => 00000000.00000000.00000000.00000001
print_bin(7) => 00000000.00000000.00000000.00000111
print_bin(make_16bit(7, 1)) => 00000000.00000000.00000001.00000111
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

void print_bin (unsigned int num);
uint16_t make_16bit (uint8_t least_significant, uint8_t most_significant);
int
main ()
{
  print_bin (0);
  print_bin (1);
  print_bin (2);
  print_bin (43);
  print_bin (123456789);
  print_bin (make_16bit (7, 1));
  return 0;
}

void
print_bin (unsigned int num)
{
  for (int i = 31; i >= 0; i--)
	{
	  printf ("%d", (num >> i) & 1);
	  if (i % 8 == 0 && i > 0)
		{
		  printf (".");
		}
	}
  printf ("\n");
}

uint16_t
make_16bit (uint8_t least_significant, uint8_t most_significant)
{
    //shifting 8 makes it more significant
    //bitwise OR operation between the result of the left shift operation 
    //(which contains the most significant bits) and the least_significant byte, combining both bytes into a single 16-bit integer.
  return ((uint16_t) most_significant << 8) | least_significant;
}


