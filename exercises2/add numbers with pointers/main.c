/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void add(int *input1,int *input2, int *result);

int main()
{   
    int input1;
    int input2;
    int result;
    printf("first number");
    scanf("%d", &input1);
    printf("second number");
    scanf("%d", &input2);
    
    add(&input1, &input2, &result);
    
    printf("%d",result);
    return 0;
}

void add(int *input1,int *input2, int *result){
    *result = *input1 + *input2;
    
}
