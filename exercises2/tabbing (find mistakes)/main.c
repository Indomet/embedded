/******************************************************************************

The following program has two mistakes in it, please find them, explain why these are mistakes
and correct them:
#include <stdio.h>
#define MAX_SIZE 5 //Maximum size of the array
int main()
{
int arr[MAX_SIZE]; //Declares an array size
int i, num;
//Enter size of array
printf("Enter size of the array: ");
scanf("%d", &num);
//Reading elements of array
printf("Enter elements in array: ");
for(i=0; i<num; i++)
{
scanf("%d", &arr[i]);
}
printf("\nAll negative elements in array are: ");
for(i=0; i<num; ++i)
{
//Printing negative elements
if(arr[i] < 0)
{
printf("%d\t", arr[i]);
}
}
return 0;
}
Tips! Execute the program and test it

*******************************************************************************/
#include <stdio.h>
// #define MAX_SIZE 5				//Maximum size of the array
int
main ()
{
    int i, num;
 

//Enter size of array
  printf ("Enter size of the array: ");
  scanf ("%d", &num);
   int arr[num];			//Declares an array size
//Reading elements of array
  printf ("Enter elements in array: ");
  for (i = 0; i < num; i++)
	{
	  scanf ("%d", &arr[i]);
	}
  printf ("\nAll negative elements in array are: ");
  for (i = 0; i < num; ++i)
	{
//Printing negative elements
	  if (arr[i] < 0)
		{
		  printf ("%d\t", arr[i]);
		}
	}
  return 0;
}

// first mistake is  int arr[MAX_SIZE];	it is already  5 from the beginning no matter what user writes
//second mistake is the array should be declared after the number is given by the user not before
