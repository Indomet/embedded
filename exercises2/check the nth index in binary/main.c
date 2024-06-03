/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Write a C program to input any number from user and check whether nth bit of the given number is
// set (1) or not (0).
// Example
// Input
// Input number: 12
// Input nth bit number: 2
// Output
// 2 bit of 12 is set (1)


#include <stdio.h>
void checkIfBitSet(int num, int index);
int main()
{   
    int num;
    int index;
    scanf("%d",&num);
    scanf("%d", &index);
    checkIfBitSet(num, index);
    return 0;
}

void checkIfBitSet(int num, int index){
    for(int i =0; i <=31; i++){
        // printf("%d", (num>>i)&1);
        
        if(i== index ){
            printf("%d bit of %d is (%d)",index, num,(num>>i)&1 );
            break;
        }
    }
}

