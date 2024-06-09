/******************************************************************************

The program below contains two mistakes. Please find them, explain them and correct them.
#include<stdio.h> //Used to include basic c library files
void main()//main() method for executing the application
{
//declaring and defining the variables
int a=100;
int b=200;
//displaying the output
printf("Sum of %d and %d is=%d\n",a,b,sum(a,b));//sum(a,b) is calling
method
}
//called method
int sum(int a, int b)
{
return a*b; // making the calculation
}

*******************************************************************************/
#include<stdio.h>				//Used to include basic c library files
int sum (int a, int b);
void main ()							//main() method for executing the application
{
//declaring and defining the variables
  int a = 100;
  int b = 200;
//displaying the output
  printf ("Sum of %d and %d is=%d\n", a, b, sum (a, b));	//sum(a,b) is callingmethod
  }

//called method
int sum (int a, int b)
{
  return a + b;					// making the calculation
}

//mistake one: it should be + instead of *
//mistake 2: the usm method should be declared before the main so that the program knows there is method after main
