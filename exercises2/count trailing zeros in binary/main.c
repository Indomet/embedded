/******************************************************************************

Write a C program to input any number from user and count number of trailing zeros in the given
number using bitwise operator.
Example
Input
Input any number: 22
Output
Trailing zeros: 1
*******************************************************************************/
#include <stdio.h>
void trailingZerosCounter(int num, int *counter);
int main()
{   
    int num;
    scanf("%d", &num);
    int counter;
    trailingZerosCounter(num,&counter);
    printf("%d", counter);
    return 0;
}

void trailingZerosCounter(int num, int *counter){
    for(int i = 0; i<=31; i++){
        if((num>>i&1)== 0){
            (*counter)++;
        }else{
            break;
        }
    
    }
}
