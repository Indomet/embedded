/******************************************************************************
Write a C program to input any number from user and find highest order set bit of given number
using bitwise operator.
Example
Input
Input any number: 22
Output
Highest order set bit in 22 is 4

*******************************************************************************/
#include <stdio.h>
void findHighestBit(int num);
int main()
{
 findHighestBit(22);

    return 0;
}

void findHighestBit(int num){
    int a;
    for( int i = 31 ; i >=0 ; i--){
        if(num>>i&1==1){
            a = i;
            break;
        }
    }
    printf("%d", a);
    
}