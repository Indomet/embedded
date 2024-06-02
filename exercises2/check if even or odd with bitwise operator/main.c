/******************************************************************************

Write a C program to input any number and check whether the given number is even or odd using
bitwise operator.
Example
Input
Input number: 12
Output
12 is even

*******************************************************************************/
#include <stdio.h>
int checkIfEvenOrOdd(int num);
int main()
{
    checkIfEvenOrOdd(12);

    return 0;
}

void checkIfEvenOrOdd(int num){
    // num=1;
    // for(int i = 0; i<=31; i++){
        if(num>>0&1==1){
            printf("odd");
        }else{
            printf("even");
        }
    // }
    
}